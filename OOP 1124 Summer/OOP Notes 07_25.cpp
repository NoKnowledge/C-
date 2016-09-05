#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
recursive problems
1) what is the base case?
2) what is the single case?
3) how do you reduce the set by the single case, working towards the base case?
*/

void printNum(int n){
	if (n <= 0){ //base case
		return;
	}
	cout << n << endl;
	printNum(n-1);
}

void printNumRev(int n){
	if(n > 1){
		printNumRev(n - 1);
	}
	cout << n << endl;
}

void printNumRev2(int n){
	if(n <= 0){
		return;
	}
	printNumRev2(n - 1);
	cout << n << endl;
}

int factorial(int n){
	if(n <= 0){
		return 1;
	}
	return n*factorial(n-1); 
}

double power(int base, int exponent){
	if(exponent == 0){
		return 1;
	}
	if(exponent > 0){
		return base*power(base,exponent-1);
	}
	else if(exponent < 0){
		return 1/power(base, -exponent);
	}
}

int sumArray(int* arr, int size){
	if(size == 0){
		return 0;
	}
	return arr[0] + sumArray(arr + 1, size - 1);
}

int printABStr(int n){
	if(n <= 0){
		return 0;
	}
	cout << 'A' << endl;
	printABStr(n - 1);
	cout << 'B' << endl;

}

bool isLetter(char c){
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool isPalindrome(char* str, int size){
	if(size <= 1){
		return true;
	}
	if (!isLetter(str[0])){
		return isPalindrome(str + 1, size - 1);
	}
	else if(!isLetter(str[size - 1])){
		return isPalindrome(str, size - 1);
	}
	if (str[0] == str[size - 1]){
		return isPalindrome(str + 1, size - 2);
	}
	return false;
}


int main(){
	printNum(5);
	printNumRev(5);
	printNumRev2(5);
	cout << factorial(5) << endl;
	cout << power(2,60) << endl;
	cout << power(5,-2) << endl;
	printABStr(3);
	cout << boolalpha << isPalindrome("dad",3) << endl; 
	cout << boolalpha << isPalindrome("a man, a plan, a canal, panama",30) << endl;
}