//Name: V Nagasai
//Roll: CS20B1016
//Q: Given a C file as a argument. Divide that into tokens and find the number of different type of tokens.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

int operators = 0, specialCharacters = 0, keywords = 0, constants = 0, strings = 0, identifiers = 0;

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' || 
        ch == '"' || ch == '\''
        )
        return (true);
    return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}
 
// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
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
 
// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
    int i, len = strlen(str);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}
 
// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
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
    int stringStart = 0;
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
 
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                {
                    printf("'%c' IS AN OPERATOR\n", str[right]);
                    operators++;
                }
            else if(str[right] != ' ')
            {
                printf("'%c' IS A SPECIAL CHARACTER\n", str[right]);
                specialCharacters++;
                if(str[right] == '\'' || str[right] == '"'){
                    stringStart = 1;
                }
            }
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
 
            if (isKeyword(subStr) == true)
                {
                    printf("'%s' IS A KEYWORD\n", subStr);
                    keywords++;
                }
 
            else if (isInteger(subStr) || isRealNumber(subStr))
                {
                    printf("'%s' IS AN CONSTANT\n", subStr);
                    constants++;
                }
 
            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                {
                    if(str[right-1] == '\n'){
                        right++;
                        left = right;
                    }else if(stringStart == 1){
                       while(str[right] != '"' && str[right] != '\''){
                        right++;
                        // printf("string started: left:'%c', right: '%c'\n", str[left], str[right-1]);
                       }
                        subStr = subString(str, left, right - 1);
                        printf("'%s' IS A STRING\n", subStr);
                        strings++;
                        left = right;
                        stringStart = 0;
                    }else{
                        printf("'%s' IS A VALID IDENTIFIER\n", subStr);
                        identifiers++;
                    }
                }
 
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
    printf("------------------------------------------------------------------\n");
    printf("Identifiers: %d\n", identifiers);
    printf("Keywords: %d\n", keywords);
    printf("Constants: %d\n", constants);
    printf("Operators: %d\n", operators);
    printf("Special Chars: %d\n", specialCharacters);
    printf("Strings: %d\n", strings);
    printf("------------------------------------------------------------------\n");
	return 0;
}