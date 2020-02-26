// Josh Musgrave
// Project 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define True 1
#define False 0
#define ARGV_SIZE 10
#define INPUT_SIZE 80

int main(){
	pid_t pid;
	char *myArgv[ARGV_SIZE];
	char * word;
	char userInput[INPUT_SIZE];
	char oldUserInput[INPUT_SIZE];
	char delimiter[] = " \n";
	char curDir[100];
	char * homeDir = getenv("HOME");
	int pidArray[5];
	int execReturn;

	memset(pidArray, 0, sizeof(pidArray));
	
	// Loop runs until user types "exit"
	while(True) {

		printf("%s %s$ ", getenv("USER"),getenv("PWD"));
		fgets(userInput, sizeof(userInput), stdin);
		if(strncmp(userInput, "lc\n", 3) == 0){
			strcpy(userInput, oldUserInput);
		}

		strcpy(oldUserInput, userInput);
		// Initializing variables, then tokenizing input
		word = strtok(userInput, delimiter);
		int i = 0;
		memset(myArgv, 0, sizeof(myArgv));
		while (word != NULL) {
			myArgv[i] = word;
			word = strtok(NULL, delimiter);
			i++;
		} //end while

		if(strncmp(myArgv[0], "exit", 4) == 0){
			break;
		}
		else if(strncmp(myArgv[0], "cd", 2) == 0){
			if(myArgv[1] == NULL) {
				setenv("PWD", homeDir, 1);
				chdir(homeDir);
				continue;
			}
			else if(chdir(myArgv[1]) == -1) {
				printf("Directory does not exist\n");
				continue;
			}
			else {
				getcwd(curDir, 100);
				setenv("PWD", curDir, 1);
			continue;
			}
		}
		else if(strncmp(myArgv[0], "showpid", 7) == 0){
			for(i = 0; i < 5 ; i++){
				printf("%d\n", pidArray[i]);
			}
			continue;
		}
		
		if((pid = fork()) == 0) {
			if (execvp(myArgv[0], myArgv) == -1){
				printf("%s: command not found\n", myArgv[0]);
			}
			return 0;
		} else {
			printf("%d\n", pid);
			for(int i = 0; i <= 3; i++) {
				pidArray[i] = pidArray[i+1];
			}
			pidArray[4] = pid;
			waitpid(-1, NULL, 0);
		} //end if else
	} // end while
	printf("Exiting!\n");
	return 0;
}
