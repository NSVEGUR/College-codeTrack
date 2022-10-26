#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("\n\033[1;34m-----Go Back N-----\033[0m\n\n");
  int sockID, receive;

  sockID = socket(AF_INET, SOCK_STREAM, 0);

	if(sockID == -1){
		printf("Socket connection failed.\n");
		exit(1);
	}


  struct sockaddr_in server, other;

  server.sin_family = AF_INET;

  server.sin_port = htons(9001);

  server.sin_addr.s_addr = INADDR_ANY;

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

  int connectionID;
  connectionID = accept(sockID, NULL, NULL);
	if(connectionID == -1){
		printf("Socket connection failed.\n");
		exit(1);
	}
	printf("Server is connected to a client with connectionID %d.\n", connectionID);
  int i = 0, k = 0, l = 0, tFrames = 0, windowSize = 0;
  int message[20];
  int acknowledgement[20];

  receive = read(connectionID, (char *)&tFrames, sizeof(tFrames));
  receive = read(connectionID, (char *)&windowSize, sizeof(windowSize));
  int choice;

  while (i < tFrames)
  {
    k = 0;
    receive = read(connectionID, (char *)&message, sizeof(message));

    while (k < windowSize && i < tFrames)
    {

      printf("\nPress 1 for acknowledgment for %d to send.", message[k]);
      printf("\nPress -1 for acknowledgment for %d not to send.", message[k]);
      printf("\nEnter the choice: ");
      scanf("%d", &choice);
      if (choice == 1)
      {
        acknowledgement[k] = message[k];
      }
      if (choice == -1)
      {
        acknowledgement[k] = -1;
        i = message[k];
        printf("\nAcknowledge Not sent for %d ", message[k]);
        i = message[k];
        break;
      }
      k++;
      i++;
    }
    printf("\n");

    write(connectionID, (char *)&acknowledgement, sizeof(acknowledgement));
  }
  printf("\n All Frames have been Received Successfully. \n");
  close(sockID);
  return 0;
}