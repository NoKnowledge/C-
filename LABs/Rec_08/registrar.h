#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <vector>
#include <iostream>
#include <string>

namespace BrooklynPoly{
	class Course;
	class Student;

	class Registrar{
	public:
		Registrar();
		void addCourse(const std::string& course);
		void addStudent(const std::string& student);
		void enrollStudentInCourse(const std::string& student, const std::string& course);
		void cancelCourse(const std::string& course);
		void purge();
		std::vector<Course*> getCourses() const;
		std::vector<Student*> getStudents() const;
		friend std::ostream& operator << (std::ostream& os, Registrar& registrar);

	private:
		std::vector<Student*> students;
		std::vector<Course*> courses;
	};

}

#endif