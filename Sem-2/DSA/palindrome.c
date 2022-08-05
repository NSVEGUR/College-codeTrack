/*Program to find whether the given string is polindrome or not
*/

#include<stdio.h>
#include<string.h>

int main()
{
 char s[1000];
 int i,n,c=0;

 /*Taking input of string from the user*/
 printf("Enter the string : ");
 gets(s);

 /*Function call to find string length*/
 n=strlen(s);

 /*To find whether given function is polindrome or not*/
 for(i=0;i<n/2;i++)
 {
  if(s[i]==s[n-i-1])
  c++;

  }
 if(c==i)
 printf("string is palindrome\n");
 else
 printf("string is not palindrome\n");

 return 0;
}
