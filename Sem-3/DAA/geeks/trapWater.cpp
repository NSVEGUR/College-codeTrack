#include <iostream>

using namespace std;

class TrapWater
{
public:
  int SIZE, arr[1000], height, height_temp, trappedWater;
  TrapWater()
  {
    cout << "Enter the Number of Blocks(size of the array): ";
    cin >> this->SIZE;
    cout << "Enter the height of " << this->SIZE << " Blocks: " << endl;
    for (int i = 0; i < this->SIZE; ++i)
    {
      cout << "Height of the Block - " << i + 1 << " = ";
      cin >> this->arr[i];
      cout << endl;
    }
  }
  void gaurd();
  void printBlocks();
  void countTrappedWater();
};

void TrapWater::gaurd()
{
  for (int i = 0; i < this->SIZE; ++i)
  {
    if (this->arr[i] < 0)
    {
      cout << "\033[1;31m-----Please use only non negetive integers-----\033[0m" << endl;
      exit(0);
    }
  }
}
void TrapWater::printBlocks()
{
  cout << "Blocks are: [";
  for (int i = 0; i < this->SIZE - 1; ++i)
  {
    cout << this->arr[i] << " , ";
  }
  cout << this->arr[this->SIZE - 1] << "]" << endl;
}
void TrapWater::countTrappedWater()
{
  int left = 0, right = this->SIZE - 1;
  int leftMax = 0, rightMax = 0;
  this->trappedWater = 0;
  while (left < right)
  {
    if (this->arr[left] <= this->arr[right])
    {
      if (this->arr[left] >= leftMax)
      {
        leftMax = arr[left];
      }
      else
      {
        this->trappedWater += leftMax - this->arr[left];
      }
      left++;
    }
    else
    {
      if (this->arr[right] >= rightMax)
      {
        rightMax = this->arr[right];
      }
      else
      {
        this->trappedWater += rightMax - this->arr[right];
      }
      right--;
    }
  }
}
int main()
{
  cout << "-----Program to find the Trapped rain water-----" << endl;
  TrapWater trap_1;
  trap_1.gaurd();
  trap_1.printBlocks();
  trap_1.countTrappedWater();
  cout << "\033[1;34mTrapped water = " << trap_1.trappedWater << "\033[0m" << endl;
  return 0;
}