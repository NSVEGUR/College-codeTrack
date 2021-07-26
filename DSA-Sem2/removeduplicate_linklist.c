//NAME: V NAGASAI
//ROLL: CS20B1016

//LAB NUMBER: 04

/* 1.Create a Linked List of size N, where each node will have a random character 
     and pointer to the next node. N should be given as user input. WAP to remove 
     the duplicate characters from the list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
  char data;
  struct node *link;
};

//Function to create linked list with given number of inputs using rand function
void Createlist(struct node *ptr, int n)
{
  int count = 1, flag = 1;

  struct node *current = ptr;

  current->data = 'A' + (rand() % 26);
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

    current->data = 'A' + (rand() % 26);

    current->link = NULL;
    --n;
  }
}

//Function to print the updated linked list
void printlist(struct node *ptr)
{
  printf("\nData in the nodal list is:\n");
  struct node *current = ptr;

  while (current != NULL)
  {
    printf("%c ", current->data);
    current = current->link;
  }

  printf("\n");
}

//Function to remove duplicate elements
void removecopy(struct node *ptr)
{
  struct node *i, *j, *save;

  //Using asusual selection sort algorithm to travrese linked list with two loops
  for (i = ptr; i != NULL; i = i->link)
  {
    save = i; //to start from begin
    for (j = i->link; j != NULL; j = j->link)
    {
      if (i->data == j->data) //deleting the duplicate
      {
        save->link = j->link;
        save = j->link;
      }
      else
        save = j; //to continue along inner loop
    }
  }
}

//Main function
int main()
{
  int n;

  struct node *head = NULL;

  head = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nOut of memory");
    exit(0);
  }

  printf("Enter the value of n: ");
  scanf("%d", &n);

  Createlist(head, n);

  printlist(head);

  removecopy(head);

  printlist(head);

  free(head);
  return 0;
}