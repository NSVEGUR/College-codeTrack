#include <iostream>
#include <string>
using namespace std;

#define SIZE 1000
class Array
{
public:
  string arr[SIZE];
  int actualSize;
  Array(int n, string arr[])
  {
    this->actualSize = n;
    for (int i = 0; i < n; ++i)
      this->arr[i] = arr[i];
  }

  void display();
  void merge(string array[], int const left, int const mid, int const right);
  void mergeSort(string array[], int const begin, int const end);
  void convertToLowerCase(string array[]);
};

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Array::display()
{
  cout << "\033[1;34m";
  for (int i = 0; i < actualSize; ++i)
  {
    cout << i + 1 << " . " << this->arr[i] << endl;
  }
  cout << "\033[0m" << endl;
}

void Array::merge(string array[], int const left, int const mid, int const right)
{
  int const subArrayOne = mid - left + 1;
  int const subArrayTwo = right - mid;

  // Create temp arrays
  string *leftArray = new string[subArrayOne],
         *rightArray = new string[subArrayTwo];

  // Copy data to temp arrays leftArray[] and rightArray[]
  for (int i = 0; i < subArrayOne; i++)
    leftArray[i] = array[left + i];
  for (int j = 0; j < subArrayTwo; j++)
    rightArray[j] = array[mid + 1 + j];

  int indexOfSubArrayOne = 0,    // Initial index of first sub-array
      indexOfSubArrayTwo = 0;    // Initial index of second sub-array
  int indexOfMergedArray = left; // Initial index of merged array

  // Merge the temp arrays back into array[left..right]
  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
  {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
    {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    }
    else
    {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }
  // Copy the remaining elements of
  // left[], if there are any
  while (indexOfSubArrayOne < subArrayOne)
  {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }
  // Copy the remaining elements of
  // right[], if there are any
  while (indexOfSubArrayTwo < subArrayTwo)
  {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void Array::mergeSort(string array[], int const begin, int const end)
{
  if (begin >= end)
    return; // Returns recursively

  int mid = begin + (end - begin) / 2;
  this->mergeSort(array, begin, mid);
  this->mergeSort(array, mid + 1, end);
  this->merge(array, begin, mid, end);
}

void Array::convertToLowerCase(string array[])
{
  for (int i = 0; i < this->actualSize; i++)
    for (int j = 0; j < array[i].length(); j++)
      array[i][j] = tolower(array[i][j]);
}

int main()
{
  int actualSize, choice = 1;
  string arr[SIZE];
  cout << "\033[1;33m-----Program for sorting algorithms-----\033[0m" << endl;
  cout << "Enter the size of the array you wanna create: ";
  cin >> actualSize;
  cout << "\033[1;32m-----Enter the words-----\033[0m" << endl;
  for (int i = 0; i < actualSize; i++)
  {
    cout << "Enter word - " << i + 1 << " : ";
    cin >> arr[i];
  }
  Array array(actualSize, arr);
  cout << "\033[1;31mSINCE IN DICTIONARY WORDS ARE ARRANGED ON ALPHABETS BUT NOT ON (CAPS OR SMALL) SO CONVERTING THEM TO SMALL" << endl;
  array.convertToLowerCase(array.arr);
  array.mergeSort(array.arr, 0, array.actualSize - 1);
  cout << "\033[1;33m-----Words after arrangement-----\033[0m" << endl;
  array.display();
  return 0;
}
