#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Employee{
	string e_name;
	int id_num;
	double rate;
	double t_hours;
	double pay;
};

void printInfo(Employee arr[]){
	//vector<Employee>payslip;
	for (int i = 0; i < 50; i++){
		//double pay;
		//pay = arr[i].rate * arr[i].t_hours;
		if (arr[i].pay != 0){
			cout << arr[i].e_name << ": $" << arr[i].pay << endl;
		}
	}
}
void sortPay(Employee arr[]){
	for (int k = 0; k < 50; k++){
		arr[k].pay = arr[k].rate * arr[k].t_hours;
	}
	double j, temp;
	for (int i = 0; i < 50; i++){
		j = i;
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			}
		}
	}
}

int main(){
	Employee arr[50];
	int num;
	double rate;
	string name;
	double hours;
	ifstream readFile("data.txt");
	while(readFile >> num >> rate){
		getline(readFile, name);
		//cout << num << " " << rate << " " << name << endl;
		arr[num].id_num = num;
		arr[num].rate = rate;
		arr[num].e_name = name;
	}
	ifstream readFile2("payroll.txt");
	while(readFile2 >> num >> hours){
		//cout << num << " " << hours<< endl;
		arr[num].t_hours += hours;
	}

	sortPay(arr);
	printInfo(arr);






}