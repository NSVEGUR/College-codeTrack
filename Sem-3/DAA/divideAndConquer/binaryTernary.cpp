#include <iostream>
using namespace std;

#define SIZE 1000

class Array
{
private:
  int arr[SIZE], actualSize, element;

public:
  Array(int n, int arr[], int x)
  {
    this->actualSize = n;
    this->element = x;
    for (int i = 0; i < n; ++i)
      this->arr[i] = arr[i];
  }
  bool binaryRecursive(int left, int right);
  bool binaryIterative();
  bool ternaryRecursive(int left, int right);
  bool ternaryIterative();
  void program();
};

bool Array::binaryRecursive(int left, int right)
{
  if (right >= left)
  {
    int middle = (right + left) / 2;
    if (this->arr[middle] == this->element)
      return true;
    if (this->arr[middle] > this->element)
      return this->binaryRecursive(left, middle - 1);

    return this->binaryRecursive(middle + 1, right);
  }

  return false;
}

bool Array::binaryIterative()
{
  int left = 0, right = this->actualSize - 1;
  while (left <= right)
  {
    int middle = (left + right) / 2;

    if (this->arr[middle] == this->element)
      return true;
    else if (this->arr[middle] > this->element)
      right = middle - 1;
    else
      left = middle + 1;
  }
  return false;
}

bool Array::ternaryRecursive(int left, int right)
{
  if (left <= right)
  {
    int mid1 = (2 * left + right) / 3;
    int mid2 = (2 * right + left) / 3;
    if (this->arr[mid1] == this->element)
      return true;
    if (this->arr[mid2] == this->element)
      return true;
    if (this->element < this->arr[mid1])
      return this->ternaryRecursive(left, mid1 - 1);
    else if (this->element > this->arr[mid2])
      return this->ternaryRecursive(mid2 + 1, right);
    else
      return this->ternaryRecursive(mid1 + 1, mid2 - 1);
  }

  return false;
}

bool Array::ternaryIterative()
{
  int left = 0, right = this->actualSize - 1;
  while (left <= right)
  {
    int mid1 = (2 * left + right) / 3;
    int mid2 = (2 * right + left) / 3;
    if (this->arr[mid1] == this->element)
      return true;
    if (this->arr[mid2] == this->element)
      return true;
    if (this->element < this->arr[mid1])
      right = mid1 - 1;
    else if (this->element > this->arr[mid2])
      left = mid2 + 1;
    else
    {
      left = mid1 + 1;
      right = mid2 - 1;
    }
  }

  return false;
}

void conclude(bool presence, int element)
{
  if (presence)
    cout << "\033[1;34m " << element << " is present in the input array.\033[0m" << endl;
  else
    cout << "\033[1;31m " << element << " is not present in the input array.\033[0m" << endl;
}

void Array::program()
{
  int choice = 1;
  while (choice != 5)
  {
    cout << "1. Binary Search the element Recursively." << endl;
    cout << "2. Binary Search the element Iteratively." << endl;
    cout << "3. Ternary Search the element Recursively." << endl;
    cout << "4. Ternary Search the element Iteratively." << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      conclude(this->binaryRecursive(0, this->actualSize - 1), this->element);
      break;
    case 2:
      conclude(this->binaryIterative(), this->element);
      break;
    case 3:
      conclude(this->ternaryRecursive(0, this->actualSize - 1), this->element);
      break;
    case 4:
      conclude(this->ternaryIterative(), this->element);
      break;
    case 5:
      cout << "\033[1;33m-----Program is exited by the user-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----Enter a valid choice------\033[0m" << endl;
      break;
    }
  }
}

int main()
{
  cout << "-----Program for Searching an element in a \033[1;31mSORTED ARRAY\033[0m in four different forms-----" << endl;
  int n, x;
  cout << "Enter the number of elements in the array: ";
  cin >> n;
  int arr[n];
  cout << "Please enter the elements of the array in \033[1;31mSORTED\033[0m order" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter element - " << i + 1 << " :";
    cin >> arr[i];
  }
  cout << "-----Array created-----" << endl;
  cout << "Enter the element to Array in the input array: ";
  cin >> x;
  Array array(n, arr, x);
  array.program();
  return 0;
}