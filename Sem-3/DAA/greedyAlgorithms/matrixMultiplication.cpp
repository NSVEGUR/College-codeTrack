#include <iostream>
using namespace std;
#define SIZE 1000

class Array
{
public:
  int arr[SIZE], actualSize, reducedSize, reformedArr[SIZE];
  Array(int actualSize, int arr[])
  {
    this->actualSize = actualSize;
    this->reducedSize = actualSize;
    for (int i = 0; i < this->actualSize; ++i)
      this->arr[i] = arr[i];
    for (int i = 0; i < this->reducedSize; ++i)
      this->reformedArr[i] = arr[i];
  }
  int calculateRate();
  int findMinPair();
};

int Array::findMinPair()
{
  int minIndex = 0;
  int min = INT_MAX;
  for (int i = 0; i < this->reducedSize - 2; i++)
  {
    if (((this->reformedArr[i] * this->reformedArr[i + 1]) + (this->reformedArr[i + 1] * this->reformedArr[i + 2])) < min)
    {
      min = ((this->reformedArr[i] * this->reformedArr[i + 1]) + (this->reformedArr[i + 1] * this->reformedArr[i + 2]));
      minIndex = i;
    }
  }
  return minIndex;
}

int Array::calculateRate()
{
  int rate = 0;
  if (this->actualSize < 3)
    return -1;
  while (this->reducedSize > 3)
  {
    int minPairIndex = this->findMinPair();
    rate += (this->reformedArr[minPairIndex] * this->reformedArr[minPairIndex + 1]) + (this->reformedArr[minPairIndex + 1] * this->reformedArr[minPairIndex + 2]);
    for (int i = minPairIndex + 1; i < this->reducedSize - 1; i++)
    {
      this->reformedArr[i] = this->reformedArr[i + 1];
    }
    this->reducedSize--;
  }
  rate += (this->reformedArr[0] * this->reformedArr[1]) + (this->reformedArr[1] * this->reformedArr[2]);
  return rate;
}

int main()
{
  int arr[SIZE], n;
  cout << "-----Greedy approach for matrix chain multiplicatoin-----";
  cout << "\033[1;31mNOTE:" << endl;
  cout << "\033[1;33mHere we take Array as input which should contain atleast 3 elements to check chain multiplication cost." << endl;
  cout << "if a b and c are inputs a*b and b*c is the matrix multiplication done for 3 elements and so on.\033[0m" << endl;
  cout << "Enter the size of the array: ";
  cin >> n;
  cout << "\033[1;32mEnter the elements of the array:\033[0m" << endl;
  for (int i = 0; i < n; ++i)
  {
    cout << "Enter the element " << i + 1 << " : ";
    cin >> arr[i];
  }
  Array array(n, arr);
  cout << "\033[1;34mCOST FOR CHAIN MATRIX MULTIPLICATION(THROUGH GREEDY APPROACH): \033[1;35m" << array.calculateRate() << "\033[0m" << endl;
  return 0;
}