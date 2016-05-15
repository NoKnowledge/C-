/* Jimmy Lauchoy
	CS 1124
	Rec 06
	*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned num_pages): number_of_pages(num_pages){}
	virtual void display_num_pages() const = 0; 

protected: 
private:
	unsigned number_of_pages;
};

void PrintedMaterial::display_num_pages() const {
		cout << number_of_pages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned num_pages): PrintedMaterial(num_pages){}

	void display_num_pages() const {
		PrintedMaterial::display_num_pages();
		cout << "I'm a magazine!\n";
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned num_pages): PrintedMaterial(num_pages){}
protected:
private:
};

class TextBook : public Book {
public:
	//Textbook(unsigned num_pages): PrintedMaterial(num_pages){}
	TextBook(unsigned num_pages, unsigned num_index): Book(num_pages), num_of_index_pages(num_index){}
	void display_num_pages() const{
		cout << "\nThis is Textbook\n";
		cout << "Pages: ";
		PrintedMaterial::display_num_pages();
		cout << "Index pages: "; 
		cout << num_of_index_pages << endl;	
	}
protected:
private:
	unsigned num_of_index_pages;
};

class Novel : public Book {
public:
	Novel(unsigned num_pages): Book(num_pages) {}

	void display_num_pages() const{
		cout << "\nChapter 1: A novel\n";
		PrintedMaterial::display_num_pages();
	}
protected:
private:
};

void display_number_of_pages(const PrintedMaterial& a_printed_material) {
	a_printed_material.display_num_pages();
	}

// tester/modeler code
int main()
{
	TextBook t(1738, 25);
	Novel n(512);
	Magazine m(16);

	t.display_num_pages();
	n.display_num_pages();
	m.display_num_pages();

	/*cout << "\nA PrintedMaterial material object\n";
	PrintedMaterial printed_material(8763);
	printed_material.display_num_pages();

	cout << "\nA PrintedMaterial variable containing a TextBook value\n";
	PrintedMaterial pm = t;
	pm.display_num_pages();
	*/
	cout << "\nA PrintedMaterial pointer containing a TextBook value\n";
	PrintedMaterial* pm_pointer;
	pm_pointer = &t;
	pm_pointer -> display_num_pages();

	cout << "\nUse the new function\n";
	display_number_of_pages(m);
	display_number_of_pages(n);
	display_number_of_pages(t);

	cout << "\nUse a vector\n";
	vector<PrintedMaterial*> all_print_material;
	all_print_material.push_back(&t);
	all_print_material.push_back(&n);
	all_print_material.push_back(&m);
	for(size_t i = 0; i < all_print_material.size(); i++) {
		all_print_material[i]->display_num_pages();
		cout << endl;
	}
}
