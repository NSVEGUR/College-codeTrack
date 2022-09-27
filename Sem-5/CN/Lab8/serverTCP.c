#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 9001


int main(){
	printf("\n-----SERVER TCP-----\n\n");
	int sock, connection;
	struct sockaddr_in server, client;
	char phoneNumber[11], otpGenerated[5], otpReceived[5], otpResult[10];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		printf("Socket creation failed.\n");
		exit(0);
	}
	bzero(&server, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);

	if((bind(sock, (struct sockaddr*)&server, sizeof(server))) != 0){
		printf("Binding Socket failed.\n");
		exit(0);
	}

	if((listen(sock, 5))!= 0){
		printf("Listening failed.\n");
		exit(0);
	}

	socklen_t len = sizeof(client);
	connection = accept(sock, (struct sockaddr*)&client, &len);
	if(connection < 0){
		printf("Server Accept failed.\n");
		exit(0);
	}
	printf("Accepting requests from client.\n");

	//Receiving Phone Number
	read(connection, phoneNumber, sizeof(phoneNumber));
	printf("\nReceived Phone Number: %s\n", phoneNumber);
	//Sending otp
	for(int i = 0; i < 4; i++){
		int x = rand()%10;
		otpGenerated[i] = x + '0';
	}
	otpGenerated[4] = '\0';
	write(connection, otpGenerated, sizeof(otpGenerated));
	printf("\nOTP sent\n");
	//verifying otp
	read(connection, otpReceived, sizeof(otpReceived));
	printf("\nOTP sent by client: %s\n", otpReceived);
	int result = strcmp(otpGenerated, otpReceived);
	if(result == 0){
		strcpy(otpResult, "Valid");
	}else{
		strcpy(otpResult, "Invalid");
	}
	//Sending back result
	write(connection, otpResult, sizeof(otpResult));
	printf("\nResult sent back\n");
	close(sock);
	return 0;
}