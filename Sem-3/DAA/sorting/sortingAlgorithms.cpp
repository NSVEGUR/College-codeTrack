#include <iostream>
#include <ctime>
using namespace std;

#define SIZE 1000

class Array
{

public:
  int arr[SIZE], actualSize;
  Array(int actualSize, int arr[])
  {
    this->actualSize = actualSize;
    for (int i = 0; i < actualSize; ++i)
      this->arr[i] = arr[i];
  }
  void display();
  void selectionSort();
  void bubbleSort();
  void insertionSort();
  void mergeSort();
  void heapSort();
  void quickSort(int arr[], int low, int high);
};

void Array::display()
{
  cout << "\033[1;34m[ ";
  for (int i = 0; i < actualSize - 1; ++i)
  {
    cout << this->arr[i] << " , ";
  }
  cout << this->arr[actualSize - 1] << " ]\033[0m" << endl;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Array::selectionSort()
{
  for (int i = 0; i < this->actualSize - 1; ++i)
    for (int j = i + 1; j < this->actualSize; ++j)
      if (this->arr[i] > this->arr[j])
        swap(&this->arr[i], &this->arr[j]);
  cout << "-----SORTED ARRAY WITH SELECTION SORT-----" << endl;
}

void Array::bubbleSort()
{
  for (int i = 0; i < this->actualSize - 1; ++i)
    for (int j = 0; j < this->actualSize - i - 1; ++j)
      if (this->arr[j] > this->arr[j + 1])
        swap(&this->arr[j], &this->arr[j + 1]);
  cout << "-----SORTED ARRAY WITH BUBBLE SORT-----" << endl;
}

void Array::insertionSort()
{
  for (int i = 1; i < this->actualSize; ++i)
  {
    if (this->arr[i] < this->arr[i - 1])
    {
      for (int j = i; j > 0; --j)
        if (this->arr[j] < this->arr[j - 1])
          swap(&this->arr[j], &this->arr[j - 1]);
    }
  }
  cout << "-----SORTED ARRAY WITH INSERTION SORT-----" << endl;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than or
    // equal to pivot
    if (arr[j] <= pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void Array::quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    /* pi is partitioning index, arr[p] is now
           at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  srand(time(NULL));
  int arr[SIZE], actualSize, choice = 1;
  cout << "\033[1;33m-----Program for sorting algorithms-----\033[0m" << endl;
  cout << "Enter the size of the array you wanna create: ";
  cin >> actualSize;
  for (int i = 0; i < actualSize; ++i)
  {
    arr[i] = rand() % 1001;
  }
  Array array(actualSize, arr);
  cout << "\033[1;33m-----INPUT ARRAY-----" << endl;
  array.display();
  cout << "\033[1;33m-----SORTING-----" << endl;
  cout << "\033[1;32m1. Selection Sort" << endl;
  cout << "2. Bubble Sort" << endl;
  cout << "3. Insertion Sort" << endl;
  cout << "4. Merge Sort" << endl;
  cout << "5. Heap Sort" << endl;
  cout << "6. Quick Sort" << endl;
  cout << "x. Default exits the program\033[0m" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  switch (choice)
  {
  case 1:
    array.selectionSort();
    array.display();
    break;
  case 2:
    array.bubbleSort();
    array.display();
    break;
  case 3:
    array.insertionSort();
    array.display();
    break;
  case 6:
    array.quickSort(array.arr, 0, array.actualSize - 1);
    cout << "-----SORTED ARRAY WITH QUICK SORT-----" << endl;
    array.display();
    break;
  default:
    cout << "\033[1;31m-----PROGRAM EXITED BY THE USER-----\033[0m" << endl;
    break;
  }
  return 0;
}