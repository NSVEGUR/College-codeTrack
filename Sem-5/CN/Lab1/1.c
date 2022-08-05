//Roll: CS20B1016
//Name: V Nagasai

/*
1) Write a menu driven program to implement CRC with following options:
	1. Send message:
			You need to take <Data bits>, <Polynomial code bits> from user. Then, perform CRC and
			display the output as <Data bits>+<CRC code bits>
	2. Receve message:
			You need to take input as <Data bits>+<CRC code bits> along with <Polynomial 
			code bits> from user. Then, perform CRC and display <Databits> and detection 
			message (Accept/Reject)
*/

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 30

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

	for(int i = 0; i < degreeOfPolynomial; i++){
			printf("%c", temp[i]);
		}
		printf("\n");
	size = degreeOfPolynomial - size;
	printf("Message with redundant bits: \n");
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

void divideReceive(int degreeOfPolynomial, int degreeOfMessage, char *message, char *polynomial){
	int point = 0, pick = degreeOfPolynomial;
	char temp[degreeOfPolynomial];
	int tempCount = 0;
	int size = 0;
	while(pick<=degreeOfMessage){
		for(int i = point; i < pick && tempCount < degreeOfPolynomial; i++){
			temp[tempCount] = *(message+i);
			tempCount += 1;
			point += 1;
		}
		xor(degreeOfPolynomial, temp, polynomial);
		size = removeZeros(degreeOfPolynomial, temp, &tempCount);
		pick += size;
	}
	if(size == degreeOfPolynomial){
		printf("Received data is correct.\n");
	}else{
		printf("Received data is corrupted.\n");
	}
	printf("Cause Reminder is: ");
	size = degreeOfPolynomial - size;
	for(int i = 0; i < size; i++){
		printf("%c", *(temp+i));
	}
	if(size == 0){
		printf("0");
	}
	printf("\n");
}

void sendMessage(){
	char polynomial[MAX_SIZE], message[MAX_SIZE * 2];
	printf("Enter the polynomial[Bit String]: ");
	scanf("%s", polynomial);
	printf("Enter the message: ");
	scanf("%s", message);
	int degreeOfPolynomial = strlen(polynomial);
	int degreeOfMessage = strlen(message);
	int n = degreeOfPolynomial + degreeOfMessage - 1;
	addZeros(degreeOfMessage, n, message);
	divideSend(degreeOfPolynomial, degreeOfMessage, n, message, polynomial);
}

void receiveMessage(){
	char polynomial[MAX_SIZE], message[MAX_SIZE * 2];
	printf("Enter the polynomial[Bit String]: ");
	scanf("%s", polynomial);
	printf("Enter the message: ");
	scanf("%s", message);
	int degreeOfPolynomial = strlen(polynomial);
	int degreeOfMessage = strlen(message);
	divideReceive(degreeOfPolynomial, degreeOfMessage,message, polynomial);	
}

int main(){
	int choice = 1;
	while(choice!=3){
		printf("1. Send a message\n");
		printf("2. Receive a message\n");
		printf("3. Exit the program\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: sendMessage();
							break;
			case 2: receiveMessage();
							break;
			case 3: printf("Program is exited.");
							// exit(0);
							break;
			default: printf("Enter the correct choice.\n");
							break;
		}
	}
	return 0;
}