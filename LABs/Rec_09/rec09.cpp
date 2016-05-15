/*
 Recitation 09
 CS1124
 Jimmy Lauchoy
 
 Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary)
    : title(aTitle), salary(aSalary) {}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
private:
    string title;
    double salary;
};

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition)
    : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    }
    friend ostream& operator<<( ostream& os, const Entry& e ) {
        os << e.name << '\n'
        << e.room << '\n'
        << e.phone;
        return os;
    }
    string getName(){
        return name;
    }
    unsigned getPhone(){
        return phone;
    }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // Entry

class Directory {
public:
    Directory()
    : capacity(2), size(0), entries(new Entry*[2] )
    {
        for (size_t i = 0; i < capacity; i++) {
            entries[i] = NULL;
        }
    }
     //destructor
    ~Directory() {
        for (size_t i = 0; i < size; i++){
            delete entries[i];
        }
        delete [] entries;
    } 
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if( size == capacity )  {
            cout<<"Increasing capacity to double" << endl;
            Entry** oldEntries = entries;
            entries = new Entry*[ capacity *= 2 ];
            for (size_t i = 0; i < size; i++){
                entries[i] = oldEntries[i]; 
            }
        }
        entries[size++] = new Entry(name, room, ph, pos);
    }
    //assignment operator
    Directory& operator= (const Directory& rhs){ 
        if (this != &rhs){
            for (size_t i = 0; i < size; i++){
                delete entries[i];
            }
            delete[] entries;  
            size = rhs.size;
            capacity = rhs.capacity;  
            entries = new Entry*[capacity];
            for (int i = 0; i < size; i++){
                entries[i] = new Entry(*rhs.entries[i]);
            }
        }
        return *this;
    }
    //copy constructor
    Directory(const Directory& rhs): capacity(rhs.capacity), size(rhs.size) {
        entries = new Entry*[capacity]; 
        for(size_t i = 0; i < size; i++){
            entries[i] = rhs.entries[i];
        }
    }
    friend ostream& operator<<(ostream& os, const Directory& aDirectory){
        for (size_t i = 0; i < aDirectory.size; i++){
            os << *aDirectory.entries[i] << endl;
        }
        return os;
    }
    unsigned operator[](const string& name){
        for (size_t i = 0; i < size; i++){
            if (entries[i]->getName() == name){
                return entries[i]->getPhone();
            }
        }
        return 0;
    }
private:
    Entry** entries;
    size_t size;
    size_t capacity;
};

int main() {
    
    // Model as if there are these four kinds
    // of position in the problem:
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // 
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    //d.add("John", 321, 7654, boss);
    //d.add("Bob", 234, 9876, boss);
    cout << d << endl;
    Directory d2 = d;	// What function is being used.
    d2.add("Gallagher", 111, 2222, techie);
    cout << d2 << endl;
    Directory d3;
    d3 = d2;
    cout << d3 << endl;

    cout << d3["Marilyn"];
}
