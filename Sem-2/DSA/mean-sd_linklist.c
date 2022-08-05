//QUESTION NUMBER - 03

//Program to print mean and standard deviation using linked lists

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//creating a structure node for link listing
struct node
{
  int data;
  struct node *link;
};

//Function to create link list
int Createlist(struct node *ptr)
{
  printf("Creation of linked list: \n");

  int count = 1, flag = 1;

  struct node *current = ptr;

  printf("\nEnter the %d nodal data: ", count);
  scanf("%d", &current->data);

  current->link = NULL;
  ++count;

  printf("\nTo stop scanning enter 0 else others: ");
  scanf("%d", &flag);

  while (flag)
  {
    struct node *temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
      printf("\nOut of memory");
      exit(0);
    }

    current->link = temp;
    current = temp;

    printf("\nEnter the %d nodal data: ", count);
    scanf("%d", &current->data);

    current->link = NULL;
    ++count;

    printf("\nTo stop scanning enter 0 else others: ");
    scanf("%d", &flag);
  }

    return (count - 1);
}

//Function to print the input list
void printlist(struct node *ptr)
{
  printf("\nData in the nodal list is:\n");
  struct node *current = ptr;

  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->link;
  }

  printf("\n");
}

//Function to sum up the data elements in link list
int Sum(struct node *ptr)
{
  int sum = 0;
  struct node *current = ptr;

  while (current != NULL)
  {
    sum = sum + current->data;
    current = current->link;
  }

  return sum;
}

//Function to sum the squares of elements in given link list
int Square(struct node *ptr)
{
  int sum = 0;
  struct node *current = ptr;

  while (current != NULL)
  {
    sum = sum + (current->data) * (current->data);
    current = current->link;
  }

  return sum;
}

//Main function
int main()
{
  int n;

  float mean, sd;

  struct node *head = NULL;

  head = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nOut of memory");
    exit(0);
  }

  n = Createlist(head);

  printlist(head);

  mean = Sum(head) / (float)n; //finding mean

  sd = (Square(head) / (float)n) - (mean * mean); //finding standard deviation

  sd = pow(sd, 0.5);

  printf("Mean of the given linked list: %f\n", mean);
  printf("Standard deviation of the given linked list: %f\n", sd);

  free(head);
  return 0;
}