//Jimmy Lauchoy
//CS1124 Summer
//HW03

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Organism;
class Doodlebug;
class Ant;

class Map {
	friend class Organism;
	friend class Ant;
	friend class Doodlebug;
private:
	Organism* mapGrid[20][20]; //multidimensional array
public:
	Map() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				mapGrid[i][j] = nullptr;
			}
		}
	}
	Organism* getOrganism(int x, int y) {
		if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) {
			return mapGrid[x][y];
		}
		return nullptr;
	}
	void setOrganism(int x, int y, Organism* aOrganism) {
		if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) {
			mapGrid[x][y] = aOrganism;
		}
	}
	void Map::showMap();
	void Map::runSim();
};

class Organism { //abstract class
	friend class Map;
protected:
	int x;
	int y;
	bool hasMoved;
	int hitpoints;
	Map* map;
public:
	Organism() : x(0), y(0), map(nullptr), hasMoved(false), hitpoints(0) {}
	Organism(Map* newMap, int xNew, int yNew);
	virtual void move() = 0;
	virtual void breed() = 0;
	virtual bool starve() = 0;
	virtual int getSpecies() = 0;
};

Organism::Organism(Map* newMap, int xNew, int yNew) {
	this->x = xNew;
	this->y = yNew;
	this->map = newMap;
	newMap->setOrganism(x, y, this);
	hasMoved = false;
	hitpoints = 0;
}

class Ant : public Organism {
	friend class Map;
public:
	Ant() : Organism() {}
	Ant(Map* newMap, int x, int y) : Organism(newMap, x, y) {}
	bool starve() {
		return false; //ants cant starve
	}
	int getSpecies() {
		return 3; //3 for the num of letters for 'ant'
	}
	void move() {
		int moveSpaces = rand() % 4;
		if (moveSpaces == 0) {
			if ((y > 0) && (map->getOrganism(x, y - 1) == nullptr)) {
				map->setOrganism(x, y - 1, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				y--;
			}
		}
		else if (moveSpaces == 1) {
			if ((y < 19) && (map->getOrganism(x, y + 1) == nullptr)) {
				map->setOrganism(x, y + 1, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				y++;
			}
		}
		else if (moveSpaces == 2) {
			if ((x > 0) && (map->getOrganism(x - 1, y) == nullptr)) {
				map->setOrganism(x - 1, y, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				x--;
			}
		}
		else {
			if ((x < 19) && (map->getOrganism(x + 1, y) == nullptr)) {
				map->setOrganism(x + 1, y, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				x++;
			}
		}
	}
	void breed() {
		hitpoints++;
		if (hitpoints == 3) {
			hitpoints = 0;
		}
		if ((y > 0) && (map->getOrganism(x, y - 1) == nullptr)) {
			Ant* newAnt = new Ant(map, x, y - 1);
		}
		else if ((y < 19) && (map->getOrganism(x, y + 1) == nullptr)) {
			Ant* newAnt = new Ant(map, x, y + 1);
		}
		else if ((x > 0) && (map->getOrganism(x - 1, y) == nullptr)) {
			Ant* newAnt = new Ant(map, x - 1, y);
		}
		else if ((x < 19) && (map->getOrganism(x + 1, y) == nullptr)) {
			Ant* newAnt = new Ant(map, x + 1, y);
		}
	}
};

class Doodlebug : public Organism {
	friend class Map;
private:
	int movesRem; //num of moves remaining till it starves
public:
	Doodlebug() : Organism(), movesRem(0) {}
	Doodlebug(Map* newMap, int xNew, int yNew) :Organism(newMap, xNew, yNew), movesRem(0) {}
	void move() {
		//sees if it can eat any ant around it
		if ((y > 0) && (map->getOrganism(x, y - 1) != nullptr) && (map->getOrganism(x, y - 1)->getSpecies() == 3)) {
			delete (map->mapGrid[x][y - 1]);
			map->mapGrid[x][y - 1] = this;
			map->setOrganism(x, y, nullptr);
			movesRem = 0;
			y--;
		}
		else if ((y < 19) && (map->getOrganism(x, y + 1) != nullptr) && (map->getOrganism(x, y + 1)->getSpecies() == 3)) {
			delete (map->mapGrid[x][y + 1]);
			map->mapGrid[x][y + 1] = this;
			map->setOrganism(x, y, nullptr);
			movesRem = 0;
			y++;
		}
		else if ((x > 0) && (map->getOrganism(x - 1, y) != nullptr) && (map->getOrganism(x - 1, y)->getSpecies() == 3)) {
			delete (map->mapGrid[x - 1][y]);
			map->mapGrid[x - 1][y] = this;
			map->setOrganism(x, y, nullptr);
			movesRem = 0;
			x--;
		}
		else if ((x < 19) && (map->getOrganism(x + 1, y) != nullptr) && (map->getOrganism(x + 1, y)->getSpecies() == 3)) {
			delete (map->mapGrid[x + 1][y]);
			map->mapGrid[x + 1][y] = this;
			map->setOrganism(x, y, nullptr);
			movesRem = 0;
			x++;
		}
		//same as ants move function
		int moveSpaces = rand() % 4;
		if (moveSpaces == 0) {
			if ((y > 0) && (map->getOrganism(x, y - 1) == nullptr)) {
				map->setOrganism(x, y - 1, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				y--;
			}
		}
		else if (moveSpaces == 1) {
			if ((y < 19) && (map->getOrganism(x, y + 1) == nullptr)) {
				map->setOrganism(x, y + 1, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				y++;
			}
		}
		else if (moveSpaces == 2) {
			if ((x > 0) && (map->getOrganism(x - 1, y) == nullptr)) {
				map->setOrganism(x - 1, y, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				x--;
			}
		}
		else {
			if ((x < 19) && (map->getOrganism(x + 1, y) == nullptr)) {
				map->setOrganism(x + 1, y, map->getOrganism(x, y));
				map->setOrganism(x, y, nullptr);
				x++;
			}
		}
		movesRem++;
	}
	bool starve() {
		if (movesRem > 3) {
			return true;
		}
		else {
			return false;
		}
	}
	int getSpecies() {
		return 9; //9 for numbers of letters in doodlebug
	}
	void breed() {
		hitpoints++;
		if (hitpoints > 8) {
			hitpoints = 0;
			//code similar to ant breed function
			if ((y > 0) && (map->getOrganism(x, y - 1) == nullptr)) {
				Doodlebug* newDoodle = new Doodlebug(map, x, y - 1);
			}
			else if ((y < 19) && (map->getOrganism(x, y + 1) == nullptr)) {
				Doodlebug* newDoodle = new Doodlebug(map, x, y + 1);
			}
			else if ((x > 0) && (map->getOrganism(x - 1, y) == nullptr)) {
				Doodlebug* newDoodle = new Doodlebug(map, x - 1, y);
			}
			else if ((x < 19) && (map->getOrganism(x + 1, y) == nullptr)) {
				Doodlebug* newDoodle = new Doodlebug(map, x + 1, y);
			}
		}
	}
};

void Map::showMap() {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (mapGrid[i][j] == nullptr) {
				cout << "-" << " "; 
			}
			else if (mapGrid[i][j]->getSpecies() == 9) {
				cout << "X" << " ";
			}
			else {
				cout << "o" << " "; 
			}
		}
		cout << "\n"; 
	}
}
void Map::runSim() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (mapGrid[i][j] != nullptr) {
				mapGrid[i][j]->hasMoved = false;
			}
		}
	}
	for (int i = 0; i < 400; i++) { 
		int xRand = rand() % 20;
		int yRand = rand() % 20;
		if ((mapGrid[xRand][yRand] != nullptr) && (mapGrid[xRand][yRand]->getSpecies() == 9)) { //check to see if its a doodlebug
			if (mapGrid[xRand][yRand]->hasMoved == false) {
				mapGrid[xRand][yRand]->hasMoved = true;
				mapGrid[xRand][yRand]->move();
			}
		}
		if ((mapGrid[xRand][yRand] != nullptr) && (mapGrid[xRand][yRand]->getSpecies() == 3)) { //check to see if its an ant
			if (mapGrid[xRand][yRand]->hasMoved == false) {
				mapGrid[xRand][yRand]->hasMoved = true;
				mapGrid[xRand][yRand]->move();
			}
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if ((mapGrid[i][j] != nullptr) && (mapGrid[i][j]->getSpecies() == 9)) {
					if (mapGrid[i][j]->starve() == true) {
						delete (mapGrid[i][j]);
						mapGrid[i][j] = nullptr;
					}
				}
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if ((mapGrid[i][j] != nullptr) && (mapGrid[i][j]->hasMoved == true)) {
				mapGrid[i][j]->breed();
			}
		}
	}
}

	int main() {
		Map simMap;
		int numAnts = 0;
		int numDoodle = 0;
		while (numAnts < 100) {
			int x = rand() % 20;
			int y = rand() % 20;
			if (simMap.getOrganism(x, y) == nullptr) {
				numAnts++;
				Ant* newAnt = new Ant(&simMap, x, y);
			}
		}
		while (numDoodle < 5) {
			int dx = rand() % 20;
			int dy = rand() % 20;
			if (simMap.getOrganism(dx, dy) == nullptr) {
				numDoodle++;
				Doodlebug* newDoodle = new Doodlebug(&simMap, dx, dy);
			}
		}
		bool gameOver = false;
		do {
			simMap.showMap();
			simMap.runSim();
			cout << "\nPress Enter to move to the next time step" << endl;
			cout << "Or type another letter to exit the simulation\n" << endl;
			if (cin.get() == '\n'){ 
				gameOver = false;
			}
			else {
				gameOver = true;
			}
		} 
		while (gameOver == false);
	}