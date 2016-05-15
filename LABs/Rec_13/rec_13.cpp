//Jimmy Lauchoy
//CS 1124

#include <string>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct node{
	node(int data = 0, node* next = NULL) : data(data), next(next) {}
	int data;
	node* next;
};

void inBinary (int number){
	if (number != 0){
		inBinary (number / 2);
		cout << number % 2;
	}
}

node* sumOfLists(node* listA, node* listB){
	if (listA != NULL){
		node* newNode = new node;
		newNode->data = listA->data + listB->data;
		newNode->next = sumOfLists(listA->next, listB->next);
		return newNode;
		}
	else {
		return NULL;
	}
}

void displayList(node* aList){
	node* current = aList;
	while (current != NULL){
		cout << current->data;
		current = current->next;
	}
	cout << endl;
}

struct TNode {
  TNode(int data = 0, TNode *left = NULL, TNode *right = NULL)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
  if (!root){
		return INT_MIN;
	}
	int left = max(root->left);
	int right = max(root->right);
	if (root->data > left && root->data > right) {
		return root->data;
	}
	else if (left >= right) { 
		return left;
	}
	else {
		return right;
	}
}

int cstringSum(char* f) {
	if (!(*f))
		return 0;
	else
		return int(*f) + cstringSum(f + 1);
}

int binSearch(char* k, char target) {
	int middle = strlen(k) / 2;
	if (target > k[middle]) {
		cout << target << ": is greater than: " << k[middle] << endl;
		return binSearch(k + middle, target);
		return 0;
	}
	else if (target == k[middle]) {
		cout << target << ": is equal to : " << k[middle] << endl;
		return middle;
	}
	else {
		cout << target << ": is less than: " << k[middle] << endl;
		k[middle] = 0;
		return binSearch(k, target);
	}
}

int main() {
	int x = 32;
	inBinary(x);
	cout << endl;

	node Alist, node1, node2;
	Alist.data = 4;
	node1.data = 5;
	Alist.next = &node1;
	node2.data = 6;
	node1.next = &node2;
	node2.next = NULL;
	node Blist, node4, node5;
	Blist.data = 1;
	node4.data = 2;
	Blist.next = &node4;
	node5.data = 3;
	node4.next = &node5;
	node5.next = NULL;
	//displayList(&Alist);
	//displayList(&Blist);
	node* sumList = sumOfLists(&Alist, &Blist);
	displayList(sumList);

	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
  	cout << max(&f) << endl;

  	char cString[] = "Test Code"; 
  	cout << cstringSum(cString) << endl;

  	char aString[] = "abcdefghijklmnopqrstuvwxyz";
  	cout << binSearch(aString, 'd') << endl;	
}