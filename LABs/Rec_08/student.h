#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <iostream>
#include <string>

namespace BrooklynPoly{
	class Course;

	class Student{
	public:
		Student(const std::string& s_name);
		std::string getName();
		void addCourse(Course* course);
		void display();
		void dropCourse(Course* course);
	private:
		std::string name;
		std::vector<Course*> courses;
	};
}
#endif