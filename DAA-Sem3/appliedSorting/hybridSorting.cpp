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

  void display();
  int mergeSort(int n, int m, int s, int arr[]);
  int insertSort(int arr[], int n, int m);
  void shiftArr(int start, int m, int arr[]);
  int merge(int n, int m, int s, int arr[]);
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

int Array::mergeSort(int n, int m, int s, int arr[])
{
  int mid = (n + m) / 2, right = 0, left = 0;
  if (m - n <= s)
    return insertSort(arr, n, m);
  else
  {
    right = mergeSort(n, mid, s, arr);
    left = mergeSort(mid + 1, m, s, arr);
    return right + left + merge(n, m, s, arr);
  }
}

int Array::insertSort(int arr[], int n, int m)
{
  int temp, comp = 0;
  for (int i = n + 1; i <= m; i++)
  {
    for (int j = i; j > n; j--)
    {
      comp++;
      if (arr[j] < arr[j - 1])
      {
        temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      }
      else
        break;
    }
  }
  return comp;
}

void Array::shiftArr(int start, int m, int arr[])
{
  for (int i = m; i > start; i--)
    arr[i] = arr[i - 1];
}

int Array::merge(int n, int m, int s, int arr[])
{
  int comp = 0;
  if (m - n <= s)
    return 0;
  int mid = (n + m) / 2;
  int temp, i = n, j = mid + 1;
  while (i <= mid && j <= m)
  {
    comp++;

    if (arr[i] >= arr[j])
    {
      if (i == mid++ && j == m && (arr[i] == arr[j]))
        break;
      temp = arr[j];
      shiftArr(i, j++, arr);
      arr[i] = temp;
      if (arr[i + 1] == arr[i])
      {
        i++;
      }
    }
    i++;
  }
  return comp;
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
  array.mergeSort(0, actualSize - 1, 20, array.arr);
  cout << "\033[1;33m-----ARRAY AFTER HYBRID SORTING-----" << endl;
  array.display();
  return 0;
}