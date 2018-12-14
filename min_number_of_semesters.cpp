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

#include "min_number_of_semesters.h"

using namespace std;

void Course::add_course(std::string main_course)
{
	main = main_course;
}

void Course::add_prerequisites(std::string preq_course)
{
	preqs.push_back(preq_course);
}

void Course::display_course()
{
	std::vector<std::string> my_preqs = preqs;

	cout << "Course: " << main << endl;
	cout << "Prerequisites: " << endl;

	for(std::vector<std::string>::iterator it = my_preqs.begin(); it != my_preqs.end(); ++it)
	{
		cout << *it << endl;
	}
}

// Usage: <executable> number_of_courses
int main(int argc, char **argv)
{
	int num_of_courses, cnt;
	char ch;
	Course *my_courses = NULL;

	if(argc < 2)
	{
		cout << "Number of courses is missing." << endl;
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}

	num_of_courses = atoi(argv[1]);

	if(num_of_courses <= 0)
	{
		cout << "Invalid number of courses." << endl;
		return ERR_INVALID_VALUE;
	}

	my_courses = new Course[num_of_courses];

	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		std::string main_course, preq_course;

		cout << "Enter name of course: ";
		cin >> main_course;
		my_courses[cnt].add_course(main_course);
		cout << endl;

		cout << "Does this course require prerequisites?(y/n): ";
		cin >> ch;
		cout << endl;

		while(ch == 'y' || ch == 'Y')
		{
			cout << "Enter name of prerequisite: ";
			cin >> preq_course;
			cout << "Do you want to enter additional prerequisites?(y/n): ";
			cin >> ch;
			cout << endl;
			my_courses[cnt].add_prerequisites(preq_course);
		}

		cout << endl;
	}

	cout << "Course List" << endl;

	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		my_courses[cnt].display_course();
	}

	return 0;
}

