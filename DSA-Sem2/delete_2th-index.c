/*Program to print the continuous deletion array at every operation with 2th index
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n, i;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n); //Taking input from the user of number of elements in the array

  int *a = (int *)malloc(n * sizeof(int)); //Dynamic memory allocation for the array

  for (i = 0; i < n; ++i)
    *(a + i) = rand() % 100; //array allocation through random function between 0 to 99

  printf("Initially allocated array: \n");
  for (i = 0; i < n; ++i)
    printf("%d ", *(a + i)); //printing the intial array

  int count = 0;
  int flag = 1;
  int power = 0, t, j; //for 2th index

  j = n; //for storing memory of decreased array

  while (flag)
  {
    count++;

    t = pow(2, power);

    for (i = t; i < j - 1; ++i)
      *(a + i) = *(a + i + 1);

    --j;

    printf("\nSorted array after %d operation: \n", power + 1); //to print array after deletion of 2th index term
    for (i = 0; i < j; ++i)
      printf("%d ", *(a + i));

    ++power;

    if ((pow(2, power)) > j)
      flag = 0; //if any 2th index number not found
  }

  printf("\nNumber of operations done are %d\n", count);

  return 0;
}
