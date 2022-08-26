//Name: V Nagasaivegur
//Roll: CS20B1016
//Q: Implement Hamming code for 4 bits message

#include<stdio.h>
#include<stdlib.h>

char data[4];
char finalMessage[7];
char hammingCode[3];
char receivedMessage[7];
int parityBits[3];
int parity = 0;

void printSenderSide(){
	printf("\n\n\033[0;34m1. Number of Parity bits = %d\n", 3);
	printf("2. Input Message = ");
	for(int i = 0; i < 4; i++){
		printf("%c", data[i]);
	}
	printf("\n3. Hamming Code = %s\n", hammingCode);
	printf("4. Sent Message = %s\n\n\033[0m", finalMessage);
}

void gen_hcode(){
	int count;

	//Filling the data in the hamming code
	finalMessage[2] = data[0];
	finalMessage[4] = data[1];
	finalMessage[5] = data[2];
	finalMessage[6] = data[3];

	//For parity bit 1
	count = 0;
	if(finalMessage[2] == '1')
		count++;
	if(finalMessage[4] == '1')
		count++;
	if(finalMessage[6] == '1')
		count++;
	if(parity == 1){
		if(count%2 == 0){
			finalMessage[0] = '1';
			hammingCode[0] = '1';
		}else{
			finalMessage[0] = '0';
			hammingCode[0] = '0';
		}
	}else{
		if(count%2 == 1){
			finalMessage[0] = '1';
			hammingCode[0] = '1';
		}else{
			finalMessage[0] = '0';
			hammingCode[0] = '0';
		}
	}

	//For parity bit 2
	count = 0;
	if(finalMessage[2] == '1')
		count++;
	if(finalMessage[5] == '1')
		count++;
	if(finalMessage[6] == '1')
		count++;
	if(parity == 1){
		if(count%2 == 0){
			finalMessage[1] = '1';
			hammingCode[1] = '1';
		}else{
			finalMessage[1] = '0';
			hammingCode[1] = '0';
		}
	}else{
		if(count%2 == 1){
			finalMessage[1] = '1';
			hammingCode[1] = '1';
		}else{
			finalMessage[1] = '0';
			hammingCode[1] = '0';
		}
	}

	//For parity bit 3
	count = 0;
	if(finalMessage[4] == '1')
		count++;
	if(finalMessage[5] == '1')
		count++;
	if(finalMessage[6] == '1')
		count++;
	if(parity == 1){
		if(count%2 == 0){
			finalMessage[3] = '1';
			hammingCode[2] = '1';
		}else{
			finalMessage[3] = '0';
			hammingCode[2] = '0';
		}
	}else{
		if(count%2 == 1){
			finalMessage[3] = '1';
			hammingCode[2] = '1';
		}else{
			finalMessage[3] = '0';
			hammingCode[2] = '0';
		}
	}
}

void detect_hcode(){
	int count;

	//For parity bit 1
	count = 0;
	if(receivedMessage[0] == '1')
		count++;
	if(receivedMessage[2] == '1')
		count++;
	if(receivedMessage[4] == '1')
		count++;
	if(receivedMessage[6] == '1')
		count++;
	if(parity == 1){
		if(count%2 == 1){
			parityBits[0] = 0;	
		}else{
			parityBits[0] = 1;
		}
	}else{
		if(count%2 == 0){
			parityBits[0] = 0;
		}else{
			parityBits[0] = 1;
		}
	}

	//For parity bit 2
	count = 0;
	if(receivedMessage[1] == '1')
		count++;
	if(receivedMessage[2] == '1')
		count++;
	if(receivedMessage[5] == '1')
		count++;
	if(receivedMessage[6] == '1')
		count++;
	if(parity == 1){
		if(count%2 == 1){
			parityBits[1] = 0;	
		}else{
			parityBits[1] = 1;
		}
	}else{
		if(count%2 == 0){
			parityBits[1] = 0;
		}else{
			parityBits[1] = 1;
		}
	}

	//For parity bit 2
	count = 0;
	if(receivedMessage[3] == '1')
		count++;
	if(receivedMessage[4] == '1')
		count++;
	if(receivedMessage[5] == '1')
		count++;
	if(receivedMessage[6] == '1')
		count++;
	if(parity == 1){
		if(count%2 == 1){
			parityBits[2] = 0;	
		}else{
			parityBits[2] = 1;
		}
	}else{
		if(count%2 == 0){
			parityBits[2] = 0;
		}else{
			parityBits[2] = 1;
		}
	}

	int errorBit = (4 * parityBits[2]) + (2 * parityBits[1]) + (1 * parityBits[0]);

	printf("\n\n\033[0;34m4. Received Message = %s\n", receivedMessage);
	printf("5. Error Result: ");
	printf("\033[1;31mError is in the %dth bit.\n", errorBit);
	printf("\033[0;34m6. Parity Bits Code: ");
	for(int i = 0; i < 3; i++){
		printf("%d", parityBits[i]);
	}
	printf("\n\033[0m\n");
}

void copyOriginal(){
	for(int i = 0; i < 7; i++){
		receivedMessage[i] = finalMessage[i];
	}
}

int main(){
	int choice = 0;
	printf("Enter the message without spaces[only 4 bits]: ");
	scanf("%s", data);
	PARITY:
	printf("1. Odd Parity\n");
	printf("2. Even Parity\n");
	printf("Choose your parity: ");
	scanf("%d", &parity);
	if(parity != 1 && parity != 2){
		printf("Please enter a correct choice.\n");
		goto PARITY;
	}
	while(choice != 5){
		printf("\n\n\033[0;33m1. No Error: without changing data and redundant bits check for error.\n");
		printf("2. Error 1: change one random data bit and check for errors.\n");
		printf("3. Error 2: change one random parity bit and check for errors.\n");
		printf("4. Error 3: change one random data and one parity bit and check for errors.\n");
		printf("5. Exit.\033[0m\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: {
				gen_hcode();
				printSenderSide();
			}break;
			case 2: {
				gen_hcode();
				copyOriginal();
				//Changing 4th data bit

				if(receivedMessage[6] == '1')
					receivedMessage[6] = '0';
				else
					receivedMessage[6] = '1';

				//Detecting the error
				detect_hcode();
			}break;
			case 3:{
				gen_hcode();
				copyOriginal();
				//Changing 1st parity bit
				if(receivedMessage[0] == '1')
					receivedMessage[0] = '0';
				else
					receivedMessage[0] = '1';

				//Detecting the error
				detect_hcode();
			}break;
			case 4:{
				gen_hcode();
				copyOriginal();
				//Changing 1st parity bit
				if(receivedMessage[0] == '1')
					receivedMessage[0] = '0';
				else
					receivedMessage[0] = '1';

				//Changing 4th data bit
				if(receivedMessage[6] == '1')
					receivedMessage[6] = '0';
				else
					receivedMessage[6] = '1';

				//Detecting the error
				detect_hcode();
				printf("\n\n\033[0;31mBut this might be wrong or correct cause hamming code can only detect one bit errors.\033[0m\n\n");
			}break;
			case 5:{
				printf("Program is Exited.\n");
				exit(0);
			}break;
			default: {
				printf("Please Enter the Correct Choice.\n");
			}break;
		}
	}
	return 0;
}