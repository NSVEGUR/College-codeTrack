#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 128
#define MAX_PRODUCTIONS 26


//Production Details
struct prod{
	char head;
	char production[MAX_PRODUCTIONS];
	int len;
}productions[MAX_PRODUCTIONS];
int productionCount = 0;

//NT and T
//Based on the alphabet number
char nonTerminals[MAX_PRODUCTIONS];
//Based on ascii values
char terminals[MAX_SIZE];

//first
struct first{
	char head;
	char set[MAX_SIZE];
}firstOfNonTerminals[MAX_PRODUCTIONS];

//follow
struct follow{
	char head;
	char set[MAX_SIZE];
}followOfTerminals[MAX_PRODUCTIONS], followOfNonTerminals[MAX_PRODUCTIONS];

int isNonTerminal(char ch){
	if(ch >= 'A' && ch <= 'Z')
		return 1;
	return 0; 
}

void calculateFirst(){
	for(int i = 0; i < MAX_SIZE; i++){
			if(nonTerminals[i] != '\0')
			{
				//For each production p
				for(int j = 0; j < productionCount; j++){
					
				}
			}
	}
}

//Function to print productions
void printProductions(){
	for(int i = 0; i < productionCount; i++){
		printf("%c->%s\n", productions[i].head, productions[i].production);
	}
}

//Function to print terminals and non terminals
void printTerminalsAndNonTerminals(){
	printf("\n---NON-TERMINALS---\n");
	for(int i = 0; i < 26; i++){
		if(nonTerminals[i] != '\0')
			printf("%c ", nonTerminals[i]);
	}
	printf("\n---TERMINALS---\n");

	for(int i = 0; i < MAX_SIZE; i++){
		if(terminals[i] != '\0')
			printf("%c ", terminals[i]);
	}
	printf("\b");
}

//Reading from the file and separating terminals, non terminals and saving productions
void readFromFile(char *argv[]){
	FILE *fp;
	char buffer[255];
	fp = fopen(argv[1], "r");
	while(fgets(buffer, sizeof(buffer), fp)){
		int flag = 0;
		productions[productionCount].len = 0;
		for(int i = 0; buffer[i] != '\n'; i++){
			if(buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '=')
				continue;
			if(!flag){
				productions[productionCount].head = buffer[i];
				flag = 1;
				continue;
			}
			productions[productionCount].production[productions[productionCount].len] = buffer[i];
			productions[productionCount].len += 1;
			if(buffer[i] >= 'A' && buffer[i] <= 'Z'){
				nonTerminals[buffer[i] - 'A'] = buffer[i];
			}
			else{
				terminals[toascii(buffer[i])] = buffer[i];
			}
		}
		productionCount+=1;
	}
	printProductions();
	printTerminalsAndNonTerminals();
}

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Please provide file name containing cfg as argument.\n");
		exit(1);
	}
	readFromFile(argv);
	printf("\n");
	return 0;
}

