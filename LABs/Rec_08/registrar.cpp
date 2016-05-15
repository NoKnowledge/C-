#include "registrar.h"
#include "course.h"
#include "student.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace BrooklynPoly {
	class Course;
	class Student;
	Registrar::Registrar() {}
	ostream& operator << (std::ostream& os, Registrar& registrar){
		cout << "Students: " << endl;
		std::vector<Student*>students = registrar.getStudents();
		if(students.size() == 0){
			cout << "NONE" << std::endl;
		}
		for(Student* thisStudent : students){
			thisStudent->display();
		}
		cout << "Courses: " << std::endl;
		std::vector<Course*>courses = registrar.getCourses();
		if(courses.size() == 0){
			cout << "NONE" << std::endl;
		}
		for (Course* thisCourse : courses){
			thisCourse->display();
		}
		return os;
	}

	void Registrar::addCourse(const std::string& name){
		Course* thisCourse = new Course(name);
		courses.push_back(thisCourse);
	}
	void Registrar::addStudent(const std::string& name){
		Student* thisStudent = new Student(name);
		students.push_back(thisStudent);
	}

	void Registrar::enrollStudentInCourse(const std::string& student, const std::string& course) {
		Student* student == NULL;
		Course* course == NULL;

		for(size_t i = 0; i < students.size(); i++){
			if(students[i]->getName() == student){
				student = students[i];
			}
		}
		for(size_t i = 0; i < courses.size(); i++){
			if(courses[i]->getName() == course){
				course = courses[i];
			}
		}
		if(student != NULL && course != NULL){
			course->addStudent(student);
			student->addCourse(course);
		}
		else{
			cout << "Could not find student or course during enrollment" << endl;
		}
	}

	void Registrar::cancelCourse(const string& course){
		Course* Courseptr = Registrar::getCourse(course);
		delete Courseptr;
		Courseptr = NULL;
		courses.pop_back();
	}

	void Registrar::purge(){
		for(Student* thisStudent : students){
			if(thisStudent != NULL){
				delete thisStudent;
			}
		}
		for(Course* thisCourse : courses){
			if(thisCourse != NULL){
				delete thisCourse;
			}
		}
		students.clear();
		courses.clear();
	}

    vector<Course*> Registrar::getCourses() const {
        return this->courses;
    }
	vector<Student*> Registrar::getStudents() const {
        return this->students;
    }
}
