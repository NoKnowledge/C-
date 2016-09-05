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
	void resize(int newsize);
	T operator[](T index) const;
	T& operator[] (T index);
	void push_back(T newitem);
	int getSize(){
		return size;
	}

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
void dynArray<T>::push_back(T newitem){
	if(size == cap){
		resize(cap * 2);
	}
	data[size] = newitem;
	size++;
}



template <class T>
class SearchHay{
	dynArray<T> haystack;

public:
	SearchHay(){}
	SearchHay& operator = (const SearchHay& rhs);
	bool operator == (const SearchHay& rhs);
	void resize(int newsize);
	void insertEle(T item);
	void searchNeedle(T needle);

};

template <class T> 
SearchHay<T>& SearchHay<T>::operator = (const SearchHay<T>& rhs){
	if(this == &rhs){
		return *this;
	}
}

template <class T>
bool SearchHay<T>::operator == (const SearchHay& rhs){
	return (*this == rhs);
}

template <class T>
void SearchHay<T>::insertEle(T item){
	haystack.push_back(item);
}

template <class T>
void SearchHay<T>::searchNeedle(T needle){
	for(int i = 0; i < haystack.getSize(); i++){
		if(haystack[i] == needle){
			cout << "Found needle!" << endl;
		}
		cout << "Searching..." << endl;
	}
}

int main(){
	SearchHay<int> p;
	p.insertEle(5);
	p.insertEle(2);
	p.insertEle(6);
	p.insertEle(9);
	p.insertEle(0);
	p.insertEle(2);
	p.insertEle(7);
	p.insertEle(435);
	p.insertEle(45);
	p.insertEle(879);
	p.insertEle(33);
	p.insertEle(12);
	p.insertEle(98);
	p.insertEle(5);
	p.insertEle(1);
	p.searchNeedle(98);	

}

