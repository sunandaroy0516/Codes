/* Given a map containing courses and the list of prerequisites for that course
in no particular order, determine the least number of semesters to finish all
the courses. You have to take all prerequisites before you take a given
course.

Eg.
Calculus : English, Math2
Math2 : Math 1, Arabic, English
Math1 : English
English: <>
Arabic: <> */

#ifndef __MIN_NUMBER_OF_SEMESTERS__
#define __MIN_NUMBER_OF_SEMESTERS__

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "error_codes.h"

#define MAX_NUMBER_OF_PREQUISITES 5

class Course
{
	std::string main;
	std::vector<std::string> preqs;
	unsigned int semester;

	public:	
	
	Course() { }
	
	void add_course(std::string);
	
	void add_prerequisites(std::string);
	
	void display_course();
	
	bool contains_prerequisites();
	
	void add_semester(unsigned int);
	
	void removed_courses(std::vector<std::string> *);
};

#endif