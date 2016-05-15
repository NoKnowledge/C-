//Jimmy Lauchoy
//CS1124
//Rec 12

#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

class Sequence {
private:
	Node* head;
	Node* current;
public:
	Sequence():head(NULL), current(NULL) {}
	//destructor
	~Sequence() {
		Node* headPtr = head;
		while (headPtr) {
			Node* temp = headPtr;
			headPtr = headPtr->link;
			delete temp;
			temp = NULL;
		}
		head = NULL;
		current = NULL;
		delete head;
		delete current;
		cout << "calling destructor" << endl;
	}
	Node* getHead() const{
		return head;
	}
	int getCurrent() const{
		return current->data;
	}
	//copy constructor
	Sequence(const Sequence& rhs){
		if (rhs.getHead()) {
			head = new Node;
			*head = *rhs.getHead();
		}
	}
	//assignment operator
	Sequence& operator = (Sequence& rhs){
		rhs.reset();
		int i = 0;
		while (rhs.next()){
			i++;
		}
		head = current = new Node;
		current->link = new Node;
		for (int t = 0; t < i; t++){
			current->link = new Node;
			current = current->link;
		}
		reset();
		rhs.reset();
		while (current != NULL){
			current->data = rhs.getCurrent();
			next();
			rhs.next();
		}
		return *this;
	}
	void add(int number){
		if (head == NULL && current == NULL){
			Node* node = new Node;
			node->data = number;
			current = head = node;
		}
		else{
			Node* node = new Node;
			node->data = number;
			node->link = current->link;
			current->link = node;
			current = current->link;
		}
	}
	void display(){
		const Node* nodePtr = head;
		while(nodePtr != NULL){
			cout << nodePtr->data << " ";
			nodePtr = nodePtr->link;
		}
		cout << endl;
	}
	void reset(){
		current = head;
	}
	void remove(){
		Node* nodePtr = head;
		if (current != NULL){
			while(nodePtr->link != current){
				nodePtr = nodePtr->link;
		}
		nodePtr->link = current->link;
		delete current;
		current = nodePtr->link ;
		}
	}
	Node* next(){
		current = current->link;
		return current;
	}
	void clear(){
		Node* nodePtr = head;
		while(nodePtr->link != NULL){
			Node* temp = nodePtr;
			nodePtr = nodePtr->link;
			delete temp;
			temp = nodePtr;
		}
		head = NULL;
		current = NULL;
	}
};

int main(){
  Sequence s;
  for (int i = 0; i < 6; ++i) s.add(i);
  s.display();
  cout << "==========\n";
  s.reset();
  for (int i = 0; i < 3; ++i) s.next();
  s.add(42);
  s.display();
  cout << "==========\n";
  s.reset();
  for (int i = 0; i < 2; ++i) s.next();
  s.remove();
  s.display();
  cout << "==========\n";
  s.clear();
  s.display();
  cout << "==========\n";
}
