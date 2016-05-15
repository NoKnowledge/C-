#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Sandwich{
	const int bread = 2;
	int cheese;
	float mayo;
	int tomatoes;
	float mustard;
public: 
	Sandwich(int c = 1, float m = 0.1, int t = 2, float md = 0.5) : 
	cheese(c), mayo(m), tomatoes(t), mustard(md){}
	void display() const{
		cout<<"Bread:"<<bread<<"\nCheese:"<<cheese<<"\nMayo:"<<
		mayo<<"\nTomatoes:"<<tomatoes<<"\nMustard:"<<mustard<<endl;
	}
	//changes values of orders
	void new_mayo(const float& m){
		mayo = m;
	}
	void new_cheese(const int& c){
		cheese = c;
	}
	void new_tom(const int& t){
		tomatoes = t;
	}
	void new_must(const float& md){
		mustard = md;
	}
	//gets amounts from orders
	float get_mayo() const{
		return mayo;
	}

	int get_cheese() const{
		return cheese;
	}
	int get_tom() const {
		return tomatoes;
	}
	float get_must() const{
		return mustard;
	}
	int get_bread() const{
		return bread;
	}
};

class Sandwich_truck{
	vector<Sandwich> sandwiches;
public:
	void insert_sandwich(Sandwich a_Sandwich){
		sandwiches.push_back(a_Sandwich);
	}
	void check_before_leaving() const{
		for (size_t index = 0; index < sandwiches.size(); index++){
			cout << "Sandwich" << index + 1 << ":" << endl;
			sandwiches[index].display();
			cout << endl;
		}
	}
};
int main(){
	Sandwich Sandwich1;
	Sandwich Sandwich2;
	Sandwich2.new_must(0);
	Sandwich Sandwich3;
	Sandwich3.new_cheese(2);
	Sandwich Sandwich4;

	Sandwich_truck a_truck;
	a_truck.insert_sandwich(Sandwich1);
	a_truck.insert_sandwich(Sandwich2);
	a_truck.insert_sandwich(Sandwich3);
	a_truck.insert_sandwich(Sandwich4);
	a_truck.check_before_leaving();
	cout << "Sandwich 2 Mustard:" << Sandwich2.get_must() << endl;
}
