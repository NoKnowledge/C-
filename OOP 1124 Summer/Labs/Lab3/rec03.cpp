//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

class DeliveryTruck{
	string ad;
	double thePackages[50];
	double truckWeight;
public:
	DeliveryTruck(): ad("No ad"), truckWeight(1000){}
	void display(){
		cout << ad << endl;
		cout << "Packages: " << endl;
		for (int i = 0; i < 50; i++){
			while(thePackages[i] != 0){
				cout << thePackages[i] << endl;
			}
		}
	}
	void setAd(string newAd){
		ad = newAd;
	}
	void addPackage(double pkg){
		for(int i = 0; i < 50; i++){
			if(thePackages[i] != 0){
				thePackages[i] = pkg;
			}
		}
	}
	double getWeight(){
		double total;
		for(int i = 0; i < 50; i++){
			if(thePackages[i] != 0){
				total += thePackages[i];
			}
		}
		return total;
	}

};

int main(){
	DeliveryTruck d;
	int option;
	do {
		cout << "Jimmy's Delivery Truck Service" << endl;
		cout << "1) Display default Delivery Truck" << endl;
		cout << "2) Change advertising" << endl;
		cout << "3) View package information" << endl;
		cout << "4) View truck weight" << endl;
		cout << "5) Check packages" << endl;
		cout << "6) Exit" << endl;
		
		cout << "Select an option:";
		cin >> option;
		if(option == 1){
			d.display();
		}
		else if(option == 2){
			string newAd;
			cout << "Enter your new advertisement: ";
			cin >> newAd;
			d.setAd(newAd);
		}
		else if(option == 3){
			double package;
			ifstream readFile("data.txt");
			while(readFile >> package){
				d.addPackage(package);
			}
			d.display();
			readfile.close()
		}
		else if(option == 4){
			d.displayWeight();
		}
		else if(option == 5){
			int id;
			cout << "Enter ID number of package: ";
			cin >> id;
			searchForPackage(id);
		}
		else if(option == 6){
			cout << "Closing menu" << endl;
		}
		else{
			cout << "Invalid selection." << endl;
		}
	}
	while (option != 6);
}