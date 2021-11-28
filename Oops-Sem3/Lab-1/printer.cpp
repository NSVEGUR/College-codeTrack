#include <iostream>
#include "queue"

using namespace std;

int main()
{
  //object creation with class Queue
  Queue queue_1;
  //variable for choice of work chosen by user
  int choice = 1;
  cout << "----- Program to execute Jobs queue based on classes: -----" << endl;

  //loop repeates untill the choice by user is 5
  while (choice != 5)
  {
    cout << endl
         << "\033[1;32m1. Add to Print Queue" << endl;
    cout << "2. Current Job" << endl;
    cout << "3. Execute a Job" << endl;
    cout << "4. Display Jobs" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice to do above functions: \033[0m";
    cin >> choice;
    //executing functions based on the users choice
    switch (choice)
    {
    case 1:
      //adding jobIds to queue untill it is full at rear end
      queue_1.enqueue();
      break;
    case 2:
      //printing the jobId at the front end
      queue_1.peek();
      break;
    case 3:
      //deleting the jobIds from front end
      queue_1.dequeue();
      break;
    case 4:
      //displaying every job present in queue
      queue_1.display();
      break;
    case 5:
      //exits the loop
      choice = 5;
      cout << "\033[1;31m-----The Program is exited-----\033[0m" << endl;
      break;
    default:
      //default print statement to enter valid choice
      cout << "\033[1;33m-----Enter the valid choice-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}