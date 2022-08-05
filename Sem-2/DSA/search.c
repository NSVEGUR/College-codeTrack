//NAME: V NAGASAI
//ROLL: CS20B1016
/*Program for linear search and binary search
using dynamic memory allocation
*/
#include <stdio.h>
#include <stdlib.h>
//Function for linear search
void linear(int n, int *a, int x)
{
  int i, count = 0, t = 0;
  for (i = 0; i < n; ++i)
  {
    count++; //operation counter
    if (x == *(a + i))
    {
      t = 1;
      break;
    }
  }
  //Result
  if (t == 1)
    printf("Given number is present in input array\n");
  else
    printf("Given number is not found in input array\n");
  printf("Number of operations are %d\n", count);
}
//Function for binary search
void binary(int n, int *a, int x)
{
  int low = 0;
  int high = n - 1;
  int count = 0, t = 0;
  while (low <= high)
  {
    int middle = (low + high) / 2;
    count++; //operatoin counter
    if (x > *(a + middle))
    {
      low = middle + 1;
      continue;
    }
    if (x < *(a + middle))
    {
      high = middle - 1;
      continue;
    }
    if (x == *(a + middle))
    {
      t = 1;
      break;
    }
  }
  //Result
  if (t == 1)
    printf("Given number is found in input array\n");
  else
    printf("Given number is not found in input array\n");
  printf("Number of operations are %d\n", count);
}
int main()
{
  int n, x, i;
  //To take input from user of number of elements
  printf("enter number of elemennts in array: ");
  scanf("%d", &n);
  //Dynamic memory allocation
  int *a = (int *)malloc(n * sizeof(int));
  //Array input
  printf("Enter %d numbers in ascending order: ", n);
  for (i = 0; i < n; ++i)
    scanf("%d", (a + i));
  //input of search element
  printf("Enter the number to search: ");
  scanf("%d", &x);
  //linear search
  printf("On linear search:\n");
  linear(n, a, x);
  //binary search
  printf("On binary search:\n");
  binary(n, a, x);
  return 0;
}