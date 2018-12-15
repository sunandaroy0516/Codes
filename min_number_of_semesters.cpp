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
	cout << "Course: " << main << endl;
	
	if(preqs.size() > 0)
	{
		cout << "Prerequisites: " << endl;

		for(std::vector<std::string>::iterator it = preqs.begin(); it != preqs.end(); ++it)
		{
			cout << *it << endl;
		}
	}	
}

bool Course::contains_prerequisites()
{
	bool result = false;
	
	if (preqs.size() > 0)
	{
		result = true;
	}
	
	return result;
}

void Course::add_semester(unsigned int sem)
{
	semester = sem;
}

void Course::removed_courses(std::vector<std::string> *removed)
{
	(*removed).push_back(main);
}

// Usage: <executable> number_of_courses
int main(int argc, char **argv)
{
	unsigned int cnt, sem_cnt;
	int num_of_courses;
	char ch;
	Course *my_courses = NULL;
	std::vector<std::string> rem_courses;
	sem_cnt = 1;

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

	// Get all course details along with their prerequisites.
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

	// Display all course details along with their prerequisites.
	/*cout << "Course List" << endl;
	
	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		my_courses[cnt].display_course();
	}*/
	
	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		Course current = my_courses[cnt];
		
		if(current.contains_prerequisites() == 0)
		{
			current.add_semester(sem_cnt);
			current.removed_courses(&rem_courses);
		}
	}

	// Display courses with no prerequisites.
	cout << "Courses in semester " << sem_cnt << endl;
	
	for(std::vector<std::string>::iterator it = rem_courses.begin(); it != rem_courses.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}