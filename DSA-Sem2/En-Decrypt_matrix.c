//NAME : V NAGASAI
//ROLL : CS20B1016

//LAB NUMBER - 03

//QUESTION NUMBER - 01

//Program to write Encryption and Decryption of a matrix
#include <stdio.h>
#include <stdlib.h>

//Function for Decryption of the given matrix
void Encryption(int *m, int r, int c)
{
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {

      if (i == 0 || j == 0 || i == (r - 1) || j == (c - 1))
        *(m + i * c + j) = *(m + i * c + j) + i;

      else
        *(m + i * c + j) = *(m + i * c + j) - (i + j);
    }
  }
}

//Function for Encryption of the given matrix
void Decryption(int *m, int r, int c)
{
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {

      if (i == 0 || j == 0 || i == (r - 1) || j == (c - 1))
        *(m + i * c + j) = *(m + i * c + j) - i;

      else
        *(m + i * c + j) = *(m + i * c + j) + (i + j);
    }
  }
}

//Function for Printing the matrx
void Display(int *m, int r, int c)
{
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
      printf("%d ", *(m + i * c + j));
    printf("\n");
  }
}

//Main function
int main()
{
  int r, c;

  //Taking the input from user
  printf("Enter the number of rows and columns of a given: ");
  scanf("%d", &r);
  scanf("%d", &c);

  //Dynamic memory allocation
  int *m = (int *)malloc(r * c * sizeof(int));

  //Initialisation of array
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      *(m + i * c + j) = rand() % 100; //assigning random values to array between 0 to 99

  printf("Original matrix:\n");
  Display(m, r, c);

  Encryption(m, r, c);
  printf("Encrypted Matrix:\n");
  Display(m, r, c);

  Decryption(m, r, c);
  printf("Decrypted Matrix:\n");
  Display(m, r, c);

  free(m);

  return 0;
}