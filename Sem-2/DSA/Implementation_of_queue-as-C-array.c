//NAME: V NAGASAI
//ROLL: CS20B1016

//LAB NUMBER: 07

/*1. Implement a Circular QUEUE using an array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rear = -1, front = -1;

//function to insert in queue
void insert(int *queue, int max)
{
  srand(time(NULL)); //to change seed of rand with time

  if ((rear + 1) % max == front)
  {
    printf("Over flow\n");
  }
  else if (rear == -1 && front == -1)
  {
    front = rear = 0; //initial stage
    *(queue + rear) = rand() % 100;
  }
  else
  {
    rear = (rear + 1) % max;
    //mod max is for incrementing rear to 0 after reaching max-1 and so on
    *(queue + rear) = rand() % 100;
  }
}

int delete (int *queue, int max)
{

  int del = *(queue + front);

  if (rear == -1 && front == -1)
  {
    printf("Under flow\n");
  }
  else
  {
    front = (front + 1) % max;
    //same as mentioned above for rand if front reached max-1 to increment it to 0 and so on
  }

  return del;
}

void display(int *queue, int max)
{
  int i = front;

  if (front == -1 && rear == -1)
  {
    printf("Queue is empty!\n");
  }
  else if (front <= rear)
  //if front comes before rear in the array due to circular concept
  {
    printf("Queue read as: ");
    while (i <= rear)
    {
      printf("%d ", *(queue + i));
      ++i;
    }
    printf("\n");
  }
  else if (front > rear)
  //if front comes after rear due to circular concept
  {
    printf("Queue read as: ");

    while (i <= (max - 1))
    //1st case we print upto max-1
    {
      printf("%d ", *(queue + i));
      ++i;
    }
    i = 0;
    //to start from 1st index again in circular array
    while (i <= rear)
    //second case we print from 0 to rear
    {
      printf("%d ", *(queue + i));
      ++i;
    }
    printf("\n");
  }
}

int main()
{
  int max, choice = 1;

  printf("Enter the max value of the queue implemented by queue: ");
  scanf("%d", &max);

  int queue[max];

  while (choice != 0)
  {
    printf("Enter 1 to Insert data: \n");
    printf("Enter 2 to Delete the data: \n");
    printf("Enter 3 to Display the data: \n");
    printf("Enter 0 to exit out of data: \n");

    printf("\nchoice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 0:
      break;
    case 1:
      insert(queue, max);
      //inserts the random integer btw 1 to 100 into queue at rear end
      printf("\n");
      break;
    case 2:
      delete (queue, max);
      //deletes the data at the front end(actually in array it just changes the index of front)
      printf("\n");
      break;
    case 3:
      printf("\n");
      display(queue, max);
      //display data btw front and rear
      printf("\n");
      break;
    default:
      printf("\n");
      printf("-------------Enter a valid choice: ---------------\n\n");
      break;
    }
  }

  return 0;
}