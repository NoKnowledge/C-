#include <cstdlib> // To allow NULL if no other includes
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);

}
void splice(Node* targetNode, Node* insertNode){
	Node* tempNode = insertNode; //creates temp variable to store node that will be inserted
	while (tempNode->link != NULL){ //tempNode links all nodes 
		tempNode = tempNode->link; //
	}
	tempNode->link = targetNode->link; //the node that the tempNode is linking to is the same as the node that targetNode is linking to
	targetNode->link = insertNode;	//the number that is targeted links to the node that you want to insert	
}

void displayList(Node* headPtr){
	const Node* tempPtr = headPtr;
	while(tempPtr != NULL){
		cout << tempPtr->data << " ";
		tempPtr = tempPtr->link;
	}
}

int main(){
	cout << "Part One:\n\n";
	cout << "L1: ";
	Node five;
	five.data = 5;
	Node seven;
	seven.data = 7;
	five.link = &seven;
	Node nine;
	nine.data = 9;
	seven.link = &nine;
	Node one;
	one.data = 1;
	nine.link = &one;
	displayList(&five);
	cout << "\nL2: ";
	Node six;
	six.data = 6;
	Node three;
	three.data = 3;
	six.link = &three;
	Node two;
	two.data = 2;
	three.link = &two;
	displayList(&six);
	cout << "\nSplicing L2 at target in L1\n";
	splice(&seven, &six);
	cout << "L1: ";
	displayList(&five);
	cout << "\nL2: ";
	displayList(&six); 
}