#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  int sockID, sending;
	printf("\n\033[1;34m-----Go Back N-----\033[0m\n\n");


  sockID = socket(AF_INET, SOCK_STREAM, 0);

	if(sockID == -1){
		printf("Socket connection failed.\n");
		exit(1);
	}

  struct sockaddr_in server;

  server.sin_family = AF_INET;

  server.sin_port = htons(9001);

  server.sin_addr.s_addr = INADDR_ANY;

  if((connect(sockID, (struct sockaddr *)&server, sizeof(server))) != 0){
		printf("Connection with server failed\n");
		exit(1);
	}

  int tFrames = 0, windowSize = 0, i = 0, j = 0, windowCount = 1, l = 0, k, temp;
  printf("Enter the Total No of Frames");
  scanf("%d", &tFrames);
  write(sockID, &tFrames, sizeof(tFrames));
  printf("Enter the Window Size");
  scanf("%d", &windowSize);
  write(sockID, &windowSize, sizeof(windowSize));
  int frames[20];
  int ack[20];

  while (i < tFrames)
  {
    printf("\nSending the %d Window with frames: ", windowCount);
    j = 0;
    temp = i;

    while (j < windowSize && i < tFrames)
    {
      printf(" %d ", i);
      frames[j] = i;
      j++;
      i++;
    }

    printf("\n");

    write(sockID, &frames, sizeof(frames));

    printf("\n--------Frames sent SuccessFully--------");
    printf("\n--------Now Waiting for Acknowledgement-------");
    sending = read(sockID, (char *)ack, sizeof(ack));

    j = 0;
    k = temp;
    l = 0;
    printf("\n");
    while (j < windowSize && k < tFrames)
    {
      if (ack[j] == -1)
      {
        printf("\nAcknowledgement is not received for %d frame. ", frames[j]);
        printf("\n Retransmiting again from Frame %d ", frames[j]);
        i = frames[j];
        l = 1;
        break;
      }
      k++;
      j++;
    }
    if (l == 0)
    {
      printf("\nAcknowledgment is received for Frame %d So the frames before this %d all are recieved by reciever. ", frames[j - 1], frames[j - 1]);
      printf("\n Now sending the Remaining Frames. ");
    }
    windowCount++;
  }
  printf("\nAll Frames hav been sent to server Successfully.");

  close(sockID);
  return 0;
}
