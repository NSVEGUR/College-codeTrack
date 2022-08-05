/*2. Create a two-way Linked List of N Fibonacci numbers. N should be given as user input.
     WAP to delete the nodes in the two-way linked list based on a given GP series. The factor of
     the GP series will be taken as an user input. (Ex: 1, 2, 4, 8, 16..... : Factor 2).
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int num;
  int data;
  struct node *forw;
  struct node *back;
};

//fibanocci recurssive function to calculate nth fibanocci number
int fib(int n)
{
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else
    return (fib(n - 1) + fib(n - 2));
}

//combined function of linked list creation and finding odd|even sum upto given input
void list(struct node *ptr, int n)
{
  int i = 1;
  struct node *current = ptr, *store = NULL;

  current->num = i;
  current->data = fib(i);
  current->back = NULL;
  current->forw = NULL;

  for (i = 2; i <= n; ++i)
  {
    struct node *temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
      printf("\nOut of memory");
      exit(0);
    }

    current->forw = temp;
    store = current;
    current = temp;
    current->back = store;

    current->num = i;
    current->data = fib(i); //assiging nth fibanocci number to linked list

    current->forw = NULL;
  }
}

//Function to print the updated linked list
void printlist(struct node *ptr)
{
  printf("\nData in the nodal list is:\n");
  struct node *current = ptr;

  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->forw;
  }

  printf("\n");
}

//Function to delete the nth index link
struct node *delete (struct node *ptr, int n, int factor)
{
  int i = 1;
  struct node *current = ptr;
  struct node *temp = NULL;
  i *= factor;
  while (current != NULL)
  {
    if (current->num == i)
    {
      current->forw->back = current->back;
      current->back->forw = current->forw;
      temp = current;
      current = current->forw;
      i *= factor;
      free(temp);
    }
    else
      current = current->forw;
  }
  return current;
}
//Main function
int main()
{
  int n, factor;

  struct node *head = NULL; //head of linked list
  struct node *temp = NULL;
  head = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nOut of memory");
    exit(0);
  }

  printf("Enter the value of n(number of fibanocci numbers): ");
  scanf("%d", &n); //taking input upto which fibanocci should be calculated

  list(head, n);

  printlist(head);

  printf("Enter the factor of GP on which you wanna delete the mentioned index : ");
  scanf("%d", &factor);

  //deleting the mentioned factorth element
  delete (head, n, factor);

  //Deleting the beginning element since we always delete first element
  temp = head;
  head = head->forw;
  head->back = NULL;
  free(temp);

  printf("\nList after deleting the mentioned factorth index: \n");
  printlist(head);

  free(head);
  return 0;
}