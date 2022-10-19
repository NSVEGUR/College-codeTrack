#include<stdio.h>

//ROll: CS20B1016
//Name: V Nagasai

int main(){
   int a = 30;
   int b = a + 1.4;
   printf("Hello World\n");
   scanf("%d", &b);
   printf("%d\n", b);
   if(a != b){
      printf("a and b are not same.\n");
   }
   a++;
   ++b;
   int c = a <= b;
   return 0;
}