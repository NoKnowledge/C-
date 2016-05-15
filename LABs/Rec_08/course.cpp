#include "course.h"
#include "student.h"
#include "registrar.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace BrooklynPoly {
	class Student;
	class Course;

	Course::Course(const std::string& c_name): name(c_name){}
	string Course::getName(){
		return name;
	}
	void Course::addStudent(Student* student){
		if(student != NULL){
			students.push_back(student);
		}
		else{
			cout << "Course is trying to add an invalid student" << endl;
		}
		/*Student* studentptr = new Student(student);
		students.push_back(studentptr);*/
	}
	void Course::display(){
		cout << "Course: " << c_name << std::endl;
	}
	void Course::dropStudents() {
		for(size_t i = 0; i < students.size(); i++){
			students[i]->dropCourse(this);
		}
		students.clear();
	}
	void Course::dropStudent(Student* student){
		if(student != NULL){
			for(size_t i = 0; i < students.size(); i++){
			if(students[i] == student){
				students.erase(students.begin() + i);
				break;
			}
		}
		else{
			cout << "Course is trying to drop an invalid student" << endl;
		}
	}
}