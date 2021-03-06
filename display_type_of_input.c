/*
Write a program to display the type of a variable read from STDIN.
For ex., 
Input 		Output
12			This is an integer.
12.34		This is a float.
Hello		This is a string.
hello123	This is something else.
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    int ctr = 0;
    char a[100];
    scanf("%s", a);

    int b = atoi(a);
    float c = atof(a);
    
    for(int i = 0; a[i] != '\0'; i++){
        if(!(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z'))
        {
            ctr++;
            break;
        }
    }
    
	if(b != 0){
		if(b == c){
			printf("This is an integer.");
		}
		else{
			printf("This is a float.");
		}
	}
	else if(ctr){
        printf("This is something else.");
    }
    else{
		printf("This is a string.");
	}

    return 0;
}