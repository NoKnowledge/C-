//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class dynArray{
	int* data;
	int size;
	int cap;
public:
	dynArray(): cap(5), size(0) {data = new int[cap];}
	~dynArray(){
		delete[] data;
	}
	dynArray(const dynArray& rhs):data(nullptr){
		*this = rhs;
	}
	dynArray& operator = (const dynArray& rhs){
		if(this == &rhs){
			return *this;
		}
		delete[] data;
		data = new int[rhs, cap];
		for (int i = 0; i < rhs.size; i++){
		data[i] = rhs.data[i];
		size = rhs.size;
		cap = rhs.cap;
		return *this;
	}
	}
	void storeAtEnd(int num){
		if(size <= cap){
			data[size] = num;
			size++;
		}
		else{
			resize(cap+1);
			data[size+1] = num;
			size++;
		}
	}
	void resize(int newsize){
		int numCopy;
		if(newsize < cap){
			numCopy = newsize;
			cap = newsize;
		}
		int* temp = new int[newsize];
		for(int i = 0; i < numCopy; i++){
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		cap = newsize;
	}
	int operator[](int index) const{
		return data[index];
	}
	int& operator[] (int index){
		return data[index];
	}
	int getCap(){
		return cap;
	}
	void push_back(int newitem){
		if(size == cap){
			resize(cap * 2);
		}
		data[size] = newitem;
		size++;
	}

};

int main(){
	dynArray d;
	for(int i = 0; i < 100; i++){
		d.push_back(i);
	}
	cout << "original d:" << endl;
	for(int i = 0; i< 100; i++){
		cout << d.data[i] << endl;
	}
	dynArray d2;
	for(int i = 0; i < 100; i++){
		d.push_back(i+1);
	}
	d = d2;
	cout << "modded d:" << endl;
	for(int i = 0; i< 100; i++){
		cout << d.data[i] << endl;
	}
}