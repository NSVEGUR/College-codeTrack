#include <iostream>

using namespace std;

class SubArray
{
public:
  int SIZE, arr[1000], sum, tempSum;
  SubArray()
  {
    cout << "Enter the Size of the array: ";
    cin >> this->SIZE;
    if (this->SIZE <= 0)
    {
      cout << "\033[1;31m-----INVALID SIZE OF THE ARRAY-----\033[0m" << endl;
      exit(0);
    }
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < this->SIZE; ++i)
    {
      cout << "Enter element - " << i + 1 << " : ";
      cin >> this->arr[i];
    }
  }
  int calculateSumOfSubArrays();
};
int SubArray::calculateSumOfSubArrays()
{
  this->sum = this->tempSum = 0;
  for (int i = 0; i < this->SIZE; ++i)
  {
    for (int j = i; j < this->SIZE; ++j)
    {
      this->sum += this->tempSum + this->arr[j];
      this->tempSum += this->arr[j];
    }
    this->tempSum = 0;
  }
  return this->sum;
}
int main()
{
  cout << "-----Program to print sum of all elements in the subarray-----" << endl;
  SubArray array_1;
  int sum = array_1.calculateSumOfSubArrays();
  cout << "\033[1;34mSum of elements in all the sub arrays is = " << sum << "\033[0m" << endl;
  return 0;
}