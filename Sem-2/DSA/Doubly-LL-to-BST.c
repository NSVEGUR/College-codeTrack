//NAME: V NAGASAI
//ROLL: CS20B1016

//LAB NUMBER: 09

/*1. Create a doubly Linked List (Two-way Linked List) from the Calander month names (January,
     February, March........December). Convert this to it's corresponding balanced Binary Search
     Tree (BST). Perform the In-order traversal.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list
{
  char *month;
  struct list *next;
  struct list *prev;
};

int count = 1; //for months

char *mon(int i)
{
  switch (i)
  {
  case 1:
    return "January";
    break;
  case 2:
    return "Febrauary";
    break;
  case 3:
    return "March";
    break;
  case 4:
    return "April";
    break;
  case 5:
    return "May";
    break;
  case 6:
    return "June";
    break;
  case 7:
    return "July";
    break;
  case 8:
    return "August";
    break;
  case 9:
    return "September";
    break;
  case 10:
    return "October";
    break;
  case 11:
    return "November";
    break;
  case 12:
    return "December";
    break;
  default:
    return "error-no-month";
    break;
  }
}

void printlist(struct list *head) //to print the list
{
  while (head != NULL)
  {
    printf(" %s ", head->month);
    head = head->next;
  }
  printf("\n");
}

//creation of doubly linked list witj al 12 months
void create_list(struct list *head)
{
  head->prev = NULL;
  head->month = mon(count);
  ++count;
  head->next = NULL;
  while (count <= 12)
  {
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    head->next = temp;
    temp->prev = head;
    temp->month = mon(count);
    temp->next = NULL;
    head = temp;
    ++count;
  }
}

//Recursive function to create tree from linked list
struct list *sortedListToBSTRecur(struct list **head, int n)
{
  /* Base Case */
  if (n <= 0)
    return NULL;

  /* Recursively construct the left subtree */
  struct list *left = sortedListToBSTRecur(head, n / 2);

  /* head now refers to middle list, make middle list as root of BST*/
  struct list *root = *head;

  // Set pointer to left subtree
  root->prev = left;

  /* Change head pointer of Linked List for parent recursive calls */
  *head = (*head)->next;

  /* Recursively construct the right subtree and link it with root
      The number of lists in right subtree  is total lists - lists in
      left subtree - 1 (for root) */
  root->next = sortedListToBSTRecur(head, n - n / 2 - 1);

  return root;
}

//printing the tree in inorder
void inorder(struct list *root)
{
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->prev);           // visiting left child
    printf(" %s \n", root->month); // printing data at root
    inorder(root->next);           // visiting right child
  }
}

int main()
{
  struct list *head = (struct list *)malloc(sizeof(struct list));
  create_list(head);

  // printf("Doubly linked list: \n");
  // printlist(head);

  struct list *root = sortedListToBSTRecur(&head, 12);
  printf("\nInorder traversal: \n");

  inorder(root);

  printf("\n");

  return 0;
}
