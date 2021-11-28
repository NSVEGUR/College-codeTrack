#include <iostream>
using namespace std;

#define SIZE 1000

class Array
{
private:
  int arr[SIZE], actualSize, element;

public:
  Array(int n, int arr[])
  {
    this->actualSize = n;
    for (int i = 0; i < n; ++i)
      this->arr[i] = arr[i];
  }
  int countNegetiveInt_TwoWay(int left, int right);
  int countNegetiveInt_ThreeWay(int left, int right);
};

int Array::countNegetiveInt_TwoWay(int left, int right)
{
  if (left == right && this->arr[left] < 0)
    return 1;
  else if (left == right && this->arr[left] >= 0)
    return 0;
  int mid = (right + left) / 2;
  return this->countNegetiveInt_TwoWay(left, mid) + this->countNegetiveInt_TwoWay(mid + 1, right);
}

int Array::countNegetiveInt_ThreeWay(int left, int right)
{
  if (left == right && this->arr[right] < 0)
    return 1;
  else if (left == right && this->arr[right] >= 0)
    return 0;
  else if (left > right)
    return 0;
  else
  {
    int temp = 0;
    int n = (right - (left - 1));
    int *l = new int[3];
    int *r = new int[3];
    for (int i = 0; i < 3; ++i)
    {
      l[i] = (i == 0) ? left : r[i - 1] + 1;
      r[i] = (n % 3 > i) ? l[i] + (n / 3) : l[i] + (n / 3) - 1;
      temp += this->countNegetiveInt_ThreeWay(l[i], r[i]);
    }
    return temp;
  }
}

int main()
{
  cout << "-----Program for counting number of negetive integers in an array-----" << endl;
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
  Array array(n, arr);
  cout << "Number of Negetive integers in the input array: " << endl;
  cout << "\033[1;34mCalculating in Two way: " << array.countNegetiveInt_TwoWay(0, n - 1) << endl;
  cout << "Calculating in Three way: " << array.countNegetiveInt_ThreeWay(0, n - 1) << "\033[0m" << endl;
  return 0;
}