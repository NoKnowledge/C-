//Jimmy Lauchoy
//CS1124 Summer
//HW 02

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void swap(char& a, char& b){
	char temp = a;
	a = b;
	b = temp;
}

void swap(double& a, double& b){
	double temp = a;
	a = b;
	b = temp;
}
*/

template <class T> //template <typename T> //same thing
void mySwap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void printLine(T item){
	cout << T << endl;
}

template <class T, class S>
void printTwoThings(T first, S second){
	cout << first << "," << second << endl;
}

template <class T>
class Storage{
	T item;
public:
	void changeItem(T newItem){
	T getItem() const;
};

void Storage<T>::changeItem(T newItem){ //name of class changes to recognize templated class
	item = newItem;
}

template <class T>
T Storage<T>::getItem() const{
	return item;
}

template <class T>
class Stack{
	T* data;
	int capacity;
	int numOfItems;
public:
	Stack() : data(new T[5]), capacity(5), numOfItems(0){}
	Stack(const Stack& rhs): data(nullptr){*this = rhs;}
	~Stack(){delete[] data;}
	Stack& operator = (const Stack& rhs);
	void resize(int newsize);
	void push(T newItem);
	T pop();
	T& top();
};

template <class T>
void Stack<T>::push(T newsize){
	if(numOfItems == capacity){
		resize(capacity * 2);
	}
	data[numOfItems++] = newItem
}

template <class T>
T& Stack<T>::top(){
	return data[numOfItems - 1];
}
template <class T>
void Stack<T>::pop(){
	T temp;
	if(numOfItems > 0){
		temp = data[--numOfItems];
	}
}
template <class T>
void Stack<T>::resize(int newsize){
	T* temp = new T[newsize];
	if (newsize < numOfItems){
		numOfItems = newsize;
	}
	for(int i = 0; i < numOfItems; i++){
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	capacity = newsize;
}

template <class T>
void sort(T* data, int size){
	for(int i = 0; i < size; i++){
		int j = i + 1;
		while(j > 0 && data[j] < data[j-1]){
			swap(data[j], data[j-1]);
			j--;
		}
	}
}

template <class T>
void bubbleSort(T* data, int size){
	for(int i = 1; i < size; i++){
		T temp = data[i];
		int j = i;
		for(; j > 0 && data[j-1] > temp; j--){ //for(j = i; j > 0 && data[j-1] > temp; j--){
			data[j] = data[j - 1];
		}
		data[j] = temp;
	}
}

template <class T>
Stack& Stack<T>::operator = (const Stack<T>& rhs){
	if(this == &rhs){
		return *this;
	}
	delete[] data;
	data = new T[rhs.capacity];
	capacity = rhs.capacity;
	numOfItems = rhs.numOfItems;
	for(int i - 0; i < numOfItems; i++){
		data[i] = rhs.data[i];
	}
}

template <class T, class S>
class Pair{
	T first;
	S second;
};

int main(){
	int i1, i2;
	double d1, d2;
	float f1, f2;
	mySwap(i1, i2);
	mySwap(d1, d2);
	mySwap(f1, f2);
	vector<int> v;
	Storage<int> s;

}
