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

std::vector<std::string> rem_courses;
unsigned int sem_cnt;

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
	if(semester)
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

		cout << "Semester: " << semester << endl;
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

bool Course::check_if_prerequisites_completed()
{
	bool all_preqs_done = true;

	if(preqs.size() == 0)
	{
		all_preqs_done = false;
	}
	else
	{
		for(std::vector<std::string>::iterator it = preqs.begin(); it != preqs.end(); ++it)
		{
			bool preq_done = false;

			for(std::vector<std::string>::iterator it1 = rem_courses.begin(); it1 != rem_courses.end(); ++it1)
			{
				if(*it == *it1)
				{
					preq_done = true;
					break;
				}
			}

			if(!preq_done)
			{
				all_preqs_done = false;
				break;
			}
		}
	}

	return all_preqs_done;
}

bool Course::check_if_completed()
{
	return semester;
}

// Usage: <executable> number_of_courses
int main(int argc, char **argv)
{
	unsigned int cnt;
	int num_of_courses;
	char ch;
	Course *my_courses = NULL;
	Course current;

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
	sem_cnt++;
	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		if(!my_courses[cnt].contains_prerequisites())
		{
			my_courses[cnt].add_semester(sem_cnt);
			my_courses[cnt].removed_courses(&rem_courses);
		}
	}

	while(1)
	{
		sem_cnt++;

		for(cnt = 0; cnt < num_of_courses; cnt++)
		{
			if(!my_courses[cnt].check_if_completed())
			{
				bool all_preqs_done = my_courses[cnt].check_if_prerequisites_completed();

				if(all_preqs_done)
				{
					my_courses[cnt].add_semester(sem_cnt);
					my_courses[cnt].removed_courses(&rem_courses);
				}
			}
		}

		if(rem_courses.size() == num_of_courses)
		{
			break;
		}
	}

	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		my_courses[cnt].display_course();
		cout << endl;
	}

	return 0;
}