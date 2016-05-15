#include "student.h"
#include "course.h"
#include "registrar.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace BrooklynPoly {
	class Course;

	Student::Student(const std::string& s_name): name(s_name){}
	string Student::getName(){
		return name;
	}
	void Student::addCourse(Course* course){
		if(course != NULL){
			courses.push_back(course);
		}
		else{
			cout << "Student is trying to join an invalid course" << endl;
		}
	}
	void BrooklynPoly::Student::display() {
		cout << "Student: " << name << endl;
	}
	void Student::dropCourse(Course* course){
		if(course != NULL){
			for(size_t i = 0; i < courses.size(); i++) {
				if(courses[i] == course) {
					courses.erase(courses.begin() + i);
					break;
				}
			}
		}
		else {
			cout << "Student is trying to drop an invalid course" << endl;
		}
	}
}
