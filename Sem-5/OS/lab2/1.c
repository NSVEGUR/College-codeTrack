//Name: V Nagasai
//Roll: CS20B1016
/*Q: Write a program to display address of an integer variable using pointer. In the same
program access the entries of an integer array using another pointer and display 
the address for each elements of the array.*/

#include <stdio.h>

int main(){
    int x = 3;
    int *ptr1 = &x;//Assigning the address of x to ptr1
    printf("Address of integer x is %p\n", ptr1);
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        int *ptr2 = &arr[i];//Assigning the address of arr[i] to ptr2
        printf("Address of element - %d of arr is %p\n", i, ptr2);
    }
    return 0;
}