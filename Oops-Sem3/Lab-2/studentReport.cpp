#include <iostream>
#include "ReportCard"
using namespace std;

bool MarksInRange(float programming, float webDevelopment, float english, float science, float mathematics)
{
  float arr[] = {programming, webDevelopment, english, science, mathematics};
  for (int i = 0; i < 5; ++i)
  {
    if (arr[i] < 0 || arr[i] > 100)
      return false;
  }
  return true;
}

int main()
{
  cout << "-----Program for Marks report of 5 students-----" << endl;
  string name;
  int rollNumber, choice = 1;
  float programming, webDevelopment, english, science, mathematics;
  cout << "\033[30;44m-----Initialising report cards of students-----\033[0m" << endl;
  ReportCard student_1;
  ReportCard student_2;
  ReportCard student_3;
  cout << "student 1, 2 & 3 created with default constructer" << endl;
  cout << "/////Now creating student 4 & 5 with Parametrised consturcter/////" << endl;
  cout << "Enter the Name of student 4: ";
  cin.ignore();
  getline(cin, name);
  while (1)
  {
    cout << "Enter the Roll number of student 4: ";
    cin >> rollNumber;
    if (rollNumber > 0)
      break;
    cout << "\033[1;31mROLL NUMBER SHOULD BE GREATER THAN ZERO\033[0m" << endl;
  }
  ReportCard student_4(name, rollNumber);
  cout << "Enter the Name of student 5: ";
  cin.ignore();
  getline(cin, name);
  while (1)
  {
    cout << "Enter the Roll number of student 5: ";
    cin >> rollNumber;
    if (rollNumber > 0)
      break;
    cout << "\033[1;31mROLL NUMBER SHOULD BE GREATER THAN ZERO\033[0m" << endl;
  }
  ReportCard student_5(name, rollNumber);
  cout << "student 4 & 5 created with parametrised constructer" << endl;
  cout << endl
       << "\033[30;44m-----Menu driven program-----\033[0m" << endl
       << endl;
  while (choice != 3)
  {
    cout << "\033[1;33m1. Create and Entry Student data." << endl;
    cout << "2. Display Report card for all students." << endl;
    cout << "3. Exit the program.\033[0m" << endl;
    cout << "\033[1;34mEnter your choice : \033[0m";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      for (int i = 0; i < 5; i++)
      {
        cout << "\033[30;44m-----Report card creation of Student - " << i + 1 << "-----\033[0m" << endl;
        cout << "Enter the name of the student: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the roll number of " << name << " : ";
        cin >> rollNumber;
        if (rollNumber <= 0)
        {
          cout << "\033[1;31mROLL NUMBER SHOULD BE GREATER THAN ZERO\033[0m" << endl;
          --i;
          continue;
        }
        while (1)
        {
          cout << "\033[1;33mEnter the marks " << name << " secured in mentioned subjects\033[0m" << endl;
          cout << "Programming - ";
          cin >> programming;
          cout << "WebDevelopment - ";
          cin >> webDevelopment;
          cout << "English - ";
          cin >> english;
          cout << "Science - ";
          cin >> science;
          cout << "Mathematics - ";
          cin >> mathematics;
          if (MarksInRange(programming, webDevelopment, english, science, mathematics))
            break;
          cout << "\033[1;31mMARKS SHOULD BE LIE BETWEEN 0 and 100\033[0m" << endl;
        }
        switch (i + 1)
        {
        case 1:
          student_1.create(name, rollNumber, programming, webDevelopment, english, science, mathematics);
          break;
        case 2:
          student_2.create(name, rollNumber, programming, webDevelopment, english, science, mathematics);
          break;
        case 3:
          student_3.create(name, rollNumber, programming, webDevelopment, english, science, mathematics);
          break;
        case 4:
          student_4.create(name, rollNumber, programming, webDevelopment, english, science, mathematics);
          break;
        case 5:
          student_5.create(name, rollNumber, programming, webDevelopment, english, science, mathematics);
          break;
        default:
          break;
        }
        cout << "\033[30;42m-----Report card of Student - " << i + 1 << " is created-----\033[0m" << endl;
      }
    }
    break;
    case 2:
    {
      student_1.display();
      student_2.display();
      student_3.display();
      student_4.display();
      student_5.display();
    }
    break;
    case 3:
      cout << "\033[1;31m-----PROGRAM EXITED-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----ENTER A VALID CHOICE-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}