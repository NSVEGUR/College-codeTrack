#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<time.h>

int main(){
	int sock;
	time_t t;
	srand((unsigned)time(&t));
	char phoneNumber[11], otp[5];
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server, client;
	server.sin_family = AF_INET;
	server.sin_port = htons(9001);
	server.sin_addr.s_addr = INADDR_ANY;
	socklen_t len = sizeof(client);
	bind(sock, (struct sockaddr *)&server, sizeof(server));
	recvfrom(sock, phoneNumber, sizeof(phoneNumber), 0, (struct sockaddr *)&client, &len);
	printf("Phone number received from client is: %s\n", phoneNumber);
	for(int i = 0; i < 4; i++){
		int x = rand()%10;
		otp[i] = x + '0';
	}
	otp[4] = '\0';
	sendto(sock, otp, sizeof(otp), 0, (struct sockaddr *)&client, sizeof(client));
	printf("Otp sent from server is: %s\n", otp);
	close(sock);
	return 0;
}