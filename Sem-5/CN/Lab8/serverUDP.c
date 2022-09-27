#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<time.h>
#include<string.h>

int main(){
	printf("\n-----SERVER UDP-----\n\n");
	int sock;
	time_t t;
	srand((unsigned)time(&t));
	char phoneNumber[11], otpGenerated[5], otpReceived[5], otpResult[10];
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server, client;
	server.sin_family = AF_INET;
	server.sin_port = htons(9001);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	//Binding server
	bind(sock, (struct sockaddr *)&server, sizeof(server));
	//Receiving Phone Number
	socklen_t len = sizeof(client);
	recvfrom(sock, phoneNumber, sizeof(phoneNumber), 0, (struct sockaddr*)&client, &len);
	printf("Received Phone Number: %s\n", phoneNumber);
	//Sending otp
	for(int i = 0; i < 4; i++){
		int x = rand()%10;
		otpGenerated[i] = x + '0';
	}
	otpGenerated[4] = '\0';
	sendto(sock, otpGenerated, sizeof(otpGenerated), 0, (struct sockaddr*)&client, sizeof(client));
	printf("\nOTP sent\n");
	//verifying otp
	recvfrom(sock, otpReceived, sizeof(otpReceived), 0, (struct sockaddr *)&client, &len);
	printf("\nOTP sent by client: %s\n", otpReceived);
	int result = strcmp(otpGenerated, otpReceived);
	if(result == 0){
		strcpy(otpResult, "Valid");
	}else{
		strcpy(otpResult, "Invalid");
	}
	//Sending back result
	sendto(sock, otpResult, sizeof(otpResult), 0, (struct sockaddr *)&client, sizeof(client));
	printf("\nResult sent back\n");
	close(sock);
	return 0;
}