//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle{
	int* VIN;
	double* gas;
public:
	Vehicle(): VIN(nullptr), gas(nullptr){}
	virtual void display(){
		cout << "Vehicle ID number: " << *VIN << endl;
		cout << "Gas mileage: " << *gas << endl;
	}
	int getVIN(){
		return *VIN;
	}
	double getGas(){
		return *gas;
	}
	void setVIN(int newVIN){
		VIN = &newVIN;
	}
	void setGas(double newGas){
		gas = &newGas;
	}
	double calcGasUsed(double miles){ //assuming 25mpg
		return miles/25;
	}
	void drive(){
		double i = rand() % 100 + 1;
		double total = calcGasUsed(i);
		cout << "Gas used: " << total << " gallons" << endl;
	}
};

class SUV: public Vehicle{
	bool* fourWDStatus;
	double* fourWDGasMileage;
public:
	void display(){
		cout << boolalpha;
		cout << "Four Wheel Drive Status: " << *fourWDStatus << endl;
		cout << "Four Wheel Drive Mileage: " << *fourWDGasMileage << endl;
	}
	bool getStatus(){
		return *fourWDStatus;
	}
	double getMileage(){
		return *fourWDGasMileage;
	}
	void setStatus(bool status){
		fourWDStatus = &status;
	}
	void setMileage(double mileage){
		fourWDGasMileage = &mileage;
	}
	double calcGasUsed(int miles){
		if(getStatus() == true){
			cout << "Vehicle is in 4x4 mode" << endl;
			return miles/15;
		}
		else{
			cout << "Vehicle is in regular mode" << endl;
			calcGasUsed(miles);
		}
	}
};

int main(){
	Vehicle carArray[3];
	Vehicle car;
	SUV suv1;
	SUV suv2;
	suv1.setStatus(true);
	carArray[0] = car;
	carArray[1] = suv1;
	carArray[2] = suv2;
	for(int i = 0; i < 3; i++){
		carArray[i].drive();
	}
}