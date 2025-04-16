#include <stdio.h>
#include <string.h>
#include <unistd.h>

# define BUFSIZE 512
# define MAXARG 10
/** 
* Parse input comand to see if it contains a specific word
* @param command string for user input
* @param target array for target phrases
* return array of words for commands
*/
char** parse_command(char *command, char *buf, int bufsize){
    static char *args[MAXARG];
    int i = 0;

    // Read input from stdin
    int bytesRead = read(0, buf, bufsize - 1);
    if (bytesRead <= 0) {
        return 0; // No input
    }

    buf[bytesRead] = '\0'; // Null-terminate input

    char *p = buf;
    while (*p != '\0' && i < MAXARG - 1) {
        // Convert spaces to null terminators
        if (*p == ' ' || *p == '\n') {
            *p = '\0';
            p++;
        }

        // Find the start of a word and add word to args
        if (*p != '\0') {  
            args[i++] = p;

            // Move to the end of the word
            while (*p != '\0') {
                p++;
            }
        }
    }

    args[i] = 0; // Null-terminate the argument list
    return args;
}

char* get_command_action(){
    // return action;
}

char* get_command_object(){
    // return object;
}

int main() {
    char play[10]; // increased size to safely hold input

    printf("Welcome to wonderland.\nTo quit the game type 'quit' at any point.\nWould you like to play?\nType 'y' or 'n': ");
    scanf("%9s", play); // limit input to avoid buffer overflow
        
    if (strcmp(play, "y")==0 || strcmp(play, "Y")==0) {
        printf("Let's play!\n");

        //Command loop

    } if (strcmp(play, "n")==0 || strcmp(play, "N")==0) {
        printf("Maybe next time.\n");
    }
    
    return 0;
}