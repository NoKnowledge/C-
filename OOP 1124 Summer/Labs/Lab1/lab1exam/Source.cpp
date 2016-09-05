#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Meters {
	int ID = 0;
	int month1 = 0;
	int month2 = 0;
};

int main() {
	string filename1;
	string filename2;
	int id_num;
	int reading;
	int reading2;
	Meters arr[20];
	cout << "Enter filename for month 1: ";
	cin >> filename1;
	ifstream readFile1(filename1);
	while (readFile1 >> id_num >> reading) {
		arr[id_num].ID = id_num;
		arr[id_num].month1 = reading;
	}

	cout << "Enter filename for month 2: ";
	cin >> filename2;
	ifstream readFile2(filename2);
	while (readFile2 >> id_num >> reading2) {
		if (id_num == arr[id_num].ID) {
			arr[id_num].month2 = reading2;
		}
		else {
			arr[id_num].ID = id_num;
			arr[id_num].month2 = reading2;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (arr[i].ID != 0) {
			bool hasZero = 0;
			double diff;
			diff = arr[i].month1 - arr[i].month2;
			if (diff < 0) {
				diff = diff * -1;
				cout << arr[i].ID << " " << diff << "kWh" << endl;
			}
			else {
				cout << arr[i].ID << " " << diff << "kWh" <<  endl;
			}
			if (arr[i].month1 == 0 && arr[i].month2 != 0) {
				cout << "Month 1 was not checked for ID " << i << endl;
			}
			else if (arr[i].month2 == 0 && arr[i].month1 != 0) {
				cout << "Month 2 was not checked for ID " << i << endl;
			}

		}
		}
}