//***************************************************
// Filename: assignment.c
//
// Author: Blake Lapum, Jay Brunsting
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h> 

#define MAX 15

int main(int argc, char *argv[]) {
	//clear terminal before starting
	system("clear"); 
	
	//array to parse input
    char input[MAX];

    while (true) {
        printf("Enter a command: ");
		
		//get the user input and store in array
        fgets(input, MAX, stdin);

		char *token;
		//remove new line character*****
		token = strtok(input, "\n");
		
		//get the first token
		token = strtok(input, " ");
		char *in1 = token;
		
		//define quit calls
		char exit1[] = "quit";
		char exit2[] = "Quit";

        if(strcmp(exit1, in1) == 0 || strcmp(exit2, in1) == 0) {
            break;
        }
		
		//array to append arguments to
		char* arr[MAX]; 
		int count = 0; 
        
		/* walk through other tokens */
		while( token != NULL ) {	
			arr[count] = token; 
			count++;
			token = strtok(NULL, " ");
		}
		
		//setting the remaining array vals to NULL
		for(int i = count; i < MAX; i++) {
			arr[i] = NULL;
		}
		
		//fork a new process
        if (fork() == 0) {
			//run exec and state if it fails
			if (execvp(in1, arr) < 0) {
				perror("Please enter a valid command.\n");
			}
		}
		else {
			//wait for child to finish, then loop again
			wait(NULL); 
		}
		
		printf("\n"); 
    }

	//clear terminal and end program
	system("clear"); 
    return 0; 
}