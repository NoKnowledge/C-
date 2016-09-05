//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>

using namespace std;


struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

void listInsertEnd(int entry, Node*& headPtr) {
	Node* insertNode = new Node(entry);
	if (headPtr->next == nullptr) {
		headPtr->next = insertNode;
	}
	else {
		Node* end = headPtr;
		while (end->next != nullptr) {
			end = end->next;
		}
		end->next = insertNode;
	}
}


Node* createList(Node*& headPtr) {
	int newdata;
	char exit;
	cout << "Enter data: ";
	cin >> newdata;
	headPtr = new Node(newdata);
	cout << "Would you like to enter new data? Y/N: ";
	cin >> exit;
	while (exit == 'y' || exit == 'Y') {
		cout << "Enter data: ";
		cin >> newdata;
		listInsertEnd(newdata, headPtr);
		cout << "Would you like to enter new data? Y/N: ";
		cin >> exit;
	}
	if (exit == 'n' || exit == 'N') {
		return headPtr;
	}
	else {
		cout << "Could not process command, please try again" << endl;
	}
}


void displayList(Node* headPtr) {
	const Node* temp = headPtr;
	cout << "Displaying linked list:" << endl;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


int find(Node* headPtr, int data) {
	cout << "Looking for number:" << data << endl;
	int position = 0; 
	while (headPtr != nullptr) {
		if (headPtr->data == data) {
			return position;
		}
		position++;
		headPtr = headPtr->next;
	}
	cout << "Number not found." << endl;
	return 0;
}


int lastElement(Node* headPtr) {
	while (headPtr->next != nullptr) {
		headPtr = headPtr->next;
	}
	return headPtr->data;
}


Node* appendList(Node*& list1, Node*& list2) {
	if (list1 == nullptr) {
		list1 = list2;
		return list1;
	}
	else {
		Node* end = list1;
		while (end->next != nullptr) {
			end = end->next;
		}
		end->next = list2;
		return end;
	}
}

int main() {
	Node* headNode = new Node;
	createList(headNode);
	displayList(headNode);
	cout << "Position: " << find(headNode, 1) << endl;
	cout << "Last Element: " << lastElement(headNode) << endl;
	Node* headNode2 = new Node;
	createList(headNode2);
	displayList(headNode2);
	appendList(headNode, headNode2);
	displayList(headNode);
}
