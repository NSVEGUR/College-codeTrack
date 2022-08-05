#include <iostream>
using namespace std;

#define SIZE 1000

class FindMax
{
private:
  int arr[SIZE];

public:
  int actualSize;
  FindMax(int n, int arr[])
  {
    this->actualSize = n;
    for (int i = 0; i < n; ++i)
      this->arr[i] = arr[i];
  }
  int oneWay();
  int twoWay(int left, int right);
  int threeWay(int left, int right);
  int k_way(int left, int right, int k);
};

int FindMax::oneWay()
{
  int max = arr[0];
  for (int i = 1; i < this->actualSize; ++i)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int FindMax::twoWay(int left, int right)
{
  if (right == left)
    return arr[right];
  int mid = (right + left) / 2;
  int a = this->twoWay(left, mid);
  int b = this->twoWay(mid + 1, right);
  return a > b ? a : b;
}

int FindMax::threeWay(int left, int right)
{
  if (left == right)
    return this->arr[right];
  else if (left > right)
    return 0;
  else
  {
    int n = (right - (left - 1));
    int max = 0;
    int *l = new int[3];
    int *r = new int[3];
    for (int i = 0; i < 3; ++i)
    {
      l[i] = (i == 0) ? left : r[i - 1] + 1;
      r[i] = (n % 3 > i) ? l[i] + (n / 3) : l[i] + (n / 3) - 1;
      int temp = this->threeWay(l[i], r[i]);
      if (temp > max)
      {
        max = temp;
      }
    }
    return max;
  }
}

int FindMax::k_way(int left, int right, int k)
{
  if (left == right)
    return this->arr[right];
  else if (left > right)
    return INT_MIN;
  else
  {
    int n = (right - (left - 1));
    int max = INT_MIN;
    int *l = new int[k];
    int *r = new int[k];
    for (int i = 0; i < k; ++i)
    {
      l[i] = (i == 0) ? left : r[i - 1] + 1;
      r[i] = (n % k > i) ? l[i] + (n / k) : l[i] + (n / k) - 1;
      int temp = this->k_way(l[i], r[i], k);
      if (temp > max)
      {
        max = temp;
      }
    }
    return max;
  }
}

int main()
{
  cout << "-----Program for finding Max using divide and conquer algorithm-----" << endl;
  int n;
  cout << "Enter the number of elements in the array: ";
  cin >> n;
  int arr[n];
  cout << "Please enter the elements of the array" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter element - " << i + 1 << " :";
    cin >> arr[i];
  }
  cout << "-----Array created-----" << endl;
  FindMax array(n, arr);
  int choice = 1, k;
  while (choice != 5)
  {
    cout << "Choose options for finding max in different ways: " << endl;
    cout << "\033[1;33m1. One way" << endl;
    cout << "2. Two way" << endl;
    cout << "3. Three way" << endl;
    cout << "4. K way" << endl;
    cout << "5. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Maximum found in \033[1;32mONE WAY \033[0m is: \033[1;34m" << array.oneWay() << "\033[0m" << endl;
      break;
    case 2:
      cout << "Maximum found in \033[1;32mTWO WAY \033[0m is: \033[1;34m" << array.twoWay(0, n - 1) << "\033[0m" << endl;
      break;
    case 3:
      cout << "Maximum found in \033[1;32mTHREE WAY \033[0m is: \033[1;34m" << array.threeWay(0, n - 1) << "\033[0m" << endl;
      break;
    case 4:
      while (1)
      {
        cout << "Enter the value of k (way of finding max): ";
        cin >> k;
        if (k > 1)
          break;
        cout << "\033[1;31mENTER VALUE OF K GREATER THAN 1\033[0m" << endl;
      }
      cout << "Maximum found in \033[1;32m " << k << " WAY \033[0m is: \033[1;34m" << array.k_way(0, n - 1, k) << "\033[0m" << endl;
      break;
    case 5:
      cout << "\033[1;31m-----PROGRAM TERMINATED BY THE USER-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31mENTER A VALID CHOICE\033[0m" << endl;
      break;
    }
  }
  return 0;
}