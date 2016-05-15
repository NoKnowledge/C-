//Jimmy Lauchoy
//CS1124
//Rec 08
/*

#include <iostream>
#include <fstream>
#include "registrar.h"

using namespace BrooklynPoly;
using namespace std;

int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    registrar.printReport();
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    registrar.printReport();

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    registrar.printReport();

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    registrar.printReport();

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    registrar.printReport();

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    registrar.printReport();

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    registrar.printReport();
   
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "Purge for start of next semester\n";
    registrar.purge();
    registrar.printReport();
} */

#include <iostream>
#include <fstream>
#include "registrar.h"

using namespace BrooklynPoly;
using namespace std;

void commandAction(const vector<string>& commands, Registrar& registrar);

void readFile(const string& file){
    Registrar registrar;

    ifstream ifs("file_to_read.txt");
    if (!ifs){
        cout << file << " could not be opened." << endl;
    }
    //string line;
    string command;
    vector<string>commands;
    while(ifs>>command){
        cout << command << endl;
        commands.push_back(command);
        commandAction(commands, registrar);
    }
    ifs.close();
}
void commandAction(const vector<string>& commands, Registrar& registrar){
    if(commands.size() == 0){
        cout << "Not a valid command" << endl;
    }
    else if(commands[0] == "PrintReport"& commands.size() == 1){
        cout << registrar << endl;
    }
    else if(commands[0] == "AddCourse" && commands.size() == 2){
        registrar.addCourse(commands[1]);
    }
    else if(commands[0] == "AddStudent" && commands.size() == 2){
        registrar.addStudent(commands[1]);
    }
    else if(commands[0] == "CancelCourse" && commands.size() == 2){
        registrar.cancelCourse(commands[1]);
    }
    else if(commands[0] == "EnrollStudentInCourse" && commands.size() == 3){
        registrar.enrollStudentInCourse(commands[1], commands[2]);
    }
    else if(commands[0] == "Purge" && commands.size() == 2){
        registrar.purge();
    }
}

int main(){
    string file = "C:/Users/Jimmy/Documents/OOP 1124/Lab/Rec_08/file_to_read.txt";
    readFile(file);
}