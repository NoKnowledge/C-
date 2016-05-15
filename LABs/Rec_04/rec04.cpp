#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Complex {
	   double real;
	   double img;
};

class PlainOldClass {  
	public:
	   PlainOldClass() : x(-72) {}
	   int getX() const { return x; }
	   void setX( int x )  { this->x = x; } // No confusion!
	private:
	   int x;
	};

class Colour {  
public:       
    Colour( const string& name, unsigned r, unsigned g, unsigned b )       
        : name(name), r(r), g(g), b(b) {}       
    void display() const { 
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")"; 
    }   
private:       
    string   name;    // what we call this colour       
    unsigned r, g, b; // red/green/blue values for displaying  
};         

class SpeakerSystem {
   public:
   void vibrateSpeakerCones( unsigned signal ) const {

      cout << "Playing: " << signal << "Hz sound..." << endl;
      cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};

class Amplifier {
public:
   void attachSpeakers( SpeakerSystem& spkrs )
   {
      if( attachedSpeakers )
         cout << "already have speakers attached!\n";
      else
         attachedSpeakers = &spkrs;
   }
   void detachSpeakers() 
   { attachedSpeakers = NULL; }
     // should there be an "error" message if not attached?
   void playMusic( ) const {
      if( attachedSpeakers )
         attachedSpeakers -> vibrateSpeakerCones( 440 ); 
      else
         cout << "No speakers attached\n"; 
   }
private:
   SpeakerSystem* attachedSpeakers;
};

class Person {  
public:       
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        roomie = &newRoomate;        // now I have a new roomie            
        newRoomate.roomie = this;    // and now they do too       
    }       
    string getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    string getRoomiesName() const { return roomie->getName(); }  
private:
    Person* roomie;       
    string name;  
};           


int main() {
	cout << "Jimmy Lauchoy\n" << "CS1124\n" <<
	"Section B\n" << "jl7263" << endl;

	int x;
	x = 10;
	cout << "x = " << x << endl;

	int* p;
	p = &x;
	cout << "p = " << p << endl;

	//p = 0x246fdc0; //using the value from my Watch window

	cout << "p points to where " << *p << " is stored\n";  
	cout << "*p contains " << *p << endl;     

	*p = -2763;  
	cout << "p points to where " << *p << " is stored\n";  
	cout << "*p now contains " << *p << endl;  
	cout << "x now contains " << x << endl;

	int y(13);      
	cout << "y contains " << y << endl;      
	p = &y;      
	cout << "p now points to where " << *p << " is stored\n";      
	cout << "*p now contains " << *p << endl;      
	*p = 980;      
	cout << "p points to where " << *p << " is stored\n";      
	cout << "*p now contains " << *p << endl;      
	cout << "y now contains " << y << endl;

	int* q;      
	q = p;      
	cout << "q points to where " << *q << " is stored\n";      
	cout << "*q contains " << *q << endl;

	double d(33.44);      
	double* pD(&d);      
	*pD = *p;      
	*pD = 73.2343;      
	//*p  = *pD;      
	*q  = *p;      
	//pD  = p;
	//p   = pD;

	int joe( 24 );  
	const int sal( 19 );    
	int*  pI;  
	  pI = &joe;  
	// *pI = 234;  
	//  pI = &sal;  
	 *pI = 7623;    

	const int* pcI;
	  pcI = &joe;  
	// *pcI = 234;  
	  pcI = &sal;  
	// *pcI = 7623;    

	//int* const cpI;
	int* const cpI(&joe);
	//int* const cpI(&sal);
	//  cpI = &joe;  
	 *cpI = 234;  
	//  cpI = &sal;  
	 *cpI = 7623;    

	//const int* const cpcI;
	const int* const cpcI(&joe);
	//const int* const cpcI(&sal);
	//  cpcI = &joe;  // *cpcI = 234;  
	//  cpcI = &sal;  
	// *cpcI = 7623;  

	
	Complex c = {11.23,45.67};      
	Complex* pC(&c);

	//cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
	//cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
	cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;

	PlainOldClass poc;
	PlainOldClass* ppoc( &poc );
	cout << ppoc -> getX() << endl;
	ppoc -> setX( 2837 );
	cout << ppoc -> getX() << endl;

	int* pDyn = new int(3); // p points to an int initialized to 3 on the heap      
	*pDyn = 17;

	cout << pDyn << endl;  
	delete pDyn;  
	pDyn = NULL;
	cout << pDyn << endl;
	double* pDouble( NULL );

	//cout << "Can we dereference NULL?  " << *pDyn << endl;      
	//cout << "Can we dereference NULL?  " << *pDouble << endl;



	double* pTest = new double( 12 );      
	delete pTest;      
	pTest = NULL;      
	delete pTest; // safe

	short* pShrt = new short( 5 );      
	delete pShrt;      
	//delete pShrt;

	long jumper( 12238743 );      
	//delete jumper;
	long* ptrTolong( &jumper );      
	//delete ptrTolong;        
	Complex cmplx;      
	//delete cmplx; 

	vector<Complex*> complV; // can hold pointers to Complex objects
	Complex* tmpPCmplx;      // space for a Complex pointer
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
	   tmpPCmplx = new Complex; // create a new Complex object on the heap
	   tmpPCmplx->real = ndx;   // set real and img to be the
	   tmpPCmplx->img  = ndx;   // value of the current ndx
	   complV.push_back( tmpPCmplx ); // store the ADDRESS of the object in a vector or pointer to Complex
	}     
	// display the objects using the pointers stored in the vector
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
	    cout << complV[ ndx ]->real << endl;         
	    cout << complV[ ndx ]->img  << endl;      
	}      
	// release the heap space pointed at by the pointers in the vector      
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
	    delete complV[ ndx ];      
	}      
	// clear the vector      
	complV.clear();  

	vector< Colour* > colours;         
	string inputName;       
	unsigned inputR, inputG, inputB;
	// fill vector with Colours from the file    
	// this could be from an actual file but here we are using the keyboard instead of a file
	//(so we don't have to create an actual file)
	// do you remember the keystroke combination to indicate "end of file" at the keyboard?
	// somehow the while's test has to fail - from keyboard input
	
	cout << "TESTttttt" << endl;

	
	/*
	while ( cin >> inputName >> inputR >> inputG >> inputB ) {            
	    colours.push_back( new Colour(inputName, inputR, inputG, inputB) );       
	}
	*/         

	// display all the Colours in the vector:       
	for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {            
	    colours[ndx]->display();            
	    cout << endl;       
	}

	SpeakerSystem someSpeaker;
	Amplifier someAmp;	
	someAmp.attachSpeakers(someSpeaker);
	someAmp.playMusic();

	// write code to model two people in this world       
	Person joeBob("Joe Bob"), billyJane("Billy Jane");         
	// now model these two becoming roommates       
	joeBob.movesInWith( billyJane );         
	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;

}



