//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class dynArray{
	T* data;
	int size;
	int cap;
public:
	dynArray(): cap(5), size(0) {data = new T[cap];}
	~dynArray(){
		delete[] data;
	}
	dynArray(const dynArray& rhs):data(nullptr){
		*this = rhs;
	}
	dynArray& operator = (const dynArray& rhs);
	void storeAtEnd(T num);
	void resize(int newsize);
	T operator[](T index) const;
	T& operator[] (T index);
	T getCap();
	void push_back(T newitem);
	void display();

};

template <class T> 
dynArray<T>& dynArray<T>::operator = (const dynArray<T>& rhs){
	if(this == &rhs){
		return *this;
	}
	delete[] data;
	data = new T[rhs, cap];
	for (int i = 0; i < rhs.size; i++){
		data[i] = rhs.data[i];
	}
	size = rhs.size;
	cap = rhs.cap;
	return *this;
}

template <class T>
void dynArray<T>::storeAtEnd(T num){
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

template <class T>
void dynArray<T>::resize(int newsize){
	int numCopy;
	if(newsize < cap){
		numCopy = newsize;
		cap = newsize;
	}
	T* temp = new T[newsize];
	for(int i = 0; i < numCopy; i++){
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	cap = newsize;
}

template <class T>
T dynArray<T>::operator[](T index) const{
		return data[index];
}

template <class T>
T& dynArray<T>::operator[] (T index){
	return data[index];
}

template <class T>
T dynArray<T>::getCap(){
	return cap;
}

template <class T>
void dynArray<T>::push_back(T newitem){
	if(size == cap){
		resize(cap * 2);
	}
	data[size] = newitem;
	size++;
}

template <class T>
void dynArray<T>::display(){
	for(int i = 0; i < size; i++){
		cout << data[i] << endl;
	}
}


int main(){
	dynArray<int> d;
	d.storeAtEnd(5);
	d.storeAtEnd(9);
	d.storeAtEnd(7);
	d.storeAtEnd(12);
	d.storeAtEnd(35);
	d.display();
	dynArray<string> s;
	s.storeAtEnd("this");
	s.storeAtEnd("is");
	s.storeAtEnd("just");
	s.storeAtEnd("another");
	s.storeAtEnd("string");
	s.display();
}