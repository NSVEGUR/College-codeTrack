//QUESTION NUMBER - 02

//Program to print a symmetric matrix taking upper triangular matrix as the input

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int r, n;

  //Taking input - rank of the matrix
  printf("Enter the rank of the matrix (must be square number): ");
  scanf("%d", &r);

  r = pow(r, 0.5); //rooting the rank

  n = r * (r + 1) / 2; //number of elements in trianguar matrix for a given

  int *u = (int *)malloc(n * sizeof(int)); //dynamic memory allocation for upper triangular matrix
  int count;

  for (count = 0; count < n; ++count)
    *(u + count) = rand() % 100; //assigning random values

  //printing read elements
  printf("Elements read as: \n");
  for (count = 0; count < n; ++count)
    printf("%d ", *(u + count));
  printf("\n");

  int *m = (int *)malloc(r * r * sizeof(int));
  count = 0;

  //Filling upper triangular matrix
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < r; ++j)
    {
      if (i <= j)
      {
        *(m + i * r + j) = *(u + count);
        ++count;
      }
    }

  //Filling lower part of lower triangular matrix
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < r; ++j)
      if (i >= j)
        *(m + i * r + j) = *(m + j * r + i);

  printf("The matrix read as:\n");
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < r; ++j)
      printf("%d ", *(m + i * r + j));
    printf("\n");
  }

  free(u);
  free(m);
  return 0;
}