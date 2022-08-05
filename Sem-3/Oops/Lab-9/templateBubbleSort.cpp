#include <iostream>
using namespace std;
#define SIZE 1000

template <typename T>
class Array
{
public:
  T arr[SIZE];
  int actualSize;
  Array(T arr[], int actualSize);
  void display();
  void bubbleSort();
  void swap(T *a, T *b);
};

template <typename T>
Array<T>::Array(T *arr, int actualSize)
{
  this->actualSize = actualSize;
  for (int i = 0; i < actualSize; ++i)
    this->arr[i] = *(arr + i);
}

template <typename T>
void Array<T>::swap(T *a, T *b)
{
  T temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
void Array<T>::bubbleSort()
{
  for (int i = 0; i < this->actualSize - 1; ++i)
    for (int j = 0; j < this->actualSize - i - 1; ++j)
      if (this->arr[j] > this->arr[j + 1])
        this->swap(&this->arr[j], &this->arr[j + 1]);
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

bool validSize(int n)
{
  if (n <= 0)
    return false;
  return true;
}

int main()
{
  int actualSize, choice = 1;
  while (choice != 6)
  {
    cout << "\033[1;32m1. Sort integer numbers array" << endl;
    cout << "2. Sort floating point numbers array" << endl;
    cout << "3. Sort Double array" << endl;
    cout << "4. Sort Characters array" << endl;
    cout << "5. Sort String array" << endl;
    cout << "6. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      int *arr = new int[SIZE];
      while (1)
      {
        cout << "Enter the size of the array: ";
        cin >> actualSize;
        if (validSize(actualSize))
          break;
        cout << "\033[1;31m-----INVALID SIZE-----\033[0m" << endl;
      }
      cout << "\033[1;33mEnter the elements of the array: \033[0m" << endl;
      for (int i = 0; i < actualSize; i++)
      {
        cout << "Enter the element - " << i + 1 << " : ";
        cin >> *(arr + i);
      }
      Array<int> array(arr, actualSize);
      cout << "\033[1;33m-----ARRAY BEFORE SORTING-----" << endl;
      array.display();
      array.bubbleSort();
      cout << "\033[1;33m-----ARRAY AFTER SORTING-----" << endl;
      array.display();
    }
    break;
    case 2:
    {
      float *arr = new float[SIZE];
      while (1)
      {
        cout << "Enter the size of the array: ";
        cin >> actualSize;
        if (validSize(actualSize))
          break;
        cout << "\033[1;31m-----INVALID SIZE-----\033[0m" << endl;
      }
      cout << "\033[1;33mEnter the elements of the array: \033[0m" << endl;
      for (int i = 0; i < actualSize; i++)
      {
        cout << "Enter the element - " << i + 1 << " : ";
        cin >> *(arr + i);
      }
      Array<float> array(arr, actualSize);
      cout << "\033[1;33m-----ARRAY BEFORE SORTING-----" << endl;
      array.display();
      array.bubbleSort();
      cout << "\033[1;33m-----ARRAY AFTER SORTING-----" << endl;
      array.display();
    }
    break;
    case 3:
    {
      double *arr = new double[SIZE];
      while (1)
      {
        cout << "Enter the size of the array: ";
        cin >> actualSize;
        if (validSize(actualSize))
          break;
        cout << "\033[1;31m-----INVALID SIZE-----\033[0m" << endl;
      }
      cout << "\033[1;33mEnter the elements of the array: \033[0m" << endl;
      for (int i = 0; i < actualSize; i++)
      {
        cout << "Enter the element - " << i + 1 << " : ";
        cin >> *(arr + i);
      }
      Array<double> array(arr, actualSize);
      cout << "\033[1;33m-----ARRAY BEFORE SORTING-----" << endl;
      array.display();
      array.bubbleSort();
      cout << "\033[1;33m-----ARRAY AFTER SORTING-----" << endl;
      array.display();
    }
    break;
    case 4:
    {
      char *arr = new char[SIZE];
      while (1)
      {
        cout << "Enter the size of the array: ";
        cin >> actualSize;
        if (validSize(actualSize))
          break;
        cout << "\033[1;31m-----INVALID SIZE-----\033[0m" << endl;
      }
      cout << "\033[1;33mEnter the elements of the array: \033[0m" << endl;
      for (int i = 0; i < actualSize; i++)
      {
        cout << "Enter the element - " << i + 1 << " : ";
        cin >> *(arr + i);
      }
      Array<char> array(arr, actualSize);
      cout << "\033[1;33m-----ARRAY BEFORE SORTING-----" << endl;
      array.display();
      array.bubbleSort();
      cout << "\033[1;33m-----ARRAY AFTER SORTING-----" << endl;
      array.display();
    }
    break;
    case 5:
    {
      string *arr = new string[SIZE];
      while (1)
      {
        cout << "Enter the size of the array: ";
        cin >> actualSize;
        if (validSize(actualSize))
          break;
        cout << "\033[1;31m-----INVALID SIZE-----\033[0m" << endl;
      }
      cout << "\033[1;33mEnter the elements of the array: \033[0m" << endl;
      for (int i = 0; i < actualSize; i++)
      {
        cout << "Enter the element - " << i + 1 << " : ";
        cin >> *(arr + i);
      }
      Array<string> array(arr, actualSize);
      cout << "\033[1;33m-----ARRAY BEFORE SORTING-----" << endl;
      array.display();
      array.bubbleSort();
      cout << "\033[1;33m-----ARRAY AFTER SORTING-----" << endl;
      array.display();
    }
    break;
    case 6:
      cout << "\033[1;31m-----USER EXITED THE PROGRAM-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----INVALID CHOICE-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}