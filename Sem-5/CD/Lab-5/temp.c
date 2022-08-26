#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 25

char productions[MAX_SIZE][MAX_SIZE];



int main(int argc, char **argv){
	if(argc != 2){
		printf("Please provide a file name as argument to execute.\n");
		exit(0);
	}else{
		FILE *input;
		char ch;
		char production[MAX_SIZE];
		input = fopen(argv[1], "r");
		ch = getc(input);
		int i = 0;
		while(ch!=EOF){
			if(ch == ' ' || ch == '\t')
				continue;
			else if(isalpha(ch) || ch == '=' || ch == '$' || ch == '#'){

			}
			else if(ch == '\n'){
				strcpy(productions[i], production);
				memset(production, 0, MAX_SIZE);
				i++;
			}else 
				continue;
		}
		printf("\n");
	}
	for(int i = 0; i < strlen(productions[i]); i++){
		printf("%s\n", productions[i]);
	}
	
	return 0;
}