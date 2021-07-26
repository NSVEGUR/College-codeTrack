/*Program to swap every 2nd element with its conjugate from the end in the given input array
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
 int n;

 //Getting number of elements in the array
 printf("Enter the number of elements in the given array: ");
 scanf("%d", &n);

 //Dynamic memory allocation for given number of elements
 int *a = (int*)malloc(n*sizeof(int));

 for(int i = 0; i < n; ++i)
 *(a+i) = rand()%1000;//array allocation through random function numbers between 0 and 999

 //Printing the random array
 printf("Taken Random array before sortion:\n");
 for(int i = 0; i < n; ++i)
 printf("%d ", *(a+i));

 int count = 0;
 int t;

 //swapping every 2th element with its conjugate
 for( int i = 1; i < n/2; i = i + 2)
 {
  count++;
           t = *(a+i);
      *(a+i) = *(a+(n-i-1));
  *(a+(n-i-1)) = t;
 }

 //Prinitng the swapped array
 printf("\nGiven array after sortion as given:\n");
 for(int i = 0;i < n; ++i)
 printf("%d ", *(a+i));

 printf("\nNumber of operations performed are %d\n", count);

 return 0;
}
