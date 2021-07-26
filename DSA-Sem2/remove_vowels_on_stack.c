/*2. Implement a character stack using Linked List. PUSH and POP operations should be clearly
     defined. WAP to take a random string as user-input. String should be a combination of
     alphabets and operators. Traverse through the string and do the following operations.
     • If a consonant is encounterd, PUSH to the stack.
     • If a vowel is encounterd, POP from the stack
     • Show the content of the top of the stack after each operation
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  char data;
  struct node *link;
};

struct node *top = NULL;
struct node *main_top = NULL;

int count = 0;

//Push function pushes the input char into the top stack and also moves main_top stack to next
void push(char ch)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("Overflow");
    exit(0);
  }
  temp->data = ch;
  temp->link = top;
  top = temp;
  main_top = main_top->link;
}

//This creates a string input and stores it into a stack unless a enter is given
void create()
{
  char ch = 'd';

  printf("Enter a string(else enter to exit scanning): ");

  while (ch != '\n')
  {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    scanf("%c", &ch);
    temp->data = ch;
    temp->link = main_top;
    main_top = temp;
    ++count;
  }
}

//This pops out that is deletes the top node of main_top struct
void pop()
{

  if (main_top == NULL)
  {
    printf("UNDERFLOW");
    exit(0);
  }
  printf("\n//%c is Popped//\n", main_top->data);
  main_top = main_top->link;
}

//This prints the new top list
void printlist()
{
  struct node *temp = top;
  printf("\nStack after a push: ");
  while (temp != NULL)
  {
    printf("%c ", temp->data);
    temp = temp->link;
  }
}

//This takes character as a input and returns 1 or 0 depending upon it is vowel or not
int vowel(char ch)
{
  char arr[] = {'a',
                'e',
                'i',
                'o',
                'u',
                'A',
                'E',
                'I',
                'O',
                'U'};

  for (int i = 0; i < 10; ++i)
  {
    if (ch == arr[i])
      return 1;
  }

  return 0;
}

//This creates a way to all the vowel pop and push functions depending upon our need
void check_stack()
{
  while (count)
  {
    if (vowel(main_top->data))
    {
      pop(); //pops if vowel is found
      printlist();
    }
    else
    {
      push(main_top->data); //pushes into new top list if its consonant
      printlist();
    }
    --count;
  }
}

//main function
int main()
{
  create();      //creates the stack of input string
  check_stack(); //solves the problem linking push pop and vowel functions
  return 0;
}