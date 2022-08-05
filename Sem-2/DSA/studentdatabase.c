/*Program for student database
 */

#include<stdio.h>

/*Structure to store student data base like name age and etc*/

struct studentdatabase
{
 char name[100];
 int age;
 int roll;
 char address[100];
};


int main()
{

 struct studentdatabase s[4];
 int i = 0, t, flag = 1;

 /*Taking the input from user into struct using flag*/

 while(flag)
 {
  printf("Enter the database of student no. %d\n", i+1);
  printf("Enter name of the student: ");
  scanf("%s", s[i].name);
  printf("Enter students age: ");
  scanf("%d", &s[i].age);
  printf("Enter students roll: ");
  scanf("%d", &s[i].roll);
  printf("Enter students address: ");
  scanf("%s", s[i].address);
  printf("To stop press 0 else others");
  scanf("%d", &flag);
  ++i;
  }

 /*Printing the read content*/
 for(t = 0; t < i; ++t)
 {
  printf("Database of student %d read as:\n", t+1);
  printf("Name : %s\n", s[t].name);
  printf("Age : %d\nRoll : %d\n", s[t].age, s[t].roll);
  printf("Address : %s\n", s[t].address);
  }

  return 0;
}


