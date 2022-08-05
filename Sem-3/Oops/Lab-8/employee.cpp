#include <iostream>
using namespace std;

//Main class Employee
class Employee
{
protected:
  int emplyoee_ID;
  string employee_name;

public:
  //constructer for employee to create ID and name
  Employee()
  {
    cout << "\033[1;33m-----Employee Creation-----\033[0m" << endl;
    while (1)
    {
      cout << "Enter the employee_ID: ";
      cin >> this->emplyoee_ID;
      if (this->existence(this->emplyoee_ID))
      {
        cout << "\033[1;31m-----EMPLOYEE ID EXIST-----\033[0m" << endl;
        continue;
      }
      if (this->emplyoee_ID > 0)
        break;
      cout << "\033[1;31m-----INVALID ID-----\033[0m" << endl;
    }
    cout << "Enter the employee_name: ";
    cin >> this->employee_name;
    cout << "\033[1;34m-----Employee Created successfully-----\033[0m" << endl;
  }
  bool existence(int ID);
};

//Sub derived class from Employee
class Contract : protected Employee
{
protected:
  int pay_per_hour;

public:
  //constructer for contract to create employees pay per hour
  Contract()
  {
    int pay;
    cout << "\033[1;33m-----Contract Employee Creation-----\033[0m" << endl;
    cout << "Enter the salary(pay per hour): ";
    cin >> pay;
    if (pay < 0)
    {
      this->pay_per_hour = 0;
      cout << "\033[1;31m-----SINCE PAY PER HOUR IS LESS THAN ZERO CURRENT PAY PER HOUR IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->pay_per_hour = pay;
    cout << "\033[1;34m-----Contract Employee created successfully-----\033[0m" << endl;
  }
  //function to set new pay per hour for the contract employee
  inline void setPay(int new_pay_per_hour)
  {
    if (new_pay_per_hour < 0)
    {
      this->pay_per_hour = 0;
      cout << "\033[1;31m-----SINCE NEW PAY PER HOUR IS LESS THAN ZERO CURRENT PAY PER HOUR IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->pay_per_hour = new_pay_per_hour;
    cout << "\033[1;34m-----PAY PER HOUR SET SUCCESSFULLY-----\033[0m" << endl;
  }
  //function to get the pay per hour details of the contract employee
  inline int getPay()
  {
    return this->pay_per_hour;
  }
};

//Sub derived class from Employee
class Salaried : protected Employee
{
protected:
  int monthlyPay;

public:
  //constructer for Salaried employee to create his monthly payment
  Salaried()
  {
    int pay;
    cout << "\033[1;33m-----Salaried employee Creation-----\033[0m" << endl;
    cout << "Enter the salary(pay per month): ";
    cin >> pay;
    if (pay < 0)
    {
      this->monthlyPay = 0;
      cout << "\033[1;31m-----SINCE NEW MONTHLY PAY IS LESS THAN ZERO CURRENT MONTHLY PAY IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->monthlyPay = pay;
    cout << "\033[1;34m-----Salaried employee created successfully-----\033[0m" << endl;
  }
  //function to set the new monthly payment
  inline void setPay(int new_monthlyPay)
  {
    if (new_monthlyPay < 0)
    {
      this->monthlyPay = 0;
      cout << "\033[1;31m-----SINCE NEW MONTHLY PAY IS LESS THAN ZERO CURRENT MONTHLY PAY IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->monthlyPay = new_monthlyPay;
    cout << "\033[1;34m-----MONTHLY PAY SET SUCCESSFULLY-----\033[0m" << endl;
  }
  //function to get the details of monthly payment
  inline int getPay()
  {
    return this->monthlyPay;
  }
};

//Sub derived class from sub class Salaried
class Manager : private Salaried
{
public:
  //function to set all the details
  void setDetails(int new_employee_ID, string new_employee_name, int new_monthlyPay)
  {
    this->emplyoee_ID = new_employee_ID;
    this->employee_name = new_employee_name;
    if (new_monthlyPay < 0)
    {
      this->monthlyPay = 0;
      cout << "\033[1;31m-----SINCE NEW SALARY IS LESS THAN ZERO MONTHLY PAY IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->monthlyPay = new_monthlyPay;
    cout << "\033[1;34m-----DETAILS SET SUCCESSFULLY-----\033[0m" << endl;
  }
  //function to print all the details
  void getDetails()
  {
    cout << "\033[1;35m-----Details of the Employee-'Manager'------\033[0m" << endl;
    cout << "\033[1;34memployee_ID      - " << this->emplyoee_ID << endl;
    cout << "employee_name    - " << this->employee_name << endl;
    cout << "salary per month - " << this->monthlyPay << "\033[0m" << endl;
    cout << "\033[1;35m------------------------------------------\033[0m" << endl;
  }
  //function to calculate salary per input number of months
  inline int calculateSalary(int number_of_months)
  {
    if (number_of_months <= 0)
      return 0;
    else
      return number_of_months * this->monthlyPay;
  }
  //function to set new salary
  inline void setSalary(int new_salary)
  {
    if (new_salary < 0)
    {
      this->monthlyPay = 0;
      cout << "\033[1;31m-----SINCE NEW SALARY IS LESS THAN ZERO MONTHLY PAY IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->monthlyPay = new_salary;
    cout << "\033[1;34m-----SALARY SET SUCCESSFULLY-----\033[0m" << endl;
  }
  //function to program everything based on the work given by user
  void program(int work);
  bool existenceInManagers(int ID);
};

//Sub derived class from sub class Contract
class Intern : private Contract
{
public:
  //function to set all the details
  void setDetails(int new_employee_ID, string new_employee_name, int new_pay_per_hour)
  {
    this->emplyoee_ID = new_employee_ID;
    this->employee_name = new_employee_name;
    if (new_pay_per_hour < 0)
    {
      this->pay_per_hour = 0;
      cout << "\033[1;31m-----SINCE NEW SALARY IS LESS THAN ZERO MONTHLY PAY IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->pay_per_hour = new_pay_per_hour;
    cout << "\033[1;34m-----DETAILS SET SUCCESSFULLY-----\033[0m" << endl;
  }
  //function to print all the details
  void getDetails()
  {
    cout << "\033[1;35m-----Details of the Employee-'Intern'------\033[0m" << endl;
    cout << "\033[1;34memployee_ID      - " << this->emplyoee_ID << endl;
    cout << "employee_name    - " << this->employee_name << endl;
    cout << "salary per hour - " << this->pay_per_hour << "\033[0m" << endl;
    cout << "\033[1;35m------------------------------------------\033[0m" << endl;
  }
  //function to calculate salary per input number of hours
  inline int calculateSalary(int number_of_hours)
  {
    if (number_of_hours <= 0)
      return 0;
    else
      return number_of_hours * this->pay_per_hour;
  }
  //function to set new salary
  inline void setSalary(int new_salary)
  {
    if (new_salary < 0)
    {
      this->pay_per_hour = 0;
      cout << "\033[1;31m-----SINCE NEW SALARY IS LESS THAN ZERO MONTHLY PAY IS ASSIGNED TO 'ZERO'-----\033[0m" << endl;
    }
    else
      this->pay_per_hour = new_salary;
    cout << "\033[1;34m-----SALARY SET SUCCESSFULLY-----\033[0m" << endl;
  }
  //function to program everything based on the work given by user
  void program(int work);
  bool existenceInInterns(int ID);
};

//Linked list for Managers
class Managers
{
public:
  Manager manager;
  Managers *link;
};

//Linked list for interns
class Interns
{
public:
  Intern intern;
  Interns *link;
};

Managers *managersHead = NULL;
Interns *internsHead = NULL;

//function for all the manager related works
void Manager::program(int work)
{
  int ID, flag = 1;
  cout << "Enter the employee_ID of the manager: ";
  cin >> ID;
  Managers *temp = managersHead;
  //moves up to the employee node based on input ID else exits
  while (temp != NULL)
  {
    if (temp->manager.emplyoee_ID == ID)
    {
      flag = 0;
      break;
    }
    temp = temp->link;
  }
  //if employee doesn't exist
  if (flag)
    cout << "\033[1;31m-----EMPLOYEE ID DOESN'T EXIST-----\033[0m" << endl;
  else
  {
    switch (work)
    {
    //updating the employee details
    case 2:
    {
      int new_ID, new_monthlyPay;
      string new_employee_name;
      while (1)
      {
        cout << "Enter the employee_ID: ";
        cin >> new_ID;
        if (this->existence(new_ID))
        {
          cout << "\033[1;31m-----EMPLOYEE ID EXIST-----\033[0m" << endl;
          continue;
        }
        if (new_ID > 0)
          break;
        cout << "\033[1;31m-----INVALID ID-----\033[0m" << endl;
      }
      cout << "Enter the name of employee - " << new_ID << " : ";
      cin >> new_employee_name;
      cout << "Enter his/her monthly salary: ";
      cin >> new_monthlyPay;
      temp->manager.setDetails(new_ID, new_employee_name, new_monthlyPay);
    }
    break;
    //printing employee details
    case 3:
    {
      temp->manager.getDetails();
    }
    break;
    //updating salary of the manager
    case 4:
    {
      int new_salary;
      cout << "Enter new Salary: ";
      cin >> new_salary;
      temp->manager.setSalary(new_salary);
    }
    break;
    //calculating the salary of the manager
    case 5:
    {
      int months;
      cout << "Enter for how many months you need to calculate the salary of the employee: ";
      cin >> months;
      cout << "Salary of employee - " << temp->manager.emplyoee_ID << " = " << temp->manager.calculateSalary(months) << " for " << months << " months" << endl;
    }
    break;
    }
  }
}

//function for all the manager related works
void Intern::program(int work)
{
  int ID, flag = 1;
  cout << "Enter the employee_ID of the Intern: ";
  cin >> ID;
  Interns *temp = internsHead;
  while (temp != NULL)
  {
    if (temp->intern.emplyoee_ID == ID)
    {
      flag = 0;
      break;
    }
    temp = temp->link;
  }
  if (flag)
    cout << "\033[1;31m-----EMPLOYEE ID DOESN'T EXIST-----\033[0m" << endl;
  else
  {
    switch (work)
    {
    case 2:
    {
      int new_ID, new_pay_per_hour;
      string new_employee_name;
      while (1)
      {
        cout << "Enter the employee_ID: ";
        cin >> new_ID;
        if (this->existence(new_ID))
        {
          cout << "\033[1;31m-----EMPLOYEE ID EXIST-----\033[0m" << endl;
          continue;
        }
        if (new_ID > 0)
          break;
        cout << "\033[1;31m-----INVALID ID-----\033[0m" << endl;
      }
      cout << "Enter the name of employee - " << new_ID << " : ";
      cin >> new_employee_name;
      cout << "Enter his/her monthly salary: ";
      cin >> new_pay_per_hour;
      temp->intern.setDetails(new_ID, new_employee_name, new_pay_per_hour);
    }
    break;
    case 3:
    {
      temp->intern.getDetails();
    }
    break;
    case 4:
    {
      int new_salary;
      cout << "Enter new Salary: ";
      cin >> new_salary;
      temp->intern.setSalary(new_salary);
    }
    break;
    case 5:
    {
      int hours;
      cout << "Enter for how many hours you need to calculate the salary of the employee: ";
      cin >> hours;
      cout << "Salary of employee - " << temp->intern.emplyoee_ID << " = " << temp->intern.calculateSalary(hours) << " for " << hours << " hours" << endl;
    }
    break;
    }
  }
}

//for creation of node of Manager(new manager creation)
void createManager()
{
  Managers *current = new Managers;
  current->link = NULL;
  //at initial stage
  if (managersHead == NULL)
    managersHead = current;
  else
  {
    //creating at the end
    Managers *temp = managersHead;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
  }
}

//for creation of node of Intern(new intern creation)
void createIntern()
{
  Interns *current = new Interns;
  current->link = NULL;
  //at initial stage
  if (internsHead == NULL)
    internsHead = current;
  else
  {
    //creating at the end
    Interns *temp = internsHead;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
  }
}

//function to check the existence of employee ID in managers list
bool Manager::existenceInManagers(int ID)
{
  Managers *temp = managersHead;
  while (temp != NULL)
  {
    if (temp->manager.emplyoee_ID == ID)
      return true;
    temp = temp->link;
  }
  return false;
}

//function to check the existence of employee ID in interns list
bool Intern::existenceInInterns(int ID)
{
  Interns *temp = internsHead;
  while (temp != NULL)
  {
    if (temp->intern.emplyoee_ID == ID)
      return true;
    temp = temp->link;
  }
  return false;
}

//function to check both the existence
bool Employee::existence(int ID)
{
  if (managersHead == NULL && internsHead == NULL)
    return false;
  if (managersHead != NULL)
    if (managersHead->manager.existenceInManagers(ID))
      return true;

  if (internsHead != NULL)
    if (internsHead->intern.existenceInInterns(ID))
      return true;

  return false;
}

int main()
{
  cout << "-----PROGRAM FOR EMPLYOEES-----" << endl;
  int choice = 1, emplyoee = 1;
  //menu driven program which works on user input
  while (choice != 6)
  {
    cout << "\033[1;32m1. Create Employee (Manager or Intern)" << endl;
    cout << "2. Update Employee Details (Manager or Intern)" << endl;
    cout << "3. Print Employee Details (Manager or Intern)" << endl;
    cout << "4. Update Pay (Manager or Intern)" << endl;
    cout << "5. Calculate Salary (Manager or Intern)" << endl;
    cout << "6. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      //inifinte loop exits if the input is correct
      while (1)
      {
        cout << "\033[1;33mEnter the type of emplyoee you wanna create." << endl;
        cout << "1. Manager" << endl;
        cout << "2. Intern\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> emplyoee;
        if (emplyoee == 1 || emplyoee == 2)
          break;
        cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      }
      //based on the user that kind of node is created
      if (emplyoee == 1)
        createManager();
      else
        createIntern();
    }
    break;
    case 2:
    {
      while (1)
      {
        cout << "\033[1;33mEnter the type of emplyoee you wanna update." << endl;
        cout << "1. Manager" << endl;
        cout << "2. Intern\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> emplyoee;
        if (emplyoee == 1 || emplyoee == 2)
          break;
        cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      }
      if (emplyoee == 1)
      {
        //if list is null
        if (managersHead == NULL)
          cout << "\033[1;31m-----There are no managers to update-----\033[0m" << endl;
        else
          managersHead->manager.program(choice);
      }
      else
      {
        //if list is null
        if (internsHead == NULL)
          cout << "\033[1;31m-----There are no interns to update-----\033[0m" << endl;
        else
          internsHead->intern.program(choice);
      }
    }
    break;
    case 3:
    {
      while (1)
      {
        cout << "\033[1;33mEnter the type of emplyoee you wanna update." << endl;
        cout << "1. Manager" << endl;
        cout << "2. Intern\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> emplyoee;
        if (emplyoee == 1 || emplyoee == 2)
          break;
        cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      }
      if (emplyoee == 1)
      {
        if (managersHead == NULL)
          cout << "\033[1;31m-----There are no managers to print-----\033[0m" << endl;
        else
          managersHead->manager.program(choice);
      }
      else
      {
        if (internsHead == NULL)
          cout << "\033[1;31m-----There are no interns to print-----\033[0m" << endl;
        else
          internsHead->intern.program(choice);
      }
    }
    break;
    case 4:
    {
      while (1)
      {
        cout << "\033[1;33mEnter the type of emplyoee you wanna update." << endl;
        cout << "1. Manager" << endl;
        cout << "2. Intern\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> emplyoee;
        if (emplyoee == 1 || emplyoee == 2)
          break;
        cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      }
      if (emplyoee == 1)
      {
        if (managersHead == NULL)
          cout << "\033[1;31m-----There are no managers to print-----\033[0m" << endl;
        else
          managersHead->manager.program(choice);
      }
      else
      {
        if (internsHead == NULL)
          cout << "\033[1;31m-----There are no interns to print-----\033[0m" << endl;
        else
          internsHead->intern.program(choice);
      }
    }
    break;
    case 5:
    {
      while (1)
      {
        cout << "\033[1;33mEnter the type of emplyoee you wanna update." << endl;
        cout << "1. Manager" << endl;
        cout << "2. Intern\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> emplyoee;
        if (emplyoee == 1 || emplyoee == 2)
          break;
        cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      }
      if (emplyoee == 1)
      {
        if (managersHead == NULL)
          cout << "\033[1;31m-----There are no managers to print-----\033[0m" << endl;
        else
          managersHead->manager.program(choice);
      }
      else
      {
        if (internsHead == NULL)
          cout << "\033[1;31m-----There are no interns to print-----\033[0m" << endl;
        else
          internsHead->intern.program(choice);
      }
    }
    break;
    case 6:
      cout << "\033[1;31m-----PROGRAM EXITED BY THE USER-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
    }
  }
  return 0;
}