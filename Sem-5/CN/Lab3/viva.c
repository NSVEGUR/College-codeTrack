#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Input message update with your roll no
char rollno[10]="CS20B1016";
//Input polynomial donot change
char poly[8]="10111011";

char binary[100];

void addZeros(int degreeOfMessage, int n, char *message){
	for(int i = degreeOfMessage; i < n; i++){
		*(message+i) = '0';
	}
}

int removeZeros(int degreeOfPolynomial, char* temp, int *tempCount){
	int start = degreeOfPolynomial;
	*tempCount = 0;
	int remain = 0;
	for(int i = 0; i < degreeOfPolynomial; i++){
		if(*(temp+i) == '1'){
			start = i;
			break;
		}
	}
	for(int i = start; i < degreeOfPolynomial; i++){
		*(temp+(*tempCount)) = *(temp+i);
		*tempCount += 1;
		remain++;
	}
	return (degreeOfPolynomial - remain);
}

void xor(int degreeOfPolynomial, char* temp, char* polynomial){
	for(int i = 0; i < degreeOfPolynomial; i++){
		if(*(temp+i) == *(polynomial+i)){
			*(temp+i) = '0';
		}else{
			*(temp+i) = '1';
		}
	}
}

void divideSend(int degreeOfPolynomial, int degreeOfMessage, int n, char *message, char *polynomial){
	int point = 0, pick = degreeOfPolynomial;
	char temp[degreeOfPolynomial];
	int tempCount = 0;
	int size = 0;
	while(pick<=n){
		for(int i = point; i < pick && tempCount < degreeOfPolynomial; i++){
			temp[tempCount] = *(message+i);
			tempCount += 1;
			point += 1;
		}
		xor(degreeOfPolynomial, temp, polynomial);
		size = removeZeros(degreeOfPolynomial, temp, &tempCount);
		pick += size;
	}

	// for(int i = 0; i < degreeOfPolynomial; i++){
	// 		printf("%c", temp[i]);
	// 	}
	// 	printf("\n");
	size = degreeOfPolynomial - size;
	printf("CRC code: ");
	for(int i = 0; i < degreeOfMessage; i++){
		printf("%c", *(message+i));
	}
	if(size < degreeOfPolynomial - 1){
		for(int i = 0; i < degreeOfPolynomial - size - 1; i++){
			printf("0");
		}
	}
	for(int i = 0; i < size; i++){
		printf("%c", *(temp+i));
	}
	printf("\n");
}

void sendMessageCRC(){
	int degreeOfPolynomial = strlen(poly);
	int degreeOfMessage = strlen(binary);
	int n = degreeOfPolynomial + degreeOfMessage - 1;
	addZeros(degreeOfMessage, n, binary);
	divideSend(degreeOfPolynomial, degreeOfMessage, n, binary, poly);
}

void sendMessageVRC(){
	int choice = 2;
	int messageLength = strlen(binary);
	int parityLength = messageLength / 4;
	char parityBits[parityLength];
	int k = 0;
	for(int i = 0; i < messageLength; i +=4){
		int count = 0;
		for(int j = i; j < i+4; j++){
			if(binary[j] == '1')
				count++;
		}
		if(choice == 1){
			if(count%2 == 0){
				parityBits[k] = '1';
			}else{
				parityBits[k] = '0';
			}
			k++;
		}else if(choice == 2){
			if(count%2 == 0){
				parityBits[k] = '0';
			}else{
				parityBits[k] = '1';
			}
			k++;
		}
	}
	printf("VRC code: ");
	for(int i = 0; i < messageLength; i++){
		printf("%c", binary[i]);
	}
	for(int i = 0; i < parityLength; i++){
		printf("%c", parityBits[i]);
	}
	printf("\n");
}

void sendMessageLRC(){
	char parity[9];
	int count = 0;
	int choice = 1;
	for (int i = 0; i < 8; i++)
    {
        count = 0;
        for (int j = i; j < 32; j += 8)
        {
            if (binary[j] == '1')
            {
                count++;
            }
        }
        if (choice == 1)
        {
            if (count % 2 == 0)
            {
                parity[i] = '0';
                parity[i + 1] = '\0';
            }
            else
            {
                parity[i] = '1';
                parity[i + 1] = '\0';
            }
        }
        else if (choice == 0)
        {
            if (count % 2 == 0)
            {
                parity[i] = '1';
                parity[i + 1] = '\0';
            }
            else
            {
                parity[i] = '0';
                parity[i + 1] = '\0';
            }
        }
    }
    
    printf("LRC code: %s%s \n",binary,parity);
}

int asciiValueToBinary(int asciiInput)
{
	int res = 0, i = 1, rem;
        
	while (asciiInput > 0)
	{
		rem = asciiInput % 2;
		res = res + (i * rem);
		asciiInput = asciiInput / 2;
		i = i * 10;
	}
	return(res);
}

//Generate binary string from input message (2 Mark)
char* genbs(char *ipmsg)
{
	printf("ASCII values: ");
	int k = 0;
	for(int i=0;ipmsg[i]!='\0';i++)
	{	
		int bi = asciiValueToBinary(toascii(ipmsg[i]));
		printf("(%d)",toascii(ipmsg[i]));
		while(bi){
			char ch = (bi % 10) + '0';
			bi = bi / 10;
			binary[k] = ch;
			k++;
		}
	}
	printf("\n");
	return(binary);
}

//CRC code generation (3 Marks)
// char* genCRC(char *ipstr)
// {	char code[8]="";
// 	//Write code to generate CRC code from input binary string
	
// 	return(code);
// }

// //LRC code generation (2 Marks)
// char* genLRC(char *ipstr)
// {	char code[8]="";
// 	//Write code to generate LRC code from input binary string
	
// 	return(code);
// }

// //VRC code generation (2 Marks)
// char* genVRC(char *ipstr)
// {	char code[8]="";
// 	//Write code to generate VRC code from input binary string
	
// 	return(code);
// }


int main()
{	
	printf("\nInput Polynomial: %s\n", poly);
	printf("Input Message: %s\n", rollno);
	printf("Binary String: %s\n",genbs(rollno));
	sendMessageCRC();
	sendMessageVRC();
	sendMessageLRC();
	printf("\n");
	// printf("\nCRC code: %s", genCRC(rollno));
	// printf("\nLRC code: %s", genLRC(rollno));
	// printf("\nVRC code: %s", genVRC(rollno));
	return 0;
}