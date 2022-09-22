#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
	int client_sock;
	char message[256] = "Hello Server this is client Vegur!\n";
	client_sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in client, other;
	client.sin_family = AF_INET;
	client.sin_port = htons(9001);
	client.sin_addr.s_addr = inet_addr("172.16.0.2");
	socklen_t ad = sizeof(other);
	sendto(client_sock, message, sizeof(message), 0, (struct sockaddr*)&client, sizeof(client));
	printf("Client side message: %s\n", message);
	close(client_sock);
	return 0;
}