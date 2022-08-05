/*2. Create a Complete Binary Tree made up of all the alphabets (A to Z) using Linked List. A is the
     root of the tree. B and C will be the left and right children of A, respectively, and so on. Write
     the recursive functions for Pre-Order, In-Order and Post-Order traversals to print the elements
    in the Tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct tree
{
  char data;
  struct tree *leftchild;
  struct tree *rightchild;
};

struct queue
{
  struct tree *address;
  struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

//enqueue function to add node to queue from rear end
void enqueue(struct tree *node)
{
  struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
  temp->address = node;
  if (front == NULL)
  {
    front = rear = temp;
    front->next = rear->next = NULL;
  }
  else
  {
    rear->next = temp;
    rear = temp;
    rear->next = NULL;
  }
  // printf("\nqueue:");
  //printf("\nenqueue: %c\n", temp->address->data);
}

//dequeue function to delete node from front end of queue and returns it
struct tree *dequeue()
{
  if (front == NULL)
  {
    printf("Underflow");
    exit(0);
  }
  else
  {
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp = front->address;
    front = front->next;
    return temp;
  }
}

//Its just to check problems in my code ignore this function
//or you can use it to explore what happens at every step
void print_queue()
{
  struct queue *temp = front;
  printf("\nQueue: ");
  while (temp != NULL)
  {
    printf("%c", temp->address->data);
    temp = temp->next;
  }
  printf("\n");
}

//This creates the tree
struct tree *create_tree(struct tree *node)
{
  int i = 0;
  struct tree *root = node;
  node->data = 65 + i;
  ++i;
  // printf("%c", node->data);
  enqueue(node);
  while (i < 26)
  {
    //print_queue();
    node = dequeue(); //front node in the queue
    //printf("\ndequeue: %c\n", node->data);
    // print_queue();
    struct tree *temp_left = (struct tree *)malloc(sizeof(struct tree));
    node->leftchild = temp_left;
    node->leftchild->data = 65 + i;
    // printf("%c", node->leftchild->data);
    ++i;
    enqueue(node->leftchild); //adds to queue at rear end
    if (i < 26)               //at last due to it 2 multiple assigning but we already assigned a outside loop
    {
      struct tree *temp_right = (struct tree *)malloc(sizeof(struct tree));
      node->rightchild = temp_right;
      node->rightchild->data = 65 + i;
      ++i;
      // printf("%c", node->rightchild->data);
      enqueue(node->rightchild); //adds queue at rear end
    }
  }

  // printf("\n");

  return root;
}
void preorder(struct tree *root)
{
  if (root != NULL) // checking if the root is not null
  {
    printf(" %c ", root->data); // printing data at root
    preorder(root->leftchild);  // visiting left child
    preorder(root->rightchild); // visiting right child
  }
}

void inorder(struct tree *root)
{
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->leftchild);   // visiting left child
    printf(" %c ", root->data); // printing data at root
    inorder(root->rightchild);  // visiting right child
  }
}

void postorder(struct tree *root)
{
  if (root != NULL) // checking if the root is not null
  {
    postorder(root->leftchild);  // visiting left child
    postorder(root->rightchild); // visiting right child
    printf(" %c ", root->data);  // printing data at root
  }
}

int main()
{

  srand(time(NULL));

  struct tree *root = (struct tree *)malloc(sizeof(struct tree));
  root = create_tree(root);

  printf("\n---------------------------------Pre-order:----------------------------------\n\n");
  // printing tree in pre-order way that is root is printed first then left child then right child
  preorder(root);
  printf("\n");

  printf("\n-----------------------------------In-order:------------------------------------\n\n");
  // printing tree in in-order way that is left child is printed first then root then right child
  inorder(root);
  printf("\n");

  printf("\n----------------------------------Post-order:-----------------------------------\n\n");
  //printing tree in post-order way that is left child is printed first then right child then root
  postorder(root);
  printf("\n");

  return 0;
}