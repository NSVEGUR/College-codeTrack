/* 2. Create a Linked List of N Fibonacci numbers. N should be given as user input. 
      WAP to find the summation of odd and even Fibonacci numbers in the series. 
      The program should be run in one pass (only one for/while loop in the entire program).
 */

#include <stdio.h>
#include <stdlib.h>

//structre node for link list
struct node
{
  int data;
  struct node *link;
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
void list(struct node *ptr, int n, int *oddsum, int *evensum)
{
  int i = 1;
  struct node *current = ptr;

  current->data = fib(i);
  current->link = NULL;

  for (i = 2; i <= n; ++i)
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

    current->data = fib(i); //assiging nth fibanocci number to linked list

    //asusual reminder of 2 if condition for seperation of odd|even
    if ((current->data) % 2 != 0)
      *oddsum = *oddsum + current->data;
    else
      *evensum = *evensum + current->data;

    current->link = NULL;
  }
}

//Main function
int main()
{
  int n, i = 1;
  int oddsum = 0, evensum = 0;

  struct node *head = NULL; //head of linked list

  head = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nOut of memory");
    exit(0);
  }

  printf("Enter the value of n(number of fibanocci numbers): ");
  scanf("%d", &n); //taking input upto which fibanocci should be calculated

  list(head, n, &oddsum, &evensum);

  printf("\nsum of odd number in fib series is: %d\n", oddsum);
  printf("sum of even numbers in fib series is: %d\n", evensum);

  free(head);
  return 0;
}