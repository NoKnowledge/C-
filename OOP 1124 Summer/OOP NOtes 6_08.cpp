//Jimmy Lauchoy
//CS1124 Summer

struct Person{
	string name;
	Person* spouse;
};

void resizeArray(int* arr, int currentSize, int newSize){
	int toCopy;
	if(newSize < currentSize){
		toCopy = newSize;
	}
	else{
		toCopy = currentSize;
	}
	int* temp = new int[newSize];
	for(int i = 0; i < toCopy; i++){
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp; 
	temp = nullptr; //kind of pointless
}


int main(){
	int arr[10];
	int x = 100;
	int* ptr;

	cout << "How many things? ";
	int count;
	cin >> count;
	//int arr2[count]; //illegal
	ptr = new int[count];
	for(int i = 0; i < count; i++){
		ptr[i] = i * 10;
	}
	delete[] ptr;//remember the [] when its an array

	int size = 10;
	int *arr = new int[size];
	for(int i = 0; i < size; i++){
		arr[i] = i * 10;
	}
	int newSize = size * 2;
	resizeArray(arr, size, newSize);
	size = newSize;
}