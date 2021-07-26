/* 3. Create a Linked List of N students. Each student node will have roll, per 
      of marks, and the corresponding grade. The roll will vary from 1 to N. Percentage 
      of marks will be taken as a random input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int rollno = 1, node_number = 1, n; //initialsing static variables as to cant lose them

//Structure to store student data
struct node
{
  int roll;
  int per;
  char grade;
  struct node *link;
};

//Grade function which returns character grade taking percentage as input
char grade(int per)
{
  if (per >= 90)
    return 'A';
  else if (per >= 80)
    return 'B';
  else if (per >= 70)
    return 'C';
  else if (per >= 60)
    return 'D';
  else if (per >= 50)
    return 'E';
  else if (per >= 35)
    return 'P';
  else
  {
    return 'F';
  }
}
//connect function takes head and inserts a node at begining ah returns the address of new head

struct node *connect(struct node *head, int roll, int per, char grade)
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->roll = roll;
  ptr->per = per;
  ptr->grade = grade;
  ptr->link = NULL;

  ptr->link = head;
  head = ptr;
  return head;
}
//function to print the elements of the linked list

void printList(struct node *head)
{
  struct node *current = head;

  printf("\nRoll no.  Percentage  Grade\n");
  while (current != NULL)
  {
    printf("%d          %d           %c\n", current->roll, current->per, current->grade);
    current = current->link;
  }
}
int main()
{
  srand(time(NULL));
  struct node *first = (struct node *)malloc(sizeof(struct node));
  struct node *nodeA = (struct node *)malloc(sizeof(struct node));
  struct node *nodeB = (struct node *)malloc(sizeof(struct node));
  struct node *nodeC = (struct node *)malloc(sizeof(struct node));
  struct node *nodeD = (struct node *)malloc(sizeof(struct node));
  struct node *nodeE = (struct node *)malloc(sizeof(struct node));
  struct node *nodeP = (struct node *)malloc(sizeof(struct node));
  struct node *nodeF = (struct node *)malloc(sizeof(struct node));
  struct node *grade_sheet[] = {nodeA, nodeB, nodeC, nodeD, nodeE, nodeP, nodeF};
  nodeA = NULL;
  nodeB = NULL;
  nodeC = NULL;
  nodeD = NULL;
  nodeE = NULL;
  nodeP = NULL;
  nodeF = NULL;
  printf("\nEnter the number of students in the class: ");
  scanf("%d", &n);
  struct node *ptr = first;
  ptr->roll = rollno;
  ptr->per = rand() % 100;
  ptr->grade = grade(ptr->per);
  switch (ptr->grade)
  {
  case 'A':
    nodeA = connect(nodeA, ptr->roll, ptr->per, ptr->grade);
    break;
  case 'B':
    nodeB = connect(nodeB, ptr->roll, ptr->per, ptr->grade);
    break;
  case 'C':
    nodeC = connect(nodeC, ptr->roll, ptr->per, ptr->grade);
    break;
  case 'D':
    nodeD = connect(nodeD, ptr->roll, ptr->per, ptr->grade);
    break;
  case 'E':
    nodeE = connect(nodeE, ptr->roll, ptr->per, ptr->grade);
    break;
  case 'P':
    nodeP = connect(nodeP, ptr->roll, ptr->per, ptr->grade);
    break;
  case 'F':
    nodeF = connect(nodeF, ptr->roll, ptr->per, ptr->grade);
    break;
  }
  rollno += 1; //increasing static variable
  ptr->link = NULL;
  for (node_number = 2; node_number <= n; node_number++)
  {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    ptr->link = temp;
    ptr = temp; //changing head position to next element
    ptr->per = rand() % 100;
    ptr->grade = grade(ptr->per);
    ptr->roll = rollno;
    switch (ptr->grade)
    {
    case 'A':
      nodeA = connect(nodeA, ptr->roll, ptr->per, ptr->grade);
      break;
    case 'B':
      nodeB = connect(nodeB, ptr->roll, ptr->per, ptr->grade);
      break;
    case 'C':
      nodeC = connect(nodeC, ptr->roll, ptr->per, ptr->grade);
      break;
    case 'D':
      nodeD = connect(nodeD, ptr->roll, ptr->per, ptr->grade);
      break;
    case 'E':
      nodeE = connect(nodeE, ptr->roll, ptr->per, ptr->grade);
      break;
    case 'P':
      nodeP = connect(nodeP, ptr->roll, ptr->per, ptr->grade);
      break;
    case 'F':
      nodeF = connect(nodeF, ptr->roll, ptr->per, ptr->grade);
      break;
    }
    rollno += 1;
    ptr->link = NULL;
  }

  printf("\nInitial student data: \n");
  printList(first);
  printf("\nSorted student data: \n");
  printf("\nGRADE A:\n");
  printList(nodeA);
  printf("\nGRADE B:\n");
  printList(nodeB);
  printf("\nGRADE C:\n");
  printList(nodeC);
  printf("\nGRADE D:\n");
  printList(nodeD);
  printf("\nGRADE E:\n");
  printList(nodeE);
  printf("\nGRADE P:\n");
  printList(nodeP);
  printf("\nGRADE F:\n");
  printList(nodeF);

  free(first);
  free(nodeA);
  free(nodeB);
  free(nodeC);
  free(nodeD);
  free(nodeE);
  free(nodeP);
  free(nodeF);

  return 0;
}
