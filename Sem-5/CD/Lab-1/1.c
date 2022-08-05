//ROll: CS20B1016
//Name: V Nagasai
/*Given a file name as an argument, write a C program to print number of lines, 
number words and number of characters in it.*/

#include<stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
	if(argc == 2){
		FILE *fp;
		fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("Input file is empty or does not exist.\n");
		}else{
			char ch;
			int words = 0, lines = 0, characters = 0, flag = 0;
			ch = fgetc(fp);
			while(ch != EOF){
				if(ch == '\n'){
					lines++;
				}
				if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'){
					if(flag == 0){
						words++;
						flag = 1;
					}
				}else{
					flag = 0;
					if(characters == 0){
						words++;
					}
				}
				characters++;
				ch = fgetc(fp);
			}
			printf("No of words: %d\n", words);
			printf("No of lines: %d\n", lines);
			printf("No of characters: %d\n", characters);
		}
		fclose(fp);
	}else{
		printf("Please provide only one argument that is name of the input file.\n");
	}
	return 0;
}