/*Programme to print summation of numbers in the input array
*/
#include<stdio.h>

int main()
{
 int n, i, sum = 0;

 /*Taking the value of n from the user*/
 printf("Enter the value of n:");
 scanf("%d", &n);
 int a[n];

 /*Taking element values*/
 printf("Enter %d numbers:\n", n);
 for(i = 0;i < n; ++i)
 scanf("%d", &a[i]);

 /*Calculating summation*/
 for(i = 0;i < n; ++i)
 sum = sum + a[i];

 printf("Summation of the given array is %d\n", sum);
 return 0;
}
