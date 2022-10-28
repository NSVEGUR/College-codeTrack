//Name: V Nagasaivegur
//Roll: CS20B1016
//Q: Implement Hamming code for 4 bits message

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char data[17];
char parity[5];

void revstr(char *str1)  
{  
    int i, len, temp;  
    len = strlen(str1); 
      
    for (i = 0; i < len/2; i++)  
    {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}

int main(){
	printf("Enter the message without spaces[only 16 bits]: ");
	scanf("%s", data);
	if(strlen(data) != 16)
	{
		printf("Please enter 16 bits only\n");
		exit(1);
	}
	data[16] = '\0';
	revstr(data);
	int count = 0;
	if(data[14] == '1')
		count++;
	if(data[15] == '1')
		count++;
	if(count%2==0)
		parity[4] = '0';
	else
		parity[4] = '1';

	count = 0;
	if(data[9] == '1')
		count++;
	if(data[10] == '1')
		count++;
	if(data[11] == '1')
		count++;
	if(data[12] == '1')
		count++;
	if(data[13] == '1')
		count++;
	if(count%2==0)
		parity[3] = '1';
	else
		parity[3] = '0';

	count = 0;
	if(data[7] == '1')
		count++;
	if(data[8] == '1')
		count++;
	if(count%2==0)
		parity[2] = '0';
	else
		parity[2] = '1';
	
	count = 0;
	if(data[2] == '1')
		count++;
	if(data[3] == '1')
		count++;
	if(data[4] == '1')
		count++;
	if(data[5] == '1')
		count++;
	if(data[6] == '1')
		count++;
	if(count%2==0)
		parity[1] = '1';
	else
		parity[1] = '0';

	count = 0;
	if(data[0] == '1')
		count++;
	if(data[1] == '1')
		count++;
	if(count%2==0)
		parity[0] = '0';
	else
		parity[0] = '1';

	printf("Input[reverse of input]: %s\n", data);
	printf("Parity Bits: %c%c%c%c%c\n", parity[4], parity[3], parity[2], parity[1], parity[0]);
	printf("Output: ");
	printf("%c%c%c", parity[4], data[15], data[14]);
	printf("%c%c%c%c%c%c", parity[3], data[13], data[12], data[11], data[10], data[9]);
	printf("%c%c%c", parity[2], data[8], data[7]);
	printf("%c%c%c%c%c%c", parity[1], data[6], data[5], data[4], data[3], data[2]);
	printf("%c%c%c", parity[0], data[1], data[0]);
	printf("\n");
	return 0;
}