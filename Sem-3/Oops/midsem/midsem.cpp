#include <iostream>
using namespace std;

#define SIZE 1000
//integer to count the size of the array
int actualSize = 0;

//base class which includes Basic Info
class Basic_info
{
private:
  string name;
  int roll_number;
  char sex;

protected:
  //function which sets the details of the user
  void setDetails(string name, int roll_number, char sex)
  {
    this->name = name;
    this->roll_number = roll_number;
    this->sex = sex;
  }

  //function which find the index number of the array if it doesnt exists returns -1
  int findRoll(int roll, Basic_info students[])
  {
    for (int i = 0; i < actualSize; ++i)
    {
      if (students[i].roll_number == roll)
        return i;
    }
    return -1;
  }

  //function which displays the details
  void getDetails()
  {
    cout << "\033[1;33m-----Details of student " << this->name << " -----" << endl;
    cout << "\033[1;34m ROLL NUMBER: " << this->roll_number << endl;
    cout << "NAME: " << this->name << endl;
    cout << "SEX: " << this->sex << endl;
  }
  //functon which updats the basic info
  void updateBasicInfo(string name, int roll_number, char sex, Basic_info students[])
  {
    students[actualSize].setDetails(name, roll_number, sex);
  }
};

class Physical_fit : private Basic_info
{
private:
  float height;
  float weight;

public:
  //function which calls sub functions based on users choice since they are inaccessible from main function
  void work(int choice, Basic_info students[], Physical_fit students_derived[])
  {
    int node = 0;
    switch (choice)
    {
    case 1:
    {
      string name;
      int roll_number;
      char sex;
      cout << "Enter the name of the student: ";
      cin >> name;
      while (1)
      {
        cout << "Enter the roll number of the student: ";
        cin >> roll_number;
        if (this->findRoll(roll_number, students) == -1)
          break;
        cout << "\033[1;31m-----ROLL NUMBER EXSITS-----\033[0m" << endl;
        continue;
      }
      while (1)
      {
        cout << "Enter the SEX of the student(M/F/O): ";
        cin >> sex;
        if (sex == 'M' || sex == 'F' || sex == 'O')
          break;
        cout << "\033[1;31m Please select SEX between \033[1;32mM or F or O\033[0m" << endl;
      }
      this->updateBasicInfo(name, roll_number, sex, students);
      students_derived[actualSize].setData(name, roll_number, sex);
      actualSize++;
    }
    break;
    case 2:
    {
      int roll_number, which;
      while (1)
      {
        cout << "Enter the roll number of the student: ";
        cin >> roll_number;
        which = this->findRoll(roll_number, students);
        if (which == -1)
        {
          cout << "\033[1;31m-----ROLL NUMBER DOESNT EXISTS-----\033[0m" << endl;
          continue;
        }
        break;
      }
      students_derived[which].display();
    }
    break;
    case 3:
    {
      int roll_number, which;
      while (1)
      {
        cout << "Enter the roll number of the student: ";
        cin >> roll_number;
        which = this->findRoll(roll_number, students);
        if (which == -1)
        {
          cout << "\033[1;31m-----ROLL NUMBER DOESNT EXISTS-----\033[0m" << endl;
          continue;
        }
        break;
      }
      cout << "\033[1;34mBMI of the student is: " << students_derived[which].calculateBMI() << " Kg/m^2\033[0m" << endl;
    }
    default:
      break;
    }
  }
  void setData(string name, int roll_number, char sex)
  {
    this->setDetails(name, roll_number, sex);
    while (1)
    {
      cout << "Enter the height(in feet): ";
      cin >> this->height;
      cout << "Enter the weight(in kg): ";
      cin >> this->weight;
      if (this->height > 9)
      {
        cout << "\033[1;31mHeight can't be greater than 9 feet\033[0m" << endl;
        continue;
      }
      if (this->weight > 300)
      {
        cout << "\033[1;31mWeight can't be greater than 300kg\033[0m" << endl;
        continue;
      }
      if (this->weight <= 0 || this->height <= 0)
      {
        cout << "\033[1;31mHeight or weight can't be less than or equal to zero\033[0m" << endl;
        continue;
      }
      break;
    }
  }
  void getData()
  {
    this->getDetails();
    cout << "HEIGHT: " << this->height << " feets" << endl;
    cout << "WEIGHT: " << this->weight << " Kg\033[0m" << endl;
  }
  inline float calculateBMI()
  {
    int heightInMeters = this->height * 0.3048;
    return (this->weight / (heightInMeters * heightInMeters));
  }
  void display()
  {
    this->getData();
  }
};

int main()
{
  Physical_fit students_derived[SIZE];
  Basic_info students[SIZE];
  int choice = 1;
  cout << "-----PROGRAM FOR STUDENTS HEALTH DETAILS-----" << endl;
  while (choice != 4)
  {
    cout << "\033[1;35m1. Set Details" << endl;
    cout << "2. Display Details" << endl;
    cout << "3. Calcualte BMI(Metric Scale)" << endl;
    cout << "4. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      students_derived[0].work(choice, students, students_derived);
      break;
    case 2:
      students_derived[0].work(choice, students, students_derived);
      break;
    case 3:
      students_derived[0].work(choice, students, students_derived);
      break;
    case 4:
      cout << "\033[1;31m-----USER EXITED THE PROGRAM-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}