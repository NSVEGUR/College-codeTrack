//NAME: V NAGASAI
//ROLL: CS20B1016

//LAB NUMBER: 05

/* 1. Create a Linked List of size N, where each node will have a random floating point value and
      pointer to the next node. WAP to reverse the linked list based on a given GP series. The
      factor of the GP series will be taken as an user input. (Ex: 1, 2, 4, 8, 16..... : Factor 2).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
  float data;
  struct node *link;
};

struct node *nextindex = NULL;
//Function to create linked list with given number of inputs using rand function
void Createlist(struct node *ptr, int n)
{
  srand(time(NULL));

  struct node *current = ptr;

  current->data = ((float)rand() / (float)(RAND_MAX)) * 22;
  current->link = NULL;

  --n;

  while (n)
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

    current->data = ((float)rand() / (float)(RAND_MAX)) * 22; //To assign random floating point integers
    current->link = NULL;

    --n;
  }
}

//Function to print the updated linked list
void printlist(struct node *ptr)
{
  struct node *current = ptr;

  while (current != NULL)
  {
    //printf(" %d - %.2f\n", current->num, current->data);
    printf("%.2f\n", current->data);

    current = current->link;
  }

  printf("\n");
}

//Funtion to reverse based on index
struct node *reverser(struct node *head, int factor, int fac)
{
  int count = 1;

  if (!head)
  {
    return NULL;
  }

  struct node *current = head; //to store current node
  struct node *next = NULL;    //For storing next node
  struct node *prev = NULL;    //For storing previous node

  // printf("count = %d\n", count);

  while (current != NULL && count <= factor)
  {

    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
    //printf("count = %d\n", count);
    ++count;
  }

  //printf("factor =  %d & fac = %d\n", factor, fac);
  if (head != NULL)
    head->link = reverser(next, (factor * fac), fac); //Through recursion linking the end of the reversed to the link part which we wanna reverse

  return prev;
}
//Main function
int main()
{
  int n, factor;
  static int fac;

  struct node *head = NULL;

  struct node *temp = NULL;

  head = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nOut of memory");
    exit(0);
  }

  printf("Enter the value of n(Number of elements in the list): ");
  scanf("%d", &n);

  printf("Enter the factor of GP on which you wanna reverse the list: ");
  scanf("%d", &factor);

  fac = factor;

  Createlist(head, n);

  printf("\nInitialised list before reversing based on index: \n");

  printlist(head);

  temp = head; //Since we send the second link of head -- to restore it

  temp = reverser(temp->link, factor, fac);

  head->link = temp; //restoring the head position which we don't need to reverse at all in any case

  printf("List after reversal based on index of given factor of terms: \n");

  printlist(head);

  free(head);
  free(temp);
  return 0;
}