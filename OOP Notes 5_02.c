/*
the STL: Standard Template Library
*/
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using mamespace std;

char* find(char* start, char* stop, char target){
	for(char* p = start; p != stop; p++){
		if(target == *p){
			return p;
		}
	}
	return stop;
}

int main(){
	char array[] = "Bjorne Stroustrup";
	int len = 17;
	vector<char> vc  = {array, array+len};
	//half-open range [start, stop) 
	//"[" = inclusive, ")" = exclude stop
	list<char> lc(array, array+len);
	sort(array, array+len);
	for(size_t i = 0; i < vc.size(); i++){
		cout << vc[i];
	}
	cout << endl;

	//use "ranged for" loop
	// for(size_t i =0; i < lc.size(); i++){
	// 	cout << lc[i];
	// }
	// cout << endl;
	list<char>::iterator iter;
	for(iter = lc.begin(); iter != lc.end(); iter++){
		cout << *iter;
	}
	cout << endl;

	//or

	for(auto iter = lc.begin(); iter != lc.end(); iter++){
		cout << *iter;
	}
	cout << endl;

	sort(vc.begin(), vc.end()); //sorts all elements in vector

	//find(array, array+len, 'p'); //syntax to find something 
	//returns address of 'p'

	char* where = find(array, array+len, 'p');
	cout << (void*)where << endl;

	list<char>::iterator otherWhere = find(lc.begin(), lc.end(), 'p');
	//return type is same as iter

	auto otherWhere = find(lc.begin(), lc.end(), 'p');
	//compiler knows return type is list<char>::iterator

	where = find(array, array+len, 'q');
	otherWhere = find(lc.begin(), lc.end(),'q');
	if (otherWhere = lc.end()){
		cout << "could not find 'q'\n";
	}

	auto x = 17; //compiler knows what type 17 is
	auto y;      //compiler doesn't know what type this is


}