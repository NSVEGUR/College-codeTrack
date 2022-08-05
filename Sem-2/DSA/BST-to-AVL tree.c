/*2. Create a Binary Search Tree (BST) from random N numbers. N should be taken as input from
     the user. Using the same N numbers, create the corresponding AVL tree. Show the height
     difference between both these trees (BST vs AVL).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct bst
{
  int data;
  struct bst *left;
  struct bst *right;
};

//used for both BST and AVL

struct bst *parent = NULL;
struct bst *location = NULL;
//during insertion to find parent and insertion location
int count = 0;
//for storing insertioins in array

void find(struct bst *root, int item)
{
  struct bst *save = NULL;
  struct bst *ptr = NULL;
  int flag = 1;

  if (root == NULL)//at initial stage
  {
    location = NULL;
    parent = NULL;
  }
  else if (item == root->data)//item at root
  {
    location = root;
    parent = NULL;
    flag = 0;
  }
  else if (flag == 1)
  {
    //printf("\nentering flag: \n");
    if (item < root->data)//item are left side of the root
    {
      ptr = root->left;
      save = root;
    }
    else//item at right side of the root
    {
      ptr = root->right;
      save = root;
    }

    parent = save;//saving the parent element 
    while (ptr != NULL)
    {
      //printf("\nloop is running\n");
      if (item == ptr->data)
      {
        location = ptr;
        parent = save;
        flag = 0;//if item found
      }
      else if (item < ptr->data)//traversing left consecutively in while loop
      {
        save = ptr;
        ptr = ptr->left;
      }
      else//travering right consectively in while loop
      {
        save = ptr;
        ptr = ptr->right;
      }
    }
  }
  if (flag == 1)//if item not found 
  {
    location = NULL;
    parent = save;
  }
}

void insert_bst(struct bst *root, int item, int *store)
{
  find(root, item);
  //finding item if its present or not if yes duplicates are not allowed in BST function exits
  //printf("number: %d\n", item);

  *(store + count) = item;
  ++count;
  //storing data in array for AVL tree construction

  if (location != NULL)
  {
    printf("\ndata is already there\n");
  }
  else
  {
    struct bst *new = (struct bst *)malloc(sizeof(struct bst));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    location = new;
    //here parent implies not the root exactly 
    //the parent where the node is to be inserted || parent is found from find function
    if (parent == NULL)
    {
      root = new;
      //printf("root: %d\n", root->data);
    }
    else if (item < parent->data)
    {
      parent->left = new;
    }
    else
    {
      parent->right = new;
    }
  }
}

int height(struct bst *node)
{
  if (node == NULL)
    return 0;
  else
  {
    /* compute the depth of each subtree */
    int left_height = height(node->left);//finding left child height
    int right_height = height(node->right);//finding right child height

    /* use the larger one */
    if (left_height > right_height)
      return (left_height + 1);
    else
      return (right_height + 1);
  }
}

//function to carry the right-rotation of input node 
struct bst *rightRotate(struct bst *y)
{
  struct bst *x = y->left;
  struct bst *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Return new root
  return x;
}

//function to carry the left-rotation of input node
struct bst *leftRotate(struct bst *x)
{
  struct bst *y = x->right;
  struct bst *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Return new root
  return y;
}

//gives the balance factor of the input node
int getBalance(struct bst *node)
{
  if (node == NULL)
    return 0;
  return (height(node->left)) - (height(node->right));
}

//inserting new node in avl tree
struct bst *newNode(int data)
{
  struct bst *node = (struct bst *)malloc(sizeof(struct bst));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

//avl insertion function
struct bst *insert_avl(struct bst *node, int data)
{
  /*  Perform the normal BST insertion */
  if (node == NULL)
    return (newNode(data));

  if (data < node->data)
    node->left = insert_avl(node->left, data);
  else if (data > node->data)
    node->right = insert_avl(node->right, data);
  else // Equal datas are not allowed in BST
    return node;

  /* Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
  int balance = getBalance(node);

  // If this node becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && data < node->left->data)
    return rightRotate(node);

  // Right Right Case
  if (balance < -1 && data > node->right->data)
    return leftRotate(node);

  // Left Right Case
  if (balance > 1 && data > node->left->data)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && data < node->right->data)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

void inorder(struct bst *root)
{
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->left);        // visiting left child
    printf(" %d ", root->data); // printing data at root
    inorder(root->right);       // visiting right child
  }
}

int main()
{
  srand(time(NULL));
  struct bst *root_bst = (struct bst *)malloc(sizeof(struct bst));
  struct bst *root_avl = NULL;
  int n;
  printf("Enter the number of nodes you wanted to create a tree with: ");
  scanf("%d", &n);

  int store[n];

  parent = root_bst;

  root_bst->data = rand() % 1000;

  store[count] = root_bst->data;
  ++count;

  printf("\n Stored data: \n");

  for (int i = 1; i < n; ++i)
  {
    printf(" %d ", store[i - 1]);
    insert_bst(root_bst, rand() % 1000, store);
  }

  printf(" %d ", store[count - 1]);
  
  printf("\n");
  printf("\n BST: \n");


  inorder(root_bst);

  printf("\n");

  for (int i = 0; i < n; ++i)
  {
    root_avl = insert_avl(root_avl, store[i]);
  }

  printf("\n");

  printf("\n AVL: \n");


  inorder(root_avl);
  printf("\n");

  printf("\n\n Height of BS tree: %d\n\n", height(root_bst));
  printf("\n\n Height of AVL tree: %d\n\n", height(root_avl));
  //height differenve between the BS and AVL trees
  printf("\n\n Height difference h(BS) - h(AVL) = %d\n\n", height(root_bst) - height(root_avl));

  
  return 0;
}