void towers(int n, char start, char target, char space){
	if (n == 0){
	return;
	towers(n-1, start, space,target);
	cout << "move " << n << "from" << start << "to" << target << endl;
	towers(n-1,space,target,start);
	}

}

void foo(int a){
	if (n > 1){
		cout << 'a';
		foo(n/2);
		cout << 'b';
		foo(n/2);
	}
	cout << 'c';
}

//input and output
foo(5)
//foo (5) prints out a
//calls foo(2)
//prints out acbcc
//prints out b
//calls foo(1)
//prints out acbcc
//prints out c

int maxB(TN* root){
	if(root == nullptr) return 0;
	int left = maxB(root->left);
	int right = maxB(root->right);
	return root->data + max(left,right); //returns the largest of left and right
}

//cookie jar problem from midterm 2
//1. check for self-assignment
//2. free up : loop through array to get rid of cookies, 
//   then get rid of array (delete square bracket)
//	 if the cookies are only objects, you can just delete. 
//in our case we have cookie pointers so we need to get rid of them
//individually before we can delte the array.
//3. allocate + copy
//	 create new array in "cookie" jar B and copy what was in A 
//	 into jar B 
//4. return dereference of this (return *this)

CookieJar& operator = (const CookieJar& rhs){
	if(this != &rhs){
		for(int i = 0; i < data.size(); i++){
			delete data[i];
		}
		delete [] data;
		//allocate another array
		data = new Cookie*[rhs.size()]
		int size = rhs.size();
		for(int i = 0; i < data.size(); i++){
			data[i] = new Cookie(*rhs.data[i]) //uses cookie's copy constructor
		}
	}
}

//destructor
//performs what you coded it to do
//non-primitive member variable destructor
//calls destructor from base class

void addLast (Node* &hp, int data){
	if(hp == nullptr){
		hp = new Node(data);
	}
	else{
		Node* last = hp;
		while (last->next != nullptr){
			last = last->next;
		}
		last->next = new Node(data);
	}
}

//delete a linked list
void clear(Node* &hp){
	while (hp != nullptr){
		Node* current = hp;
		hp = hp->next;
		delete current;
	}
}

//delete linked list with recursion
void clear(Node* &hp){
	if(hp == nullptr){
		return;
	}
	clear(hp->next);
	delete hp;
	hp = nullptr;
	}
}

	

