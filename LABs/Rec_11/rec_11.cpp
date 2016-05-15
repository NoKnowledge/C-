//Jimmy Lauchoy
//CS1124
//Rec 11

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

/*Node* find(Node* targetNode, int nodeData) {
    while (targetNode != NULL) {
        if (targetNode->data == nodeData) {
            return targetNode;
        }
        targetNode = targetNode->link;
    }
    return NULL;
}*/
Node* findMatch(Node* targetNode, Node* insertNode) {
	Node* tempHeadPtr = NULL;
    Node* tempinsertNode = insertNode;
    Node* location = /*find(targetNode, insertNode->data)*/ targetNode;
    while (location != NULL) {
        //if (location->data == tempinsertNode->data) 
        {
            tempHeadPtr = location;
            bool entered = false;
            while (location != NULL && tempinsertNode!= NULL && location->data == tempinsertNode->data) 
            {
                //if (location->link != NULL) 
                {
                    location = location->link;
                    tempinsertNode = tempinsertNode->link;
         			entered = true;
                }
                //else 
                {
                    //return NULL;
                }
            }
            if (tempinsertNode == NULL && entered) {
                return tempHeadPtr;
            }
        }
        tempinsertNode = insertNode;
        targetNode = /*find(targetNode, insertNode->data)*/ targetNode->link;
        location = targetNode;
    }
    return NULL;
}

int main(){
	cout << "Part One:\n\n";
	cout << "L1: ";
	Node five, seven, nine, one;
	five.data = 5;
	seven.data = 7;
	nine.data = 9;
	one.data = 1;
	five.link = &seven;
	seven.link = &nine;
	nine.link = &one;
	displayList(&five);
	cout << "\nL2: ";
	Node six, three, two;
	six.data = 6;
	three.data = 3;
	two.data = 2;
	six.link = &three;
	three.link = &two;
	displayList(&six);
	cout << "\nSplicing L2 at target in L1\n";
	splice(&seven, &six);
	cout << "L1: ";
	displayList(&five);
	cout << "\nL2: ";
	displayList(&six); 
	cout << "\n===========================================" << endl;
	cout << "Part Two: \n\n";
	cout << "Target: ";
	//1 2 3 2 3 2 4 5 6
	Node juan, dos, tres, due, tre, second, quatro, cinque, sei;
	juan.data = 1;
	dos.data = 2;
	tres.data = 3;
	due.data = 2;
	tre.data = 3;
	second.data = 2;
	quatro.data = 4;
	cinque.data = 5;
	sei.data = 6;
	juan.link = &dos;
	dos.link = &tres;
	tres.link = &due;
	due.link = &tre;
	tre.link = &second;
	second.link = &quatro;
	quatro.link = &cinque;
	cinque.link = &sei;
	displayList(&juan);
	cout << "\nAttempt match: 1\n";
	Node wan;
	wan.data = 1;
	//findMatch(&juan, &wan);
	if (findMatch(&juan, &wan) != NULL) {
        displayList(findMatch(&juan, &wan));
    }
    else {
        cout << "Failed to match";
    }
	cout << "\n";
	cout << "Attempt match: 3 9\n";
	Node treis, nove;
	treis.data = 3;
	nove.data = 9;
	treis.link = &nove;
	//findMatch(&juan, &treis);
	if (findMatch(&juan, &treis) != NULL) {
        displayList(findMatch(&juan, &treis));
    }
    else {
        cout << "Failed to match";
    }
	cout << "\n";
	cout << "Attempt match: 2 3\n";
	Node deux, trois;
	deux.data = 2;
	trois.data = 3;
	deux.link = &trois;
	//AttemptMatch(Node* targetNode, Node* insertNode)
	//findMatch(&juan, &deux);
	if (findMatch(&juan, &deux) != NULL) {
        displayList(findMatch(&juan, &deux));
    }
    else {
        cout << "Failed to match";
    }
	cout << "\n";
	cout << "Attempt match: 2 4 5 6\n";
	Node dva, quatre, cinq, seis;
	dva.data = 2;
	quatre.data = 4;
	cinq.data = 5;
	seis.data = 6;
	dva.link = &quatre;
	quatre.link = &cinq;
	cinq.link = &seis;
	//AttemptMatch(Node* targetNode, Node* insertNode)
	//findMatch(&juan, &dva);
	if (findMatch(&juan, &dva) != NULL) {
        displayList(findMatch(&juan, &dva));
    }
    else {
        cout << "Failed to match";
    }
	cout << "\n";
	cout << "Attempt match: 2 3 2 4\n";
	Node twee, drie, duo, vier;
	twee.data = 2;
	drie.data = 3;
	duo.data = 2;
	vier.data = 4;
	twee.link = &drie;
	drie.link = &duo;
	duo.link = &vier;
	//AttemptMatch(Node* targetNode, Node* insertNode)
	findMatch(&juan, &twee);
	if (findMatch(&juan, &twee) != NULL) {
        displayList(findMatch(&juan, &twee));
    }
    else {
        cout << "Failed to match";
    }
	cout << "\n";
	cout << "Attempt match: 5 6 7\n";
	Node wu, liu, qi;
	wu.data = 5;
	liu.data = 6;
	qi.data = 7;
	wu.link = &liu;
	liu.link = &qi;
	findMatch(&juan, &wu);
	if (findMatch(&juan, &wu) != NULL) {
        displayList(findMatch(&juan, &wu));
    }
    else {
        cout << "Failed to match" << endl;
    }
}