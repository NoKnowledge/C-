//Jimmy Lauchoy
//CS 1122
//Rec 05

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//email to TA: rsr379@nyu.edu
using namespace std;

class StudentRecord{
public:
   StudentRecord(const string student_name) : name(student_name), grades(13,-1) {}
   //methods
   void displayGrade() const {
      cout << "Student: " << name << " , Grades: ";
      for (size_t index = 0; index < grades.size(); index++) {
         cout << grades[index] << " ";
      }
      cout << endl;
   }

   void addGrade(int grade, int week) {
      grades[week] = grade;
   }

   string getName() const{
      return name;
   }
private:
   string name;
   vector<int> grades; 

};

class TimeSlot{ 

public:
   TimeSlot(string date, int time) : date(date), time(time) {}
   
   void displayTime() const {
      if (time >= 12) {
         cout << date << ", " << time % 12 << " PM" << endl;
      }
      else {
         cout << date << ", " << time << " AM" << endl;
      }
   }
private:
   string date;
   int time;
};

class Section{
   
public:
   Section(string name, string date, int time): student_name(name), aTime(date, time) {}

   reset() {
      for (size_t i = 0; i < gradebook.size(); i++){
         delete gradebook[i];
      }
      gradebook.clear();
   }

   addStudent(string studentName) {
      StudentRecord* student = new StudentRecord(studentName);
      gradebook.push_back(student);
   }

   void display() const {
      cout << "Section: " << student_name << "; ";
      aTime.displayTime();
      for (size_t index = 0; index < gradebook.size(); index++) {
         gradebook[index] -> displayGrade();
      }
      cout << endl;
   }

   void addGrades(string name, int grade, int week) {
      for (int i = 0; i < gradebook.size(); i++) {
         if (gradebook[i]-> getName() == name) {
            gradebook[i]-> addGrade(grade, week);
         }
      }
   }


private:
   vector<StudentRecord*> gradebook;
   string student_name;
   TimeSlot aTime;

};

class LabWorker{
public:
   LabWorker(string newName): worker_name(newName){}

   void displayGrades() {
      cout << worker_name << " has ";
      section -> display();
      cout << endl; 
   }
   
   // sections and setup and testing
   void addSection(Section& aSection) {
      section = &aSection;
   }

   void addGrade(string name, int grade, int week) {
      section->addGrades(name,grade,week);
   }

private:
   string worker_name;
   Section* section;
};

int main() {
   //lab workers
   LabWorker moe( "Moe" );
   LabWorker jane( "Jane" );

   Section secA2( "A2", "Tuesday", 16 );
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.addStudent("John");
   secA2.addStudent("George");
   secA2.addStudent("Paul");
   secA2.addStudent("Ringo");

   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.addSection( secA2 );
   moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
  
   Section secB3( "B3", "Thursday", 11 );
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.addStudent("Thorin");
   secB3.addStudent("Dwalin");
   secB3.addStudent("Balin");
   secB3.addStudent("Kili");
   secB3.addStudent("Fili");
   secB3.addStudent("Dori");
   secB3.addStudent("Nori");
   secB3.addStudent("Ori");
   secB3.addStudent("Oin");
   secB3.addStudent("Gloin");
   secB3.addStudent("Bifur");
   secB3.addStudent("Bofur");
   secB3.addStudent("Bombur");

   cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
   secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
   jane.addSection( secB3 );
   jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


   // setup is complete, now a real world scenario can be written in the code
   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

   // week one activities  
   cout << "\nModeling week: 1\n";
   moe.addGrade( "John", 7, 1 );  
   moe.addGrade( "Paul", 9, 1 );  
   moe.addGrade( "George", 7, 1 );  
   moe.addGrade( "Ringo", 7, 1 );  
   cout << "End of week one\n";
   moe.displayGrades();

   // week two activities
   cout << "\nModeling week: 2\n";
   moe.addGrade( "John", 5, 2 );  
   moe.addGrade( "Paul", 10, 2 );  
   moe.addGrade( "Ringo", 0, 2 );  
   cout << "End of week two\n";
   moe.displayGrades();

   //test that reset works  // NOTE: can we check that the heap data was dealt with?
   cout << "\ntesting reset()\n";
   secA2.reset();
   secA2.display();
   moe.displayGrades();

} // main