#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 9001
#define MAX_SIZE 1023

int main(){
	printf("\n\033[1;34m-----Stop and Wait Protocol-----\033[0m\n\n");
	int sockID;
	char message[MAX_SIZE];
	int acknowledgement;
	sockID = socket(AF_INET, SOCK_STREAM, 0);
	if(sockID == -1){
		printf("Socket connection failed.\n");
		exit(1);
	}
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(PORT);
	if((connect(sockID, (struct sockaddr *)&server, sizeof(server))) != 0){
		printf("Connection with server failed\n");
		exit(1);
	}
	printf("Connected to server...!\n");
	printf("Enter the message to send: ");
	scanf("%s", message);
	for(int i = 0; message[i] != '\0'; i++){
		write(sockID, &message[i], sizeof(char));
		read(sockID, &acknowledgement, sizeof(int));
		if(acknowledgement == 0)
		{
			i--;
			printf("\033[0;33mRetransmitting packet - %d [i] : %c [char]\n\033[0m", i+1, message[i+1]);
		}
	}
	char ch = '\0';
	END:
		write(sockID, &ch, sizeof(char));
		read(sockID, &acknowledgement, sizeof(int));
		if(acknowledgement == 0)
			goto END;
		printf("Message is sent.\n");
	return 0;
}