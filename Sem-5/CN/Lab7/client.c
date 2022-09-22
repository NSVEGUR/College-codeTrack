#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
	int sock;
	char phoneNumber[11], otp[5];
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9001);
	server.sin_addr.s_addr = INADDR_ANY;
	printf("Enter your phone number[10 chars]: ");
	scanf("%s", phoneNumber);
	sendto(sock, phoneNumber, sizeof(phoneNumber), 0, (struct sockaddr *)&server, sizeof(server));
	printf("Phone number sent from client is: %s\n", phoneNumber);
	socklen_t len = sizeof(server);
	recvfrom(sock, otp, sizeof(otp), 0, (struct sockaddr *)&server, &len);
	printf("Otp received from server is: %s\n", otp);
	close(sock);
	return 0;
}