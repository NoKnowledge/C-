#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

//char* where = find(array, array+len, 'p');
char* myFind(char* start, char* stop, char target){
	cerr << "myFind(char* start, char* stop, char target)\n";
	for(char *p = start; p != stop; p++){
		if(target == *p){
			return p;
		}
	}
	return stop;
}

// list<int>::iterator myFind(list<int>::iterator start,
// 						   list<int>::iterator stop, int target){
// 	for(list<int>::iterator p = start; p != stop; p+){
// 		if (target == *p){
// 			return p;
// 		}
// 	}
// 	return stop;
// }

template <typename Fred, typename George>
Fred myFind(Fred start, Fred stop, George target){
	for(Fred p = start; p != stop; p+){
		if (target == *p){
			return p;
		}
	}
	return stop;
}

cout << *find_if(li.begin(), li.end(), 
				 [] (int n) {return n%2 != 1;} //lambda expression
				 ) << endl;


int main(){
	char array[] = "Bjorne Stroustrup";
	int len = 17;
	if ((myFind(array, array+len, 'p') != array+len){
		cout << "Found 'p'\n";
	}

	list<int>li {2,4,6,8,1,3,5,7};
	if ((myFind(li.begin(), li.end(), 19) == li.end()){
		cout << "Didn't find 19 \n";
	}
}