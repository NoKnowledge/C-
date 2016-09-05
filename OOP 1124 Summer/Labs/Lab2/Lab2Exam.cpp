#include <iostream>
#include <string>
#include <vector>

using namespace std;


void arrSort(int*& arr, int s) {
	int* temp = new int[s];
	int count = 1;
	for (int i = 0; i < s; i++) {
		int count = i + 1;
		int hold = 0;
		while (count < s) {
			if (arr[i] < arr[count]) {
				cout << arr[i] << " is less than " << arr[count] << endl;
				count++;
			}
			else if (arr[i] > arr[count]) {
				cout << arr[i] << " is greater than " << arr[count] << endl;
				hold = arr[i];
				arr[i] = arr[count];
				arr[count] = hold;
				count++;
			}
			else if (arr[i] == arr[count]) {
				cout << arr[i] << " is equal to " << arr[count] << endl;
				count++;
			}
		}
		temp[i] = arr[i];
		cout << "temp[i] is " << temp[i] << endl;
	}
	delete[] arr;
	arr = temp;
	temp = nullptr; //kind of pointless
}
/*void sortArray(int size, int*& arr) {
	int counter = 1;
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		while(arr[i] < arr[counter]){
			counter++;
		}
	}
}*/

int main() {
	int size = 7;
	int* arr = new int[size];
	arr[0] = 7;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 9;
	arr[4] = 1;
	arr[5] = 7;
	arr[6] = -1;
	cout << "Before sort: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
	arrSort(arr, size);
	cout << "After sort: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}