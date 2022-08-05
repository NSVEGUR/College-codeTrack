#include<stdio.h>

int main(){
    FILE *fpInput, *fpOutput;
    fpInput = fopen("Input1.txt", "r");
    fpOutput = fopen("Output.txt", "w");
    if(fpInput == NULL){
        printf("Input file is empty or doesn't exist");
    }else{
        char ch;
        ch = fgetc(fpInput);
        while(ch!=EOF){
           if(ch >= 'a' && ch <= 'z'){
               ch = ch - 32;
           }else if(ch >= 'A' && ch <= 'Z'){
               ch = ch + 32;
           }
           fputc(ch, fpOutput);
           ch = fgetc(fpInput);
        }
    }
    return 0;
}