#include <iostream>
#include <ctime>
using namespace std;

#define SIZE 1000
class Array
{
public:
  int arr[SIZE], actualSize;
  Array(int n, int arr[])
  {
    this->actualSize = n;
    for (int i = 0; i < n; ++i)
      this->arr[i] = arr[i];
  }

  void dualPivotQuickSort(int *arr, int low, int high);
  int partition(int *arr, int low, int high, int *lp);
  void display();
};

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Array::display()
{
  cout << "\033[1;34m[ ";
  for (int i = 0; i < actualSize - 1; ++i)
  {
    cout << this->arr[i] << " , ";
  }
  cout << this->arr[actualSize - 1] << " ]\033[0m" << endl;
}

void Array::dualPivotQuickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    // lp means left pivot, and rp means right pivot.
    int lp, rp;
    rp = this->partition(arr, low, high, &lp);
    this->dualPivotQuickSort(arr, low, lp - 1);
    this->dualPivotQuickSort(arr, lp + 1, rp - 1);
    this->dualPivotQuickSort(arr, rp + 1, high);
  }
}

int Array::partition(int *arr, int low, int high, int *lp)
{
  if (arr[low] > arr[high])
    swap(&arr[low], &arr[high]);

  // p is the left pivot, and q is the right pivot.
  int j = low + 1;
  int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
  while (k <= g)
  {

    // if elements are less than the left pivot
    if (arr[k] < p)
    {
      swap(&arr[k], &arr[j]);
      j++;
    }

    // if elements are greater than or equal
    // to the right pivot
    else if (arr[k] >= q)
    {
      while (arr[g] > q && k < g)
        g--;
      swap(&arr[k], &arr[g]);
      g--;
      if (arr[k] < p)
      {
        swap(&arr[k], &arr[j]);
        j++;
      }
    }
    k++;
  }
  j--;
  g++;

  // bring pivots to their appropriate positions.
  swap(&arr[low], &arr[j]);
  swap(&arr[high], &arr[g]);

  // returning the indices of the pivots.
  *lp = j; // because we cannot return two elements
  // from a function.

  return g;
}

int main()
{
  srand(time(NULL));
  int arr[SIZE], actualSize;
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
  array.dualPivotQuickSort(array.arr, 0, array.actualSize - 1);
  cout << "\033[1;33m-----ARRAY AFTER DUAL PIVOT QUICK SORT-----" << endl;
  array.display();
  return 0;
}