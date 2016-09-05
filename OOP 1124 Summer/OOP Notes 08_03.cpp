//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

template <class T>
class LList;

template <class T>
class LListNode{
	T data;
	LListNode<T>* next;
public:
	LListNode(T newdata = t(), LListNode<T>* newNext = nullptr):
	data(newdata), next(newNext){}
	friend class LList <T>;
};

template <class T>
class LList{
	LListNode<T>* head;
public:
	LList(): head(nullptr){}
	~LList(){clear();}
	LList(const LList& rhs): head(nullptr){*this = rhs;}
	LListNode recursiveCopy(LListNode* rhs);
	LLis& operator = (const LList& rhs);
	void insertAtHead(T newdata);
	void insertAtEnd(T newdata);
	void insertAtPoint(LListNode<T>* ptr, T newdata);
	T removeFromHead();
	int size() const;
	void clear();
	bool isEmpty() const{return head == nullptr};
};
template <class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs){
	if (rhs = nullptr){
		return nullptr;
	}
	return new LListNode<T>(rhs->data, recursiveCopy(rhs->next));
	/*
	LListNode<T>* temp = new LListNode<T>(rhs->data);
	temp->next = recursiveCopy(rhs->next);
	return temp;
	*/
	return *this;
}
template <class T> 
LList<T>& LList<T>::operator = (const LList<T>& rhs){
	if (this == &rhs){
		returh *this;
	}
	clear();
	head = recursiveCopy(rhs.head);
}
template <class T>
void LList<T>::insertAtHead(T newdata){
	LListNode<T>* temp = new LListNode<T>(newdata);
	temp->next =  head;
	head = temp;
}

template <class T>
T LList<T>::removeFromHead(){
	T retval = head->data;
	LListNode<T>* temp = head;
	head = head->next;
	delete temp;
	return retval;
}

template <class T>
void LList<T>::clear(){
	while(!isEmpty()){
		removeFromHead();
	}
}

template <class T>
void LList<T>::insertAtEnd(T newdata){
	if (isEmpty()){
		insertAtHead(newdata);
		return;
	}
	LListNode<T>* temp = new LListNode<T>(newdata);
	LListNode<T>* end = head;
	while(end->next != nullptr){
		end = end->next;
	}
	end->next = temp;
}

template <class T>
void LList<T>::insertAtPoint(LListNode<T>* ptr, T newdata){
	LListNode<T>* temp = new LListNode<T>(newdata);
	temp->next = ptr->next;
	ptr->next = temp;
}

template <class T>
int LList<T>::size() const{
	int count = 0;
	LListNode<T>* temp = head;
	while(temp != nullptr){
		count++;
		temp = temp->next;
	}
	return count;
}

void func(){
	LList<int> l;
	for(int i = 0; i < 5; i++){
		l.insertAtHead(i);
	}
}

int main(){
	for(int i = 0; i < 10; i++){
		func();
	}
}