//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car{
	string make;
	string model;
	int license;
	double gas;
	double odometer;
	double rating;
public:
	Car(): make("unspecified"), model("unspecified"), license(0), gas(15),odometer(0),rating(25){}
	Car(string brand, string model, double rating):make(brand), model(model),rating(rating){}
	void fillTank(double gallons){
		gas += gallons;
	}
	double getGas() const{
		return gas;
	}
	double getMeter() const{
		return odometer;
	}
	double getRating() const{
		return rating;
	}
	double drive(){
		if(gas > 0){
			int i;
			i = rand() % 25 + 1;
			odometer = i;
			gas -= i / rating;
			return i;
		}
		else{
			cout << "No more gas." << endl;
		}
	}
	void changeLicense(int lic){
		license = lic;
	}
};

int main(){
	Car myCar("Honda", "Civic", 35);
	int distance = myCar.drive();
	cout << "The car drove " << distance << " miles." << endl;
	int distance2 = myCar.drive();
	cout << "The car drove " << distance2 << " miles." << endl;
}