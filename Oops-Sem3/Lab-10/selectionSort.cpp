#include <iostream>
using namespace std;
#define SIZE 1000

template <typename T>
class Array
{
private:
  T arr[SIZE];
  int actualSize;

public:
  Array(int size)
  {
    this->actualSize = size;
  }
  void create(T arr[], int actualSize);
  void selectionSort();
  void display();
};

template <typename T>
void Array<T>::create(T arr[], int actualSize)
{
  this->actualSize = actualSize;
  for (int i = 0; i < actualSize; ++i)
    this->arr[i] = arr[i];
}

template <typename T>
void swap(T *a, T *b)
{
  T temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
void Array<T>::selectionSort()
{
  for (int i = 0; i < this->actualSize - 1; ++i)
    for (int j = i + 1; j < this->actualSize; ++j)
      if (this->arr[i] > this->arr[j])
        swap(&this->arr[i], &this->arr[j]);
}

template <typename T>
void Array<T>::display()
{
  cout << "\033[1;34m[ ";
  for (int i = 0; i < actualSize - 1; ++i)
  {
    cout << this->arr[i] << " , ";
  }
  cout << this->arr[actualSize - 1] << " ]\033[0m" << endl;
}

template <typename T>
void menuDriven(int n)
{
  int choice = 1;
  char flag = 'a';
  Array<T> array(n);
handleError3:
  try
  {
    cout << "\033[1;33m1. Get Values" << endl;
    cout << "2. Sort" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 4)
    {
      cout << "\033[1;31mProgram Exited By user\033[0m" << endl;
      exit(0);
    }
    else if (choice > 4 || choice <= 0)
      throw choice;
    else if (choice == 2 || choice == 3)
    {
      if (flag == 'a')
        throw flag;
    }
  }
  catch (int choice)
  {
    cout << "\033[1;31mInvalid choice\033[0m" << endl;
    goto handleError3;
  }
  catch (char flag)
  {
    cout << "\033[1;31mArray is empty\033[0m" << endl;
    goto handleError3;
  }
  if (choice == 1)
  {
    T arr[n];
    cout << "\033[1;32mEnter the elements of the array:\033[0m" << endl;
    for (int i = 0; i < n; ++i)
    {
      cout << "Enter the element " << i + 1 << " : ";
      cin >> arr[i];
    }
    array.create(arr, n);
    cout << "\033[1;34mArray created successfully\033[0m" << endl;
    flag = 'b';
  }
  if (choice == 2)
    array.selectionSort();
  if (choice == 3)
    array.display();
  goto handleError3;
}

int main()
{
  cout << "-----Program for Selection sort using execption handling-----" << endl;
  int n;
  int choice = 1;
handleError1:
  try
  {
    cout << "Enter the size of the array: ";
    cin >> n;
    if (n <= 0)
      throw n;
  }
  catch (int n)
  {
    cout << "\033[1;31mSIZE CAN'T BE 0 or NEGETIVE\033[0m" << endl;
    goto handleError1;
  }
handleError2:
  try
  {
    cout << "Enter the type of the Array: " << endl;
    cout << "\033[1;32m1. Integer" << endl;
    cout << "2. Float" << endl;
    cout << "3. Character" << endl;
    cout << "4. String" << endl;
    cout << "5. Double\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice > 5 || choice <= 0)
      throw choice;
  }
  catch (int n)
  {
    cout << "\033[1;31mINVALID CHOICE\033[0m" << endl;
    goto handleError2;
  }
  switch (choice)
  {
  case 1:
    cout << "\033[1;35m-----Implementation of Integer Array-----\033[0m" << endl;
    menuDriven<int>(n);
    break;
  case 2:
    cout << "\033[1;35m-----Implementation of Float Array-----\033[0m" << endl;
    menuDriven<float>(n);
    break;
  case 3:
    cout << "\033[1;35m-----Implementation of Character Array-----\033[0m" << endl;
    menuDriven<char>(n);
    break;
  case 4:
    cout << "\033[1;35m-----Implementation of String Array-----\033[0m" << endl;
    menuDriven<string>(n);
    break;
  case 5:
    cout << "\033[1;35m-----Implementation of Double Array-----\033[0m" << endl;
    menuDriven<double>(n);
    break;
  }
  return 0;
}