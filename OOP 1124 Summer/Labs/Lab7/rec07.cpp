//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myLocation {
protected:
	int x;
	int y;
public:
	myLocation() : x(0), y(0) { cout << "In the no argument constructor of myLocation" << endl; }
	myLocation(int xcoord, int ycoord) : x(xcoord), y(ycoord) { cout << "In the two argument constructor of myLocation" << endl; }
	virtual void display() {
		cout << "In the display function of myLocation" << endl;
		cout << "Coordinates: (" << x << "," << y << ")" << endl;
	}
};

class myPoint : public myLocation {
protected:
	char color;
public:
	myPoint() : color('w') { cout << "In the no argument constructor of myPoint" << endl; }
	myPoint(char newcolor) : color(newcolor) { cout << "In the one argument constructor of myPoint" << endl; }
	void display() {
		cout << "In the display function of myLocation" << endl;
		cout << "Color: " << color << endl;
	}
};

class myCircle : public myPoint {
protected:
	double diameter;
public:
	myCircle() : diameter(0.0) {
		myPoint();
		myLocation();
	}
	myCircle(int xcoord, int ycoord, char newcolor, double newdiam) : diameter(newdiam), myPoint(newcolor) {
		myLocation(xcoord, ycoord);
		//myPoint(newcolor);
	}
	void display() {
		cout << "Diameter: " << diameter << endl;
	}
};


int main() {
	int option;
	do {
		cout << "1) Show myLocation's constructors and display" << endl;
		cout << "2) Show myPoint's constructors and display" << endl;
		cout << "3) Task 3 & 4" << endl;
		cout << "4) Task 5" << endl;
		cout << "5) Task 6" << endl;
		cout << "6) Exit" << endl;

		cout << "Select an option:";
		cin >> option;
		if (option == 1) {
			myLocation loc;
			loc.display();
			myLocation loc2(56, 85);
			loc2.display();
		}
		else if (option == 2) {
			myPoint point;
			point.display();
			myPoint point2('b');
			point2.display();
		}
		else if (option == 3) {
			myPoint point;
			point.display();
			myPoint point2('b');
			point2.display();
			myLocation* loc;
			loc = &point;
			loc->display();
			myLocation* loc2;
			loc2 = &point2;
			loc2->display();
		}
		else if (option == 4) {
			myLocation** myArray = new myLocation*[6];
			myLocation loc1;
			myLocation loc2;
			myPoint pt1;
			myPoint pt2;
			myCircle c1;
			myCircle c2;
			myArray[0] = &loc1;
			myArray[1] = &loc2;
			myArray[2] = &pt1;
			myArray[3] = &pt2;
			myArray[4] = &c1;
			myArray[5] = &c2;
			for (int i = 0; i < 6; i++) {
				myArray[i]->display();
			}
		}
		else if (option == 5) {
			myLocation myArray [6];
			myLocation loc1;
			myLocation loc2(50,40);
			myPoint pt1;
			myPoint pt2('g');
			myCircle c1;
			myCircle c2(75, 40, 'p', 30.2);
			myArray[0] = loc1;
			myArray[1] = loc2;
			myArray[2] = pt1;
			myArray[3] = pt2;
			myArray[4] = c1;
			myArray[5] = c2;
			for (int i = 0; i < 6; i++) {
				myArray[i].display();
			}
		}
		else if (option == 6) {
			cout << "Closing menu" << endl;
		}
		else {
			cout << "Invalid selection." << endl;
		}
	} while (option != 6);
}