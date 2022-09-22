#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
	int server_sock;
	char message[256];
	server_sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server, other;
	server.sin_family = AF_INET;
	server.sin_port = htons(9001);
	server.sin_addr.s_addr = INADDR_ANY;
	socklen_t ad = sizeof(other);
	bind(server_sock, (struct sockaddr *)&server, sizeof(server));
	recvfrom(server_sock, message, sizeof(message), 0, (struct sockaddr*)&other, &ad);
	printf("Message received at server Nagasai: %s\n", message);
	close(server_sock);
	return 0;
}