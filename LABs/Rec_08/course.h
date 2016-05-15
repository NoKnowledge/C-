#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <iostream>
#include <string>

namespace BrooklynPoly{
	class Student;

	class Course{
	public:
		Course(const std::string& c_name);
		std::string getName();
		void addStudent(Student* student);
		void display();
		void dropStudents();
		void dropStudent(Student* student);

	private:
		std::string name;
		std::vector<Student*> students;
	};
}
#endif