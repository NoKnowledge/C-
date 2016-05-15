//Jimmy Lauchoy
//CS1124
//rec 14

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <fstream>
#include <set>

using namespace std;

void printList(const list<int> aList) {
    for (list<int>::const_iterator iter = aList.begin(); iter != aList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    
}

void printList2(const list<int> aList) {
    for (int x:aList) {
        cout << x << " ";
    }
    cout << endl;
}

auto printList3(const list<int> aList) {
    for (list<int>::const_iterator iter = aList.begin(); iter != aList.end(); ++(++iter)) {
        cout << *iter << " ";
    }
    cout << endl;
}

list<int>::const_iterator findIter(const list<int>& aList, int num) {
    for (list<int>::const_iterator iter = aList.begin(); iter != aList.end(); ++iter) {
        if (*iter == num) {
            return iter;
        }
    }
    return aList.end();
}

auto findIter2(const list<int>& aList, int num) {
    for (auto iter = aList.begin(); iter != aList.end(); ++iter) {
        if (*iter == num) {
            return iter;
        }
    }
    return aList.end();
}

bool isEven(int x) {
    return (x%2 == 0);
}

list<int>::const_iterator ourFind(const list<int>& aList, int num) {
    cout << "In ourFind" << endl;
    for (list<int>::const_iterator iter = aList.begin(); iter != aList.end(); ++iter) {
        if (*iter == num) {
            return iter;
        }
    }
    return aList.end();
}

template <typename Chicken, typename Duck>

typename Chicken::iterator ourFind(Chicken aList, Duck num) {
    cout << "In Template" << endl;
    for (typename Chicken::iterator iter = aList.begin(); iter != aList.end(); ++iter) {
        if (*iter == num) {
            return iter;
        }
    }
    return aList.end();
}

void addWords(vector<string>& words, ifstream& ifs) {
    string word;
    while (ifs >> word) {
        bool exists = false;
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word) {
                exists = true;
            }
        }
        if (exists == false) {
            words.push_back(word);
        }
    }
}

int main() {
    //Ex 1
    cout << "Ex 1: ";
    vector<int> vc{21,1,3,8,5,34,2,1};
    //vector<int> vc{2,63,25,15,1,3,1,45};
    for (int x:vc) {
        cout << x << " ";
    }
    cout << endl;
    
    //Ex 2
    cout << "Ex 2: ";
    list<int> aList{vc.begin(), vc.end()};
    for (list<int>::iterator iter = aList.begin(); iter != aList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    
    //Ex 3
    cout << "Ex 3: ";
    sort(vc.begin(),vc.end());
    for (int x:vc) {
        cout << x << " ";
    }
    cout << endl;
    
    //Ex 4
    cout << "Ex 4: ";
    for (size_t i = 0; i < vc.size(); i+=2) {
        cout << vc[i] << " ";
    }
    cout << endl;
    
    //Ex 5
    cout << "Ex 5: ";
    aList.sort();
    for (list<int>::iterator iter = aList.begin(); iter != aList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    
    //Ex 6
    cout << "Ex 6: ";
    for (vector<int>::iterator iter = vc.begin(); iter != vc.end(); iter += 2) {
        cout << *iter << " ";
    }
    cout << endl;
    
    //Ex 7
    cout << "Ex 7: ";
    for (list<int>::iterator iter = aList.begin(); iter != aList.end(); ++(++iter)) {
        cout << *iter << " ";
    }
    cout << endl;
    
    //Ex 8
    cout << "Ex 8: ";
    printList(aList);
    
    //Ex 9
    cout << "Ex 9: ";
    printList2(aList);
    
    //Ex 10
    cout << "Ex 10: ";
    printList3(aList);
    
    //Ex 11
    cout << "Ex 11: ";
    if (findIter(aList, 4) == aList.end()) {
        cout << "4 is not found!" << endl;
    }
    else { cout << "4 is found!" << endl;}
    if (findIter(aList, 5) == aList.end()) {
        cout << "5 is not found!" << endl;
    }
    else { cout << "5 is found!" << endl;}
    
    //Ex 12
    cout << "Ex 12: ";
    if (findIter(aList, 1) == aList.end()) {
        cout << "1 is not found!" << endl;
    }
    else { cout << "1 is found!" << endl;}
    if (findIter(aList, 13) == aList.end()) {
        cout << "13 is not found!" << endl;
    }
    else { cout << "13 is found!" << endl;}
    
    //Ex 13
    cout << "Ex 13: ";
    if (find(aList.begin(),aList.end(), 21) == aList.end()) {
        cout << "21 is not found!" << endl;
    }
    else { cout << "21 is found!" << endl;}
    
    //Ex 14
    cout << "Ex 14: ";
    if (find_if(aList.begin(), aList.end(), isEven) != aList.end()) {
        cout << *(find_if(aList.begin(), aList.end(), isEven)) << endl;
    }
    else {
        cout << "Not Found!" << endl;
    }
    
    //Ex 15
    cout << "Ex 15: ";
    if (find_if(aList.begin(), aList.end(),
                [](int n) {return n%2 == 0;}
                ) != aList.end()) {
        cout << *(find_if(aList.begin(), aList.end(), [](int n) {return n%2 == 0;})) << endl;}
    else {
        cout << "Not Found!" << endl;
    }
    
    //Ex 16
    cout << "Ex 16: ";
    int arr[8];
    copy(aList.begin(), aList.end(), arr);
    
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    if (find(arr,arr+8, 21) != arr+8) {
        cout << "21 is found!" << endl;
    }
    else {
        cout << "21 is not found!" << endl;
    }
    
    //Ex 17
    cout << "Ex 17: ";
    if (ourFind(aList, 5) == aList.end()) {
        cout << "5 is not found!" << endl;
    }
    else { cout << "5 is found!" << endl;}
    
    //Ex 18
    cout << "Ex 18: ";
    if (ourFind(vc,21) != vc.end()) {
        cout << "21 is found!" << endl;
    }
    else {cout << "21 is not found!" << endl;}
    
    //Ex 19
    cout << "Ex 19: ";
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs) {
        cout << "File Not Opened!" << endl;
    }
    else {
        vector<string> words;
        addWords(words,ifs);
        cout << words.size() << ": ";
        for (size_t i = 0; i < words.size(); ++i) {
            cout << words[i] << " ";
        }
        cout << endl;
        ifs.close();
    }
    
    //Ex 20
    cout << "Ex 20: ";
    set<string> setWords;
    string word;
    ifs.open("pooh-nopunc.txt");
    while (ifs >> word) {
        setWords.insert(word);
    }
    
    for (string word:setWords) {
        cout << word << " ";
    }
    cout << setWords.size() << endl;
    ifs.close();
    
    //Ex 21
    cout << "Ex 21: ";
    
    map<string, vector<int>> wordMap;
    int position = 0;
    ifs.open("pooh-nopunc.txt");
    
    while (ifs >> word) {
        wordMap[word].push_back(position);
        ++position;
    }
    
    cout << "Map Size: " << wordMap.size() << endl;
    
    for(auto i : wordMap) {
        cout << i.first << ": ";
        for (size_t a = 0; a < i.second.size(); ++a) {
            cout << i.second[a] << " ";
        }
        cout << endl;
    }
    
}



