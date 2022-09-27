#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	printf("\n-----CLIENT UDP-----\n\n");
	int sock;
	char phoneNumber[11], otpReceived[5], otpSent[5], otpResult[10];
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9001);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	//Sending Phone Number
	printf("Enter your 10 digit phone number: ");
	scanf("%s", phoneNumber);
	sendto(sock, phoneNumber, sizeof(phoneNumber), 0, (struct sockaddr *)&server, sizeof(server));
	//Receiving otp
	socklen_t len = sizeof(server);
	recvfrom(sock, otpReceived, sizeof(otpReceived), 0, (struct sockaddr *)&server, &len);
	printf("\nYour OTP is: %s\n", otpReceived);
	//Sending back otp
	printf("\nEnter the 4 digit otp to verify: ");
	scanf("%s", otpSent);
	sendto(sock, otpSent, sizeof(otpSent),0, (struct sockaddr *)&server, sizeof(server));
	//Result
	recvfrom(sock, otpResult, sizeof(otpResult), 0, (struct sockaddr *) &server, &len);
	printf("\nYour OTP is %s\n\n", otpResult);
	close(sock);
	return 0;
}