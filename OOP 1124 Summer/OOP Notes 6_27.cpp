#include <iostream>

using namespace std;

class DynArray{
	int* data;
	int cap;
	int items;

	public:
	DynArray():cap(5), items(0){data = new int[cap];}
	~DynArray(){ //destructor
		delete[] data;
	}
	DynArray(const DynArray& rhs): data(nullptr){ //copy constructor
		*this = rhs;
	}
	DynArray& operator = (const DynArray& rhs); //assignment operator
	int size() const{
	return items;
	}

	int capacity() const{
	return cap;
	}

	void resize(int newsize);
	void push_back(int newitem);
	int pop_back();

	void clear(){
		items = 0;
	}
	int operator[](int index) const{
		return data[index];
	}
	int& operator[] (int index){
		return data[index];
	}

};


DynArray& DynArray::operator = (const DynArray& rhs){
	if (this == &rhs){ //check to see if they POINT TO THE SAME ADDRESS
		return *this;
	}
	delete[] data;
	data = new int[rhs, cap];
	for (int i = 0; i < rhs.items; i++){
		data[i] = rhs.data[i];
		itmes = rhs.items;
		cap = rhs.cap;
		return *this;
	}

}
void DynArray::push_back(int newitem){
	if(items == cap){
		resize(cap * 2);
	}
	data[items++] = newitem;
}

void DynArray::resize(int newSize){
	int itemsToCopy;
	if (newSize<itemstoCopy){
		itemsToCopy = newSize;
		items = newSize;
	}
	int* temp = new int[newSize];
	for(int i = 0; i < itemsToCopy; i++){
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	cap = newSize;
}

int DynArray::pop_back(){
	if(items == cap){
		resize(cap * 2);
		data[items++] = newitem;
	}
}

void func()

int main(){
	DynArray d;
	for(int i = 0; i < 100; i++){
		d.push_back(i);
	}
	/*for(int i = 0; i < d.size(); i++){
		cout << d[i] << endl;
	}*/

	for(int i = 0; i < 100; i++){
		func(d);	
	}
}

