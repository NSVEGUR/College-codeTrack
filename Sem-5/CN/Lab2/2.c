//Roll: CS20B1016
//Name: V Nagasai

/*
2)  Write a menu driven program to implement LRC with following options:
3. Send message:You need to take <Data bits> from user. Then, perform LRC and display the
output as <Data bits>+<LRC code bits>
4. Receve message: You need to take input as <Data bits>+<LRC code bits> from user. Then,
perform LRC and display <Data bits> and detection message (Accept/Reject)
*/

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 30

void sendMessage(){
	char message[MAX_SIZE];
	int choice = 1;
	printf("Enter the message: ");
	scanf("%s", message);
	printf("Choose the Parity\n");
	printf("1. Odd Parity\n");
	printf("2. Even Parity\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	int messageLength = strlen(message);
	int parityLength = messageLength / 4;
	char parityBits[parityLength];
	int k = 0;
	for(int i = 0; i < messageLength / 4; i++){
		int count = 0;
		for(int j = 0; j < messageLength / 4; j++){
			int index = j * 4 + i;
			if(message[index] == '1'){
				count++;
			}
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
	
	printf("Redundant Message is: \n");
	for(int i = 0; i < messageLength; i++){
		printf("%c", message[i]);
	}
	for(int i = 0; i < parityLength; i++){
		printf("%c", parityBits[i]);
	}
	printf("\n");
}

void receiveMessage(){
	char message[MAX_SIZE];
	int choice = 1;
	printf("Enter the message: ");
	scanf("%s", message);
	printf("Choose the Parity\n");
	printf("1. Odd Parity\n");
	printf("2. Even Parity\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	int messageLength = strlen(message);
	int parityLength = messageLength / 4 - 1;
	char parityBits[parityLength];
	int k = 0;
	int flag = 0;
	for(int i = messageLength - 4; i < messageLength; i++){
		parityBits[k] = message[i];
		k++;
	}
	printf("Parity:\n");
	for(int i = 0; i < parityLength; i++){
		printf("%c", parityBits[i]);
	}
	printf("\n");
	k = 0;
	for(int i = 0; i < (messageLength / 4) - 1; i +=4){
		int count = 0;
		for(int j = 0; j < (messageLength / 4) - 1; j++){
			int index = j * 4 + i;
			if(message[index] == '1'){
				count++;
			}
		}
		if(parityBits[k] == '1'){
			count++;
		}
		k++;
		if(choice == 1){
			if(count%2 == 0){
				flag = 1;
				break;
			}
		}else if(choice == 2){
			if(count%2 == 1){
				flag = 1;
				break;
			}
		}
	}
	if(flag == 1){
		printf("Message is corrupted.\n");
	}else{
		printf("Message if fine.\n");
	}
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
				case 3: printf("Program is exited.\n");
								// exit(0);
								break;
				default: printf("Enter the correct choice.\n");
								break;
			}
		}
	return 0;
} 