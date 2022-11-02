
#include<stdio.h>
#include<string.h>

int i,j,l,addr=100;
char expressionCopy[10], expression[10] ,expressionTemp[10];

void strrev(char *str){
	int len = strlen(str);
	for(int i = 0; i < len/2; i++){
		char temp = str[i];
		str[i] = str[temp - i - 1];
		str[temp - i - 1] = temp;
	}
}

void pm()
{
	strrev(expression);
	j=l-i-1;
	strncat(expressionTemp,expression,j);
	strrev(expressionTemp);
	printf("Three address code:\ntemp=%s\ntemp1=%c%c temp\n",expressionTemp,expression[j+1],expression[j]);
}

void div()
{
	strncat(expressionTemp,expression,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",expressionTemp,expression[i+2],expression[i+3]);
}

void plus()
{
	strncat(expressionTemp,expression,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",expressionTemp,expression[i+2],expression[i+3]);
}

int main()
{
	printf("\nEnter the expression with arithmetic operator:");
	scanf("%s",expressionCopy);
	strcpy(expression,expressionCopy);
	l=strlen(expression);
	expressionTemp[0]='\0';

	for(i=0;i<l;i++)
	{
		if(expression[i]=='+'||expression[i]=='-')
		{
			if(expression[i+2]=='/'||expression[i+2]=='*')
			{
				pm();
				break;
			}
			else
			{
				plus();
				break;
			}
		}
		else if(expression[i]=='/'||expression[i]=='*')
		{
			div();
			break;
		}
	}
	return 0;
}