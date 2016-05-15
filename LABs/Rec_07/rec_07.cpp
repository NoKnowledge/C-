//Jimmy Lauchoy
//CS1124
//Rec 07

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Instrument {
public:
  Instrument(){}
  virtual void makeSound() const = 0;
};

void Instrument::makeSound() const {
    cout << "To make a sound... ";
  }

class Brass : public Instrument {
public:
  Brass(unsigned size): size(size){}
  void makeSound() const{
    Instrument::makeSound();
    cout << "blow on a mouthpiece of size " << size << endl;
  }
private:
  unsigned size;
};

class String : public Instrument {
public:
  String(unsigned pitch): pitch(pitch){}
  void makeSound() const{
    Instrument::makeSound();
    cout << "bow a string with pitch " << pitch << endl;
  }
private:
  unsigned pitch;
};
class Percussion : public Instrument {
public:
  Percussion(){}
  void makeSound() const{
    Instrument::makeSound(); 
    cout << "hit me!" << endl;
  }
};

class Trombone: public Brass {
public:
    Trombone(unsigned size): Brass(size) {}   
};

class Trumpet: public Brass {
public:
    Trumpet(unsigned size): Brass(size) {}
};

class Violin : public String {
public:
    Violin(unsigned pitch): String(pitch) {}
};

class Cello : public String {
public:
    Cello(unsigned pitch): String(pitch) {}
};

class Drum : public Percussion {
public:
  Drum(){}
};

class Cymbal : public Percussion {
public:
  Cymbal(){}
};


class MILL{
public:
  void receiveInstr(Instrument& instr) {
    instr.makeSound();
    if (inventory.size() == 0) {
      inventory.push_back(&instr);
    }
    else {
      for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i] == NULL) {
          inventory[i] = &instr;
          return;
        }
      }
      inventory.push_back(&instr);
      return;
    }
  }

  void dailyTestPlay() {
    for (size_t i = 0; i < inventory.size(); i++) {
      if (inventory[i] != NULL) {
        inventory[i]->makeSound();
      }
    }
  }

  Instrument* loanOut() {
    Instrument* temp;
    for (size_t i = 0; i < inventory.size(); i++){
      if (inventory[i] != NULL) {
        temp = inventory[i];
        inventory[i] = NULL;
        return temp;
      }
    }
    return NULL;
  }
private:
  vector<Instrument*>inventory;
};


class Musician {
public:
	Musician() : instr( NULL ) {}
	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) { 
		Instrument* tmp(instr); 
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if( instr ) 
			instr->makeSound();
		else
			cerr << "have no instr\n";
	}
private:
	Instrument* instr;
};

// PART ONE
int main()
{

   cout << "Define some instruments ----------------------------------------\n";
   Drum drum;
   Cello cello(673);
   Cymbal cymbal;
   Trombone tbone( 4 );
   Trumpet trpt( 12 ) ;
   Violin violin( 567 ) ;
  
    // use the debugger to look at the mill
   cout << "Define the MILL ------------------------------------------------\n";
   MILL mill;
  
   cout << "Put the instruments into the MILL ------------------------------\n";
   mill.receiveInstr( trpt );
   mill.receiveInstr( violin );
   mill.receiveInstr( tbone );
   mill.receiveInstr( drum );
   mill.receiveInstr( cello );
   mill.receiveInstr( cymbal );
  
   cout << "Daily test -----------------------------------------------------\n";
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
   cout << endl;
  
   cout << "Define some Musicians-------------------------------------------\n";
   Musician j;
   Musician jj;
   Musician q;
  	
   cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
   q.testPlay();	
   cout << endl;
   q.acceptInstr( *mill.loanOut() );
   cout << endl;
   q.testPlay();
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
  
   cout << endl << endl;
  
   q.testPlay();	
   cout << endl;
   mill.receiveInstr( *q.giveBackInstr() );
   j.acceptInstr( *mill.loanOut() );
   q.acceptInstr( *mill.loanOut() );
   cout << endl;
   q.testPlay();
   cout << endl;
   j.testPlay();
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
  
   cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
  
   // fifth
   mill.receiveInstr( *q.giveBackInstr() );
   cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
   mill.receiveInstr( *j.giveBackInstr() );
  
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
   cout << endl;
  
   cout << endl;
   
}

