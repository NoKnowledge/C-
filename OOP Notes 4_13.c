Node* listFindEnd(Node* headPtr){
	if (headPtr == NULL){
		return NULL;
	}
	Node* p = headPtr;
	while (p->next != NULL){
		p = p->next;
	}
	return p;
}

void listAddToEnd(Node*& headPtr, int data){ //pass by reference
	if(headPtr == NULL){
		headPtr = new Node(data);
	}
	Node* theEnd = listFindEnd(headPtr);
	theEnd->next = new Node(data);
}
void listAddHead(Node*& headPtr, int data){
	//1. create the node
	//Node* p = new Node(data, headPtr);
	headPtr = new Node(data, headPtr);

	//Node* p = new Node(data);
	//2. make that node point to the old first node
	//p->next = headPtr;
	//3. make the head pointer point to the new node
	headPtr = p;

//prior is not premitted to be null
void listAdd(Node* prior, int data){
		prior->next = new Node(data, prior->next);
	}
}
void listRemove(Node* prior){
	Node* theOneAfter - prior->next->next;
	delete prior->next;
	prior->next = theOneAfter;
}
void listRemoveEnd(Node* prior){
	
}
int main(){
	Node* list = NULL; //empty list
	listAddToEnd(list, 17); //list contains single node
	listAddToEnd(list, 42); //now it has two
	listDsplay(list);
}