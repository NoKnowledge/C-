/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

void resizeArray(int*& arr, int currentSize, int newSize) {
	int toCopy;
	if (newSize < currentSize) {
		toCopy = newSize;
	}
	else {
		toCopy = currentSize;
	}
	int* temp = new int[newSize];
	for (int i = 0; i < currentSize; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	temp = nullptr; //kind of pointless
}

int main() {
	cout << "Jimmy Lauchoy\nCS1124 Summer\nSection A\njl7263\n" << endl;
	int x;
	x = 10;
	int* address = &x;
	cout << "x = " << x << endl;
	cout << "&x = " << address  << endl;
	int* p;
	p = new int(10);
	cout << "p = " << *p << endl;

	int* p1, *p2;
	p1 = new int;
	*p1 = 42;
	p2 = p1;

	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;

	*p2 = 53;

	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;

	p1 = new int;
	*p1 = 88;

	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;

	cout << "Hope you got the point of this example!\n";

	int a(10);
	int b = 20;
	int* c;
	c = new int(30);
	int* d, e;
	d = new int(40);
	e = 50;
	int* f;
	f = d;
	cout << "a: " << a << endl;
	cout << "address of a: " << &a << endl;
	cout << "b: " << b << endl;
	cout << "address of b: " << &b << endl;
	cout << "c: " << *c << endl;
	cout << "address of  c: " << c << endl;
	cout << "d: " << *d << endl;
	cout << "address of d: " << d << endl;
	cout << "e: " << e << endl;
	cout << "address of e: " << &e << endl;
	cout << "f: " << *f << endl;
	cout << "address of f: " << f << endl;

	int* A;
	A = new int(100);
	int * B;
	B = A;
	cout << "The value of A is " << *A << endl;
	cout << "A is pointing to the location " << A << endl;
	cout << "The value of B is " << *B << endl;
	cout << "B is pointing to the location " << B << endl;
	*/
	/*
	cout << "Returning the memory for A to the heap: " << endl;
	delete A;
	cout << "The value of A is " << *A << endl;
	cout << "A is pointing to the location " << A << endl;
	cout << "The value of B is " << *B << endl;
	cout << "B is pointing to the location " << B << endl;
	*/

/*
	int size = 5;
	int* arr = new int[size];
	for (int i = 0; i < 5; i++) {
		arr[i] = i * i;
		cout << arr[i] << endl;
	}
	int arrSize;
	int newValue;
	cout << "Enter number of new values: ";
	cin >> arrSize;
	resizeArray(arr, 5, arrSize + 5);
	for (int k = 5; k < arrSize + 5; k++) {
		cout << "New value: ";
		cin >> newValue;
		arr[k] = newValue;
		cout << arr[k] << endl;
	}
	cout << "Your array contains: " << endl;
	for (int j = 0; j < arrSize+5; j++) {
		cout << arr[j] << ", " ;
	}
	cout << endl;
}
*/

