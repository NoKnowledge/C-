//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack{

private:
	int lastPos;
	int cap;
	int size;

public:
	int* arr;	
	Stack(): lastPos(cap-1), cap(1), size(0) {arr = new int[cap];}
	~Stack(){
		delete[] arr;
	}
	Stack(const Stack& rhs): arr(nullptr){
		*this = rhs;
	}
	Stack& operator = (const Stack& rhs){
		if (this == &rhs){
			return *this;
		}
		delete[] arr;
		arr = new int[rhs.cap];
		for(int i = 0; i < rhs.size; i++){
			arr[i] = rhs.arr[i];
		}
		size = rhs.size;
		cap = rhs.cap;
		return *this;
	}

	void resize(int newsize){
		int numCopy;
		if(newsize < cap){
			numCopy = newsize;
			cap = newsize;
		}
		int* temp = new int[newsize];
		for(int i = 0; i < numCopy; i++){
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		cap = newsize;
	}

	void push(int newitem){
		if(size == cap){
			resize(++cap);
			lastPos++;
		}
		arr[size] = newitem;
		size++;
	}

	void clear(){
		//for(int i = 0; i < cap; i++){
		//	delete [] arr;
		//}
		//delete[] arr;
		//arr = nullptr;
		size=0;
	}
	bool isEmpty(){
		if(arr == nullptr){
			cout << "dynamic array empty" <<
			return true;
		}
		else{return false;}
	}
	int pop(){
		//int temp = arr[lastPos];
		//delete &arr[lastPos];
		//cout << temp << endl;
		//return temp;
		return arr[--size];
	}
	int top(){
		return arr[size-1];
	}

};

int main(){
	Stack d;
	for(int i = 0; i < 10; i++){
		d.push(i);
		cout << d.arr[i] << endl;
	}
	int remainder = d.pop();
	cout << remainder << endl;
	int rem = d.top();
	cout << rem << endl;
	d.clear();
	d.isEmpty();

}