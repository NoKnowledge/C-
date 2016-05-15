#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs("encrypted.txt");
	int rotation;
	ifs >> rotation;
	string word;
	string d_word;
	while(ifs >> word){
		cout << "encrypted: " << word << endl;
		for (int i = 0; i < word.size(); i++){
			word[i] += rotation;
			d_word += word[i];
		}
		cout << d_word << endl;
	}
	cout << endl;
}