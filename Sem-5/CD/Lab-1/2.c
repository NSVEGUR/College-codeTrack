//ROll: CS20B1016
//Name: V Nagasai
/*Given two file names as arguments, write a C program to remove redundant spaces, lines and 
comments and write it into a new files named second argument.*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	if(argc == 3){
		FILE *fpInput, *fpOutput;
		fpInput = fopen(argv[1], "r");
		fpOutput = fopen(argv[2], "w");
		if(fpInput == NULL){
			printf("Input file is empty or does not exist.\n");
		}else{
			char ch;
			int redundantFlag = 0;
			ch = fgetc(fpInput);
			while(ch != EOF){
			if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'){
				if(redundantFlag == 0){
					fputc(ch, fpOutput);
					redundantFlag = 1;
				}
			}else{
				redundantFlag = 0;
				if(ch == '/'){
					ch = fgetc(fpInput);
					if(ch == '/'){
						while(ch!='\n'){
							ch = fgetc(fpInput);
						}
					}else if(ch == '*'){
						char previous = fgetc(fpInput);
						char current = fgetc(fpInput);
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
				}else{
					fputc(ch, fpOutput);
				}
			}
				ch = fgetc(fpInput);
			}
		}
		fclose(fpInput);
		fclose(fpOutput);
	}else{
		printf("Please provide only two arguments that is name of the input file and output file.\n");
	}
}