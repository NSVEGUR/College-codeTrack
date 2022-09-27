#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>


#define PORT 9001

int main(){
	int sock, connection;
	struct sockaddr_in server;
	char phoneNumber[11], otpReceived[5], otpSent[5], otpResult[10];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		printf("Socket creation failed.\n");
		exit(0);
	}
	bzero(&server, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(PORT);

	if((connect(sock, (struct sockaddr *)&server, sizeof(server))) != 0){
		printf("Connection with server failed\n");
		exit(0);
	}

	printf("Connected to server.\n");

	//sending phone number
	printf("\nEnter your 10 digit phone number: ");
	scanf("%s", phoneNumber);
	write(sock, phoneNumber, sizeof(phoneNumber));
	//receiving otp
	read(sock, otpReceived, sizeof(otpReceived));
	printf("\nYour OTP is: %s\n", otpReceived);
	//Sending back otp
	printf("\nEnter the 4 digit otp to verify: ");
	scanf("%s", otpSent);
	write(sock, otpSent, sizeof(otpSent));
	//Result
	read(sock, otpResult, sizeof(otpResult));
	printf("\nYour OTP is %s\n\n", otpResult);
	close(sock);
	return 0;
}