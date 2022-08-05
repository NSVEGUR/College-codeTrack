/*3. Evaluation of a Prefix expression using stack. Your program should do the following.
• User should take an infix expression as input
• WAP to convert this infix expression to Prefix expression
• WAP to evaluate the above Prefix expression using stack.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//structure to store stack of infix to prefix operation
struct node
{
  char data;
  struct node *link;
};

struct node *stack = NULL;

//structure to store stack of evalution operation
struct exp
{
  int num;
  struct exp *next;
};

struct exp *nums = NULL;

//Checks wheter the input char is mathematical operator or not | if yes returns 0 else 1
int operator(char ch)
{
  int flag = 0;

  char op[] = {'+', '-', '/', '*', '^', '(', ')'};
  for (int i = 0; i < 7; ++i)
  {
    if (ch == op[i])
      flag = 1;
  }

  if (flag)
    return 0; //since we check it for the operands in compliment manner it returns false if its operator
  else
    return 1;
}

//As we know since I use gcc compiler which doesn't include strrev() function I created it manually
void strrev(char *str)
{
  int i = 0;

  int j = strlen(str) - 1;

  char temp;

  while (i < j)
  {
    temp = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = temp;
    ++i;
    --j;
  }
}

//This is just to print the stack if needed but I didnt used it for main purpose
//Just used it to check the stack elements when needed
void printlist()
{
  printf("stack: \n");
  struct node *temp = stack;
  while (temp != NULL)
  {
    printf("%c", temp->data);
    temp = temp->link;
  }
  printf("\n");
}

//Asusual push function which pushes the given data into new node and attaches it to the main stack
void push(char ch)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("Overflow");
    exit(0);
  }
  temp->data = ch;
  temp->link = stack;
  stack = temp;
  //printlist();
}

//This is the push function to push elements into the stack of evaluation
void push_num(int n)
{
  struct exp *temp = (struct exp *)malloc(sizeof(struct exp));
  if (temp == NULL)
  {
    printf("Overflow");
    exit(0);
  }
  temp->num = n;
  temp->next = nums;
  nums = temp;
  //printlist();
}

//Pop function which pops up the charcter in the inf-pref operation and returns the char
char pop()
{
  if (stack == NULL)
  {
    printf("UNDERFLOW");
    exit(0);
  }
  char ch;
  ch = stack->data;
  stack = stack->link;
  return ch;
}

//Pop function which pops up the integer in the evaluation operation and returns the int
int pop_num()
{
  if (nums == NULL)
  {
    printf("UNDERFLOW");
    exit(0);
  }
  int n;
  n = nums->num;
  nums = nums->next;
  return n;
}

//Function which checks the precedence or priority of the input mathematical operator
int precedence(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '^')
    return 3;
  if (ch == '(' || ch == ')')
    return 4;
}

//Function which converts the given infix to prefix
void prefix(char *str, char *exp)
{
  strrev(str); //since its prefix operation we will reverse and then will do postfix algorithm and then reverse the obtained

  //printf("Reversed string: %s\n", str);

  int s = 0, e = 0;

  for (s = 0; s < strlen(str); ++s)
  {
    //since we do based on postfix algorithm we reverse the ( to ) & vice versa
    if (*(str + s) == '(')
    {
      *(str + s) = ')';
      //printf("reversed '(' to ')'\n");
    }
    else if (*(str + s) == ')')
    {
      *(str + s) = '(';
      //printf("reversed ')' to '('\n");
    }

    //printf("char at loop start: %c\n", *(str + s));
    if (operator(*(str + s))) //if its a number or any other alphabet print it into the expression part
    {
      *(exp + e) = *(str + s);
      //printf("expression: %c\n", *(exp + e));
      ++e;
    }
    else if (*(str + s) == '(')
    {
      //printf("pushable: %c\n", *(str + s));
      push(*(str + s));
    }
    else if (*(str + s) == ')')
    {
      do
      {
        *(exp + e) = pop();
        //printf("expression: %c\n", *(exp + e));
        ++e;

      } while (stack->data != '(');
      pop();
    }
    else //if (*(str + s) == '+' || *(str + s) == '-' || *(str + s) == '/' || *(str + s) == '*' || *(str + s) == '^')
    {
      if (stack == NULL)
      {
        //printf("pushable: %c\n", *(str + s));
        push(*(str + s)); //if stack is null then it pushes the operator into the stack directly without worrying about precedence
      }
      else if (precedence(*(str + s)) > precedence(stack->data))
      {
        //printf("stack data: %c\n", stack->data);
        //printf(" p > stack pushable: %c\n", *(str + s));
        push(*(str + s));
        //if presedence of the given operator is greater than the one in stack it just pushes into stack
      }
      else if (precedence(*(str + s)) == precedence(stack->data) && *(str + s) == '^')
      {
        while (precedence(*(str + s)) == precedence(stack->data) && *(str + s) == '^')
        {
          *(exp + e) = pop();
          //printf("expression: %c\n", *(exp + e));
          ++e;
          //printf("stack data: %c", stack->data);
          //This loops goes on still the condition is true
        }
      }
      else if (precedence(*(str + s)) == precedence(stack->data))
      {
        //printf("stack data: %c\n", stack->data);
        //printf(" p == stack pushable: %c\n", *(str + s));
        push(*(str + s));
        //if its just equal push into the stack
      }
      else if (precedence(*(str + s)) < precedence(stack->data))
      {
        if (stack->data == '(')
        {
          //printf("stack data: %c\n", stack->data);
          //printf("p < stack pushable: %c\n", *(str + s));
          push(*(str + s));
          continue;
          //since we need to igone '(' this even precedence is higher as it is closer just continue the loop
        }
        do
        {

          *(exp + e) = pop();
          ++e;
          //printf("expression: %c\n", *(exp + e));
          //This goes on repeating till precedence condtion gets false or stack becomes null
        } while (stack != NULL && precedence(*(str + s)) < precedence(stack->data));

        //printf("p < stack pushable: %c\n", *(str + s));
        push(*(str + s)); //after this popping finally push the operator to stack
        //printf("stack data: %c\n", stack->data);
      }
    }
  }

  //printf("%s\n", exp);

  --e; //due to its array and to maintain the memory

  while (stack != NULL)
  {
    ++e;
    *(exp + e) = pop();
    //printf("expression: %c\n", *(exp + e));
  }

  ++e;

  *(exp + e) = '\0'; //provides the end to the string which avoids garbages

  //printf("%s\n", exp);
  strrev(exp);

  //printf("\n");
}

//This function just returns the value based on input int values and the operator by just doing mathematical operations
int expression(int A, char ch, int B)
{
  if (ch == '+')
    return (A + B);
  if (ch == '-')
    return (A - B);
  if (ch == '*')
    return (A * B);
  if (ch == '/')
    return (A / B);
  if (ch == '^')
    return (pow(A, B));
}

//Function which evaluates the prefix which made manually
int evaluate(char *exp)
{
  int value;

  int temp; //to store the atoi() return

  char test; //to store current character

  strrev(exp);
  //printf("Reversed prefix: %s", exp);
  for (int i = 0; i < strlen(exp); ++i)
  {
    if (operator(*(exp + i)))
    {
      test = *(exp + i);
      //printf("test: %c\n", test);
      temp = atoi(&test);
      push_num(temp); //if its number just push it into new num stack
      //printf("temp: %d\n", temp);
    }
    else
    {

      //if its operator take out above two nums of num stack and perform the mathematical operation
      value = expression(nums->num, *(exp + i), nums->next->num);
      pop_num();
      pop_num(); //pops the operated top elements
      //printf("value: %d\n", value);
      push_num(value); //pushes the result of operation into num stack
    }
  }
  return value;
}

//allocates the size to the expression to ignore the memory and garbage value problems
int sizer(char *str)
{
  int size = 0, i;
  for (i = 0; i < strlen(str); ++i)
  {
    if (*(str + i) == '(' || *(str + i) == ')')
      continue; //since ) and ( are not required in prefix or postfix notation
    ++size;
  }
  return size;
}

int main()
{
  char str[1000];
  printf("Enter the infix: ");
  scanf("%s", str); //Enter the input string which contains charactrical digits
  //printf("%s", str);
  char exp[sizer(str)];
  //printf("sizer gave: %d\n", sizer(str));
  prefix(str, exp);
  printf("\n");
  printf("Prefix of the entered infix is: ");
  printf("%s\n", exp); //printf the prefix
  printf("\n");
  int answer = evaluate(exp);
  printf("Answer after evaluation: %d\n", answer); //prints the answer
  printf("\n");
  return 0;
}