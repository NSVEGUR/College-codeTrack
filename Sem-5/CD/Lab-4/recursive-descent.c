//NAME:- V Nagasai
//ROLL NO:-CS20B1016
//Q:-GIVEN A CFG, DO RECURSIVE DESCENT PARSING 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fA();
void fB();
void fS();

#define SIZE 10000
char arr_str[SIZE], token;
int i = 0;

void get_token()
{
    i++;
    token = arr_str[i];
}

void error(){
    printf("\nString is NOT ACCEPTED\n");
    exit(0);    
}

void fA()
{
    switch (token)
    {
    case 'b':
        get_token();

        if(token == 'a')
            get_token();

        else
            error();

        break;

    case 'a':
        fS();
        fB();
        break;
    case 'c':
        fS();
        fB();
        break;
    
    default:
        error();
        break;
    }
}

void fB()
{
    switch (token)
    {
        case 'b':
            get_token();
            fA();
            break;
        
        case 'a':
            fS();
            break;
        
        case 'c':
            fS();
            break;
        
        default:
            error();
            break;
    }
}

void fS()
{
    switch (token)
    {
    case 'a':
        get_token();
        fA();
        fS();
        break;
    
    case 'c':
        get_token();
        break;

    default:
        break;
    }
}

int main()
{
    printf("Enter the string : ");

    fgets(arr_str, SIZE, stdin);
    token = arr_str[0];

    fS();

    if(token == '$')
        printf("\nString is ACCEPTED\n");
    
    else   
        error();


    return 0;
}