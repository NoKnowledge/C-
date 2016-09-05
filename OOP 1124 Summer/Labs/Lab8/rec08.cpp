//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int iterativeFactorial(int n){
	int sum = 1;
	while(n > 1){
		sum *= n;
		n--;
	}
	return sum;
}

int recursiveFactorial(int n){
	if(n <= 0){
		return 1;
	}
	else{
		return n*recursiveFactorial(n-1);
	}
}
/*
string writeStringBackwards(char* s){
	int index = strlen(s);
	if (index < 0)
	{
		cout << "Empty string" << endl;
		return "Empty string";
	}

	else{
		cout << s[index];
		writeStringBackwards(s-1);
	}
}
*/

void ReverseName(char* s){ 
    if(*s){ 
        ReverseName(s+1); 
        cout << *s; 
        } 
    return; 
}

void ReverseName2(char* s){
	//strip first char of c-string and put 
	//on the back of an empty c-string
	//return new string
	//char newString[];
	//if(*s)

}

unsigned int Acker(int m, int n){
	if(m == 0){
		return n + 1;
	}
	else if(n == 0){
		return Acker(m - 1, 1);
	}
	else{
		return Acker(m - 1, Acker(m, n - 1));
	}
}

int main(){
	int result;
	result = iterativeFactorial(5);
	cout << result << endl;
	int result2;
	result2 = recursiveFactorial(3);
	cout << result2 << endl;
	//char aString[] = "BACKWARDS";
	//cout << writeStringBackwards(aString) << endl;
	unsigned int a = Acker(1,1);
	cout << a << endl;
	char astring[] = "BACKWARDS";
	ReverseName(astring);
}
