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

#define MAX 50

int main(int argc, char *argv[]) {
    char input[MAX];

    while (true) {
        printf("Enter a command: ");
        fgets(input, MAX, stdin);

        
        char* arr[MAX]; 
        int count = 1; 
        char* in1 = strtok(input, " ");
        arr[0] = "some string";

        if(strcmp(in1, "Q") == 0 || strcmp(in1, "Quit") == 0) {
            break;
        }

        while(true) {
            char* in2 = strtok(NULL, " ");
            if (in2 != NULL) {
                arr[count] = in2; 
                count++; 
            }
            else {
                arr[count] = NULL;
                break; 
            }
        }

        execvp(in1, arr); 
    }

    return 1; 
}