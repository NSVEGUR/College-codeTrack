//NAME: V NAGASAI
//ROLL: CS20B1016

//LAB NUMBER: 08

/*1. Create an integer Binary Tree (height>=3) of your choice using Linked List. Fill the integers
     randomly. After creation of the Tree, Write the recursive functions for Pre-Order, In-Order and
     Post-Order traversals. While traversing, find the Mean and Standard Deviation of the elements
     in the tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float sum = 0, count = 0; // declaring sum and count as global variables
struct tree               // declaring binary tree
{
  int data;
  struct tree *leftchild;
  struct tree *rightchild;
};
struct tree *newnode() // function for inserting a new node
{
  struct tree *p;
  p = (struct tree *)(malloc(sizeof(struct tree)));
  p->data = rand() % 100;
  p->leftchild = NULL;
  p->rightchild = NULL;
  return p;
}

void preorder(struct tree *root)
{
  if (root != NULL) // checking if the root is not null
  {
    printf(" %d ", root->data); // printing data at root
    sum = sum + root->data;
    count++;
    preorder(root->leftchild);  // visiting left child
    preorder(root->rightchild); // visiting right child
  }
}

void inorder(struct tree *root)
{
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->leftchild);   // visiting left child
    printf(" %d ", root->data); // printing data at root
    inorder(root->rightchild);  // visiting right child
  }
}

void postorder(struct tree *root)
{
  if (root != NULL) // checking if the root is not null
  {
    postorder(root->leftchild);  // visiting left child
    postorder(root->rightchild); // visiting right child
    printf(" %d ", root->data);  // printing data at root
  }
}

int main()
{
  float n = 0;
  float stddev, mean, val;
  srand(time(NULL));

  struct tree *root;
  root = newnode();
  root->leftchild = newnode();
  root->rightchild = newnode();
  root->leftchild->leftchild = newnode();
  root->rightchild->leftchild = newnode();
  root->leftchild->rightchild = newnode();
  root->rightchild->rightchild = newnode();

  printf("\n--------------Pre-order:--------------\n\n");
  // printing tree in pre-order way that is root is printed first then left child then right child
  preorder(root);
  printf("\n");

  printf("\n----------------In-order:------------\n\n");
  // printing tree in in-order way that is left child is printed first then root then right child
  inorder(root);
  printf("\n");

  printf("\n---------------Post-order:------------\n\n");
  //printing tree in post-order way that is left child is printed first then right child then root
  postorder(root);
  printf("\n\n");

  n = count; // no of elements in the tree
  mean = sum / n;

  printf("\033[1;37m-------------mean = %.2f--------------\n", mean); // printing mean of elements in the tree

  val = (((sum * sum) / n) - (mean * mean));
  stddev = sqrt(val);

  printf("------standard deviation = %.2f------\033[0m\n\n", stddev);
  // printing standard deviation of elements in the tree
  return 0;
}