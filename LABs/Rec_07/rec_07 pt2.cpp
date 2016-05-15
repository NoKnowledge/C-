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
  virtual void playSound() const = 0;
};

void Instrument::playSound() const {
    cout << "To make a sound... ";
  }

class Brass : public Instrument {
public:
  Brass(unsigned size): size(size){}
  void playSound() const{
    Instrument::playSound();
    cout << "blow on a mouthpiece of size " << size << endl;
  }
private:
  unsigned size;
};

class String : public Instrument {
public:
  String(unsigned pitch): pitch(pitch){}
  void playSound() const{
    Instrument::playSound();
    cout << "bow a string with pitch " << pitch << endl;
  }
private:
  unsigned pitch;
};
class Percussion : public Instrument {
public:
  Percussion(){}
  void playSound() const{
    Instrument::playSound(); 
    cout << "hit me!" << endl;
  }
};

class Trombone: public Brass {
public:
    Trombone(unsigned size): Brass(size) {}  
    void playSound() const {
      cout << "Blat ";
    } 
};

class Trumpet: public Brass {
public:
    Trumpet(unsigned size): Brass(size) {}
    void playSound() const {
        cout << "Toot ";
    }
};

class Violin : public String {
public:
    Violin(unsigned pitch): String(pitch) {}
    void playSound() const {
        cout << "Screech ";
    }
};

class Cello : public String {
public:
    Cello(unsigned pitch): String(pitch) {}
    void playSound() const {
        cout << "Squawk ";
    }
};

class Drum : public Percussion {
public:
  Drum(){}
  void playSound() const {
        cout << "Boom ";
    }
};

class Cymbal : public Percussion {
public:
  Cymbal(){}
  void playSound() const {
        cout << "Crash ";
    }
};


class MILL{
public:
  void receiveInstr(Instrument& instr) {
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
        inventory[i]->playSound();
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
			instr->playSound();
	}
private:
	Instrument* instr;
};

class Orch {
public:
    void addPlayer(Musician& musician) {
        if (musicians.size() < 25) {
            musicians.push_back(&musician);
        }
        else {
            cout << "Orchestra is full!" << endl;
        }
    }
    void play() {
        for (size_t i = 0; i < musicians.size(); ++i) {
            musicians[i] -> testPlay();
        }
        cout << endl;
        
    }
private:
    vector<Musician*> musicians;
};

// PART TWO
int main()
{
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone( 4 );
    Trumpet trpt( 12 ) ;
    Violin violin( 567 ) ;
    
    MILL mill;
    mill.receiveInstr( trpt );
    mill.receiveInstr( violin );
    mill.receiveInstr( tbone );
    mill.receiveInstr( drum );
    mill.receiveInstr( cello );
    mill.receiveInstr( cymbal );
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr( *mill.loanOut() );
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr( *mill.loanOut() );
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr( *mill.loanOut() );
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr( *ralph.giveBackInstr() );
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr( *mill.loanOut() );
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr( *mill.loanOut() );
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr( *mill.loanOut() );
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr( *mill.loanOut() );
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    return 0;
    
} // main


