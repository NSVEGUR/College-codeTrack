//Name: V Nagasai
//Roll: CS20B1016
//Q: Given a C file as a argument. Divide that into tokens and find the number of different type of tokens.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

bool check(char ch, char arr[]){
	int n = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0; i < n; i++){
		if(ch == arr[i]){
			return true;
		}
	}
	return false;
}

bool isDelimiter(char ch){
	char delimiters[] = {' ', '+', '-', '*', 
								'/', ',', ';', '>',
								'<', '=', '(', ')',
								'[', ']', '{', '}'};
	return check(ch, delimiters);
}

bool isOperator(char ch){
	char operators[] = {'+','-', '*', '/', '>', '<', '='};
	return check(ch, operators);
}

bool validIdentifier(char* str){
	char notIdentifierStarters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	if(check(str[0], notIdentifierStarters) || isDelimiter(str[0])){
		return false;
	}
	return true;
}

bool isKeyword(char* str){
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isInteger(char* str){
	char integers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int i, len = strlen(str);
	if(len == 0)
		return false;
	for(int i = 0; i < len; i++){
		if(check(str[i], integers) || (str[i] == '-' && i == 0)){
			return true;
		}
	}
	return false;
}

bool isRealNumber(char* str){
	int i, len = strlen(str);
	bool hasDecimal = false;
	char decimals[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
  if(len == 0)
		return false;
	for(int i = 0; i < len; i++){
		if(check(str[i], decimals) || (str[i] == '-' && i == 0)){
			return true;
		}
		if(str[i] == '.'){
			hasDecimal = true;
		}
	}
	return hasDecimal;
}

// Extracts the SUBSTRING.
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
 
// Parsing the input STRING.
void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
 
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);
 
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
 
            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);
 
            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);
 
            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);
 
            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);
 
            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}

void removeUnnecessary(FILE *fpInput, FILE *fpOutput){
	char ch, current, previous;
	int redundantFlag = 0;
	ch = fgetc(fpInput);
	previous = '\n';
	current = ch;
	while(ch != EOF){
	if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'){
		if(redundantFlag == 0){
			fputc(ch, fpOutput);
			redundantFlag = 1;
		}
		ch = fgetc(fpInput);
	}else{
		redundantFlag = 0;
		if(ch == '/'){
			ch = fgetc(fpInput);
			if(ch == '/'){
				while(ch!='\n'){
					ch = fgetc(fpInput);
				}
			}else if(ch == '*'){
				previous = fgetc(fpInput);
				current = fgetc(fpInput);
				int temp = 0;
				if(current == '/' && previous == '*'){
					temp = 1;
				}
				while(temp != 1){
					previous = current;
					current = fgetc(fpInput);
				if(current == '/' && previous == '*'){
					temp = 1;
				}
				}
				ch = fgetc(fpInput);
			}else{
				fputc(ch, fpOutput);
			}
			ch = fgetc(fpInput);
		}else if(ch == '#'){
			if(previous == '\n'){
				while(ch!='\n'){
					ch = fgetc(fpInput);
				}
			}
			redundantFlag = 1;
			printf("current: ch %c\n", ch);
		}else{
			fputc(ch, fpOutput);
			ch = fgetc(fpInput);
		}
	}
		previous = current;
		current = ch;
	}
}

int main(int argc, char** argv){
	if(argc != 2){
		printf("Please enter the file name as an argument[only one].\n");
		exit(1);
	}
	FILE *fpInput, *fpOutput;
	fpInput = fopen(argv[1], "r");
	fpOutput = fopen("output.c", "w");
	//To remove redundant spaces, lines, comments and file directives.
	removeUnnecessary(fpInput, fpOutput);
	fclose(fpInput);
	fclose(fpOutput);
	FILE *fp = fopen("output.c", "r");
	char chunk[128];
  while(fgets(chunk, sizeof(chunk), fp) != NULL) {
    parse(chunk);
  }
	return 0;
}