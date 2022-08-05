//NAME: V NAGASAI
//ROLL: CS20B1016

//LAB NUMBER: 06

/*1. Implement an integer stack using Linked List. PUSH and POP operations should be clearly
     defined. WAP to calculate the factorial of a number N using the above defined stack. The
     number N should be taken as an user input.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

struct node *top = NULL;

//Pushes the given data to the stack
void push(int i)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("Overflow");
    exit(0);
  }
  temp->data = i;
  temp->link = top;
  top = temp;
}

//pops out the top element every time in the stack till its empty & returns the data in that top element
int pop()
{
  int item;

  if (top == NULL)
  {
    printf("UNDERFLOW");
    exit(0);
  }

  item = top->data;
  top = top->link;

  return item;
}

int main()
{
  int n, i, product = 1;
  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (i = n; i >= 1; --i) //starting with n at the bottom fills the stack till it reaches 1
    push(i);

  i = n;

  while (i) //calls the pop and multiplies the returned value with product each time
  {
    product *= pop();
    --i;
  }

  printf("\n%d! = %d\n", n, product); //prints the output

  return 0;
}