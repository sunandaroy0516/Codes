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

// Usage: <executable> number_of_courses
int main(int argc, char **argv)
{
	int num_of_courses, cnt, preq;
	char ch;
	char **courses = NULL;
	
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
	
	*courses = (char *)malloc(number_of_courses * MAX_LENGTH_OF_COURSE * (MAX_NUMBER_OF_PREREQUISITES + 1) * sizeof(char));
	
	for(cnt = 0; cnt < num_of_courses; cnt++)
	{
		cout << "Enter name of course: ";
		cin >> courses[cnt][0];
		cout << endl;
		
		preq = 1;
		while(preq < MAX_NUMBER_OF_PREREQUISITES)
		{
			cout << "Enter name of prerequisite: ";
			cin >> courses[cnt][preq];
			cout << "Do you want to enter additional prerequisites?(y/n): ";
			cin >> ch;
			
			if(ch == 'y' || ch == 'Y')
			{
				cout << endl;
				preq++;
			}
			else
			{
				break;
			}
		}
		
		display_courses(courses);
	}
	
	return 0;
}

