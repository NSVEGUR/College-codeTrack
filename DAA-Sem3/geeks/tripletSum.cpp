#include <iostream>

using namespace std;

class TripletSum
{
public:
  int SIZE, arr[1000], tripletSum;
  TripletSum()
  {
    cout << "Enter the size of the array: ";
    cin >> this->SIZE;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < this->SIZE; ++i)
    {
      cout << "Enter element - " << i + 1 << " = ";
      cin >> this->arr[i];
    }
    cout << "Enter the number which you wanna check its triplet sum existence: ";
    cin >> this->tripletSum;
  }
  void bubbleSort();
  bool checkTripletSum();
};
void TripletSum::bubbleSort()
{
  for (int i = 0; i < this->SIZE - 1; ++i)
  {
    for (int j = 0; j < this->SIZE - i - 1; ++j)
    {
      if (this->arr[j] > this->arr[j + 1])
      {
        int temp = this->arr[j];
        this->arr[j] = this->arr[j + 1];
        this->arr[j + 1] = temp;
      }
    }
  }
}
bool TripletSum::checkTripletSum()
{
  int j, k;
  for (int i = 0; i < this->SIZE - 1; ++i)
  {
    j = i + 1;
    k = this->SIZE - 1;
    while (j < k)
    {
      if (this->arr[i] + this->arr[j] + this->arr[k] == this->tripletSum)
        return true;
      else if (this->arr[i] + this->arr[j] + this->arr[k] > this->tripletSum)
        --k;
      else
        ++j;
    }
  }
  return false;
}
int main()
{
  cout << "-----Program to find whether the triplet sum of given number exits or not in the given array-----" << endl;
  TripletSum array_1;
  array_1.bubbleSort();
  if (array_1.checkTripletSum())
    cout << "\033[1;34mTriplet sum exists!!\033[0m" << endl;
  else
    cout << "\033[1;31mTriplet sum don't exists!!\033[0m" << endl;
  return 0;
}