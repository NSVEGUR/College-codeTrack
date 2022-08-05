#include <iostream>
#include <string>
using namespace std;

// Template for rollNumber data string for student and int for researchStudent
template <typename T>
class Person
{
protected:
  string name;
  T rollNumber;

public:
  // Parameterised constructor
  Person(string name, T rollNumber)
  {
    this->name = name;
    this->rollNumber = rollNumber;
  }
  // virtual function for display which displays only name and roll number
  virtual void display()
  {
    cout << "\033[1;33m-----PERSON DETAILS-----" << endl;
    cout << "\033[1;34mName    : " << this->name << endl;
    cout << "Roll No.: " << this->rollNumber << "\033[0m" << endl;
  }
};

// virtual class Student derived from Person
class Student : virtual protected Person<string>
{
protected:
  string course1, course2, course3;

public:
  // Parameterised constructor
  Student(string name, string rollNumber, string course1, string course2, string course3) : Person(name, rollNumber)
  {
    this->course1 = course1;
    this->course2 = course2;
    this->course3 = course3;
  }
  // display function for student which displays student details
  void display()
  {
    cout << "\033[1;33m-----STUDENT DETAILS-----" << endl;
    cout << "\033[1;34mName    : " << this->name << endl;
    cout << "Roll No.: " << this->rollNumber << endl;
    cout << "Course1 : " << this->course1 << endl;
    cout << "Course2 : " << this->course2 << endl;
    cout << "Course3 : " << this->course3 << "\033[0m" << endl;
  }
};

// virtual class Research student derived from Person
class ResearchStudent : virtual protected Person<int>
{
protected:
  string course1, researchArea;

public:
  // Parameterised constructor
  ResearchStudent(string name, int rollNumber, string course1, string researchArea) : Person(name, rollNumber)
  {
    this->course1 = course1;
    this->researchArea = researchArea;
  }
  // display function which details research student details
  void display()
  {
    cout << "\033[1;33m-----RESEARCH STUDENT DETAILS-----" << endl;
    cout << "\033[1;34mName          : " << this->name << endl;
    cout << "Roll No.      : " << this->rollNumber << endl;
    cout << "Course1       : " << this->course1 << endl;
    cout << "Research Area : " << this->researchArea << "\033[0m" << endl;
  }
};

// class Teaching Assistant derived from both Student and Research Student
class TeachingAssistant : protected Student, ResearchStudent
{
protected:
  string courseAssigned, role;
  TeachingAssistant *link;

public:
  // Parameterised constructor for ta role as student
  TeachingAssistant(string name, string rollNumber, string courseAssigned, string role, string course1, string course2, string course3) : Student(name, rollNumber, course1, course2, course3), ResearchStudent(name, stoi(rollNumber), course1, "nothing"), Person<string>(name, rollNumber), Person<int>(name, stoi(rollNumber))
  {
    this->courseAssigned = courseAssigned;
    this->role = role;
  }
  // Parameterised constructor for ta role as research student
  TeachingAssistant(string name, int rollNumber, string courseAssigned, string role, string course1, string researchArea) : ResearchStudent(name, rollNumber, course1, researchArea), Student(name, to_string(rollNumber), course1, "nothing", "nothing"), Person<string>(name, to_string(rollNumber)), Person<int>(name, rollNumber)
  {
    this->courseAssigned = courseAssigned;
    this->role = role;
  }
  // display function which displays ta details
  void display()
  {
    cout << "\033[1;33m-----TEACHING ASSISTANT DETAILS-----" << endl;
    if (this->role == "student")
    {
      cout << "\033[1;34mName          : " << Person<string>::name << endl;
      cout << "Roll No.      : " << Person<string>::rollNumber << endl;
    }
    else
    {
      cout << "\033[1;34mName          : " << Person<int>::name << endl;
      cout << "Roll No.      : " << Person<int>::rollNumber << endl;
    }
    cout << "Course assign.: " << this->courseAssigned << endl;
    cout << "Role          : " << this->role << "\033[0m" << endl;
  }
  // function to create new ta
  TeachingAssistant *createNode(TeachingAssistant *head);
  // function to find ta based on input roll number
  TeachingAssistant *findNode(TeachingAssistant *head, int rollNumber);
  // functions to call respective display  functions using virtual class and function feature
  // Here functions are used since conversion is not accessible from main since child is derived in protected manner
  void callForPerson(string s);
  void callForPerson(int i);
  void callForStudent();
  void callForResearchStudent();
  // function to return roll Number to compare with the input roll to find the required node
  int returnRoll()
  {
    if (this->role == "student")
    {
      return stoi(Person<string>::rollNumber);
    }
    else
      return Person<int>::rollNumber;
  }
  // function to find the role of the ta whether student or research student
  string roleOfTA()
  {
    return this->role;
  }
};

// helper function to find whether the courses are unique or not
bool uniqueCourse(string course1, string course2, string course3)
{
  if (course1 != course2 && course1 != course3 && course2 != course3)
    return true;
  return false;
}

// function definition for finding the required node
TeachingAssistant *TeachingAssistant::findNode(TeachingAssistant *head, int rollNumber)
{
  if (head == NULL)
    // if no TAs are there returns NULL
    return NULL;
  TeachingAssistant *temp = head;
  while (temp != NULL)
  {
    if (temp->returnRoll() == rollNumber)
      // returns the node if the rollNumber matches
      return temp;
    temp = temp->link;
  }
  // if input roll is not found returns NULL
  return NULL;
}

// function definition to create the node
TeachingAssistant *TeachingAssistant::createNode(TeachingAssistant *head)
{
  int choice = 1;
  while (1)
  {
    cout << "Choose the role of TA: " << endl;
    cout << "\033[1;32m1. Student" << endl;
    cout << "2. Research Student\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1 || choice == 2)
      break;
    cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
  }
  // creating that kinda nodes based on user input whethter student or research student
  if (choice == 1)
  {
    string name, rollNumber, course1, course2, course3, courseAssigned;
    cout << "Enter the name of TA: ";
    cin >> name;
    while (1)
    {
      cout << "Enter the roll number of " << name << " (\033[1;31mPLEASE ENTER ONLY INTEGERS/STRINGS WITH ONLY INTEGERS\033[0m): ";
      cin >> rollNumber;
      // checks rollnumber validity if greater than 0 and its unique loop breaks
      if (stoi(rollNumber) > 0 && this->findNode(head, stoi(rollNumber)) == NULL)
        break;
      cout << "\033[1;31mROLL NUMBER MUST BE GREATER THAN 0 AND UNIQUE\033[0m" << endl;
    }
    cout << "Enter the Course Assigned to TA: ";
    cin >> courseAssigned;
    while (1)
    {
      cout << "-----COURSES as STUDENT-----" << endl;
      cout << "Enter course1: ";
      cin >> course1;
      cout << "Enter course2: ";
      cin >> course2;
      cout << "Enter course3: ";
      cin >> course3;
      if (uniqueCourse(course1, course2, course3))
        break;
      cout << "\033[1;31mCOURSES MUST BE UNIQUE\033[0m" << endl;
    }
    TeachingAssistant *current = new TeachingAssistant(name, rollNumber, courseAssigned, "student", course1, course2, course3);
    current->link = NULL;
    if (head == NULL)
    {
      head = current;
    }
    else
    {
      TeachingAssistant *temp = head;
      while (temp->link != NULL)
        temp = temp->link;
      temp->link = current;
    }
  }
  if (choice == 2)
  {
    string name, course1, researchArea, courseAssigned;
    int rollNumber;
    cout << "Enter the name of TA: ";
    cin >> name;
    while (1)
    {
      cout << "Enter the roll number of " << name << " (\033[1;31mPLEASE ENTER ONLY INTEGERS/STRINGS WITH ONLY INTEGERS\033[0m): ";
      cin >> rollNumber;
      // checks rollnumber validity if greater than 0 and its unique loop breaks
      if (rollNumber > 0 && this->findNode(head, rollNumber) == NULL)
        break;
      cout << "\033[1;31mROLL NUMBER MUST BE GREATER THAN 0 AND UNIQUE\033[0m" << endl;
    }
    cout << "Enter the Course Assigned to TA: ";
    cin >> courseAssigned;
    cout << "-----COURSES as RESEARCH STUDENT-----" << endl;
    cout << "Enter the course1: ";
    cin >> course1;
    cout << "Enter the research area: ";
    cin >> researchArea;
    TeachingAssistant *current = new TeachingAssistant(name, rollNumber, courseAssigned, "researchStudent", course1, researchArea);
    current->link = NULL;
    if (head == NULL)
    {
      head = current;
    }
    else
    {
      TeachingAssistant *temp = head;
      while (temp->link != NULL)
        temp = temp->link;
      temp->link = current;
    }
  }
  return head;
}

// function to call display function on person if its roll is string(student)
void TeachingAssistant::callForPerson(string s)
{
  Person<string> *basePointer;
  Person<string> obj = *this; // giving value of this to parent object person
  basePointer = &obj;
  basePointer->display();
}

// function to call display function on person if its roll is int(researchStudent)
void TeachingAssistant::callForPerson(int i)
{
  Person<int> *basePointer;
  Person<int> obj = *this; // giving value of this to parent object person
  basePointer = &obj;
  basePointer->display();
}

// function to call display function on student
void TeachingAssistant::callForStudent()
{
  Student *basePointer;
  Student obj = *this; // giving value of this to parent object student
  basePointer = &obj;
  basePointer->display();
}

// function to call display function on research student
void TeachingAssistant::callForResearchStudent()
{
  ResearchStudent *basePointer;
  ResearchStudent obj = *this; // giving value of this to parent object researchStudent
  basePointer = &obj;
  basePointer->display();
}

int main()
{
  TeachingAssistant *head = NULL;
  cout << "\033[1;33m-----PROGRAM FOR STUDENTS IMPLEMENTATION USING VIRTUAL FUNCTIONS AND TEMPLATES-----" << endl;
  int choice = 1;
  char subChoice = 'a';
  while (choice != 3)
  {
    cout << "\033[1;32m1. Set TA details" << endl;
    cout << "2. Display details" << endl;
    cout << "3. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      // creating node
      head = head->createNode(head);
      break;
    case 2:
    {
      cout << "\033[1;32ma. Person" << endl;
      cout << "b. Student" << endl;
      cout << "c. Research Student" << endl;
      cout << "d. Teaching Assistant\033[0m" << endl;
      cout << "Enter your choice: ";
      cin >> subChoice;
      switch (subChoice)
      {
      case 'a':
      {
        string rollNumber;
        cout << "Enter the roll Number of the Person(\033[1;31mPLEASE ENTER ONLY INTEGERS/STRINGS WITH ONLY INTEGERS\033[0m): ";
        cin >> rollNumber;
        // finding node based on roll input and conducting functions based on the input
        TeachingAssistant *temp = head->findNode(head, stoi(rollNumber));
        if (temp == NULL)
        {
          cout << "\033[1;31mLIST IS EMPTY OR TA WITH THAT ROLL DOESN'T EXIST\033[0m" << endl;
        }
        else
        {
          if (temp->roleOfTA() == "student")
            temp->callForPerson("student"); // for function overloading
          else
            temp->callForPerson(1); // for function overloading
        }
      }
      break;
      case 'b':
      {
        int rollNumber;
        cout << "Enter the roll Number of the Person(\033[1;31mPLEASE ENTER ONLY INTEGERS/STRINGS WITH ONLY INTEGERS\033[0m): ";
        cin >> rollNumber;
        TeachingAssistant *temp = head->findNode(head, rollNumber);
        if (temp == NULL)
        {
          cout << "\033[1;31mLIST IS EMPTY OR TA WITH THAT ROLL DOESN'T EXIST\033[0m" << endl;
        }
        else
        {
          if (temp->roleOfTA() == "student")
            temp->callForStudent();
          else
            cout << "\033[1;31m-----HE/SHE IS A RESEARCH STUDENT(NOT A STUDENT)-----\033[0m" << endl;
        }
      }
      break;
      case 'c':
      {
        int rollNumber;
        cout << "Enter the roll Number of the Person(\033[1;31mPLEASE ENTER ONLY INTEGERS/STRINGS WITH ONLY INTEGERS\033[0m): ";
        cin >> rollNumber;
        TeachingAssistant *temp = head->findNode(head, rollNumber);
        if (temp == NULL)
        {
          cout << "\033[1;31mLIST IS EMPTY OR TA WITH THAT ROLL DOESN'T EXIST\033[0m" << endl;
        }
        else
        {
          if (temp->roleOfTA() == "researchStudent")
            temp->callForResearchStudent();
          else
            cout << "\033[1;31m-----HE/SHE IS JUST A STUDENT(NOT A RESEARCH STUDENT)-----\033[0m" << endl;
        }
      }
      break;
      case 'd':
      {
        int rollNumber;
        cout << "Enter the roll Number of the Person(\033[1;31mPLEASE ENTER ONLY INTEGERS/STRINGS WITH ONLY INTEGERS\033[0m): ";
        cin >> rollNumber;
        TeachingAssistant *temp = head->findNode(head, rollNumber);
        if (temp == NULL)
        {
          cout << "\033[1;31mLIST IS EMPTY OR TA WITH THAT ROLL DOESN'T EXIST\033[0m" << endl;
        }
        else
        {
          temp->display();
        }
      }
      break;
      default:
        cout << "\033[1;31m-----INVALID SUBCHOICE-----\033[0m" << endl;
        break;
      }
    }
    break;
    // exiting the program
    case 3:
      cout << "\033[1;31m-----USER EXITED THE PROGRAM-----\033[0m" << endl;
      break;
    // if given choice is invalid
    default:
      cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}