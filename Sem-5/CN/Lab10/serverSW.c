#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<time.h>

#define PORT 9001
#define MAX_SIZE 1023

int main(){
	printf("\n\033[1;34m-----Stop and Wait Protocol-----\033[0m\n\n");
	int sockID, connectionID;
	srand(time(NULL));
	char message[MAX_SIZE];
	int acknowledgement;
	sockID = socket(AF_INET, SOCK_STREAM, 0);
	if(sockID == -1){
		printf("Socket creation failed.\n");
		exit(1);
	}
	struct sockaddr_in server, client;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);
	if(bind(sockID, (struct sockaddr *)&server, sizeof(server)) != 0)
	{
		printf("Socket binding failed.\n");
		exit(1);
	}
	if(listen(sockID,5) != 0){
		printf("Socket listening failed.\n");
		exit(1);
	}
	printf("Server is listening...!\n");
  socklen_t len = sizeof(client);
	connectionID = accept(sockID, (struct sockaddr *)&client, &len);
	if(connectionID == -1){
		printf("Socket connection failed.\n");
		exit(1);
	}
	printf("Server is connected to a client with connectionID %d.\n", connectionID);
	int i;
	read(connectionID, &message[0], sizeof(char));
	for(i = 0; message[i] != '\0'; ){
		//Generating random acknowledgement 0 or 1
		acknowledgement = rand() % 2;
		write(connectionID, &acknowledgement, sizeof(acknowledgement));
		if(acknowledgement == 1)
		{
			printf("\033[0;32mReceived packet - %d [i] : %c [char]\n\033[0m", i, message[i]);
			i++;
		}else{
			printf("\033[0;31mNot Received packet - %d [i].\n\033[0m", i);
		}
		read(connectionID, &message[i], sizeof(char));
	}
	printf("Complete message read from client is: %s\n", message);
	return 0;
}