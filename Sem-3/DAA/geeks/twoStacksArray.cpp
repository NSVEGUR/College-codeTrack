#include <iostream>

using namespace std;

#define SIZE 6

class TwoStacksArray
{
public:
  int top1 = -1, top2 = -1, arr[SIZE];
  void push1(int num);
  void push2(int num);
  int pop1();
  int pop2();
};
void TwoStacksArray::push1(int num)
{
  if (this->top1 == SIZE / 2 && SIZE % 2 == 0)
  {
    cout << "\033[1;31m STACK-1 IS FULL\033[0m" << endl;
    exit(0);
  }
  else if (this->top1 == SIZE / 2 + 1 && SIZE % 2 == 1)
  {
    cout << "\033[1;31m STACK-1 IS FULL\033[0m" << endl;
    exit(0);
  }
  else
  {
    ++top1;
    this->arr[this->top1] = num;
  }
}
void TwoStacksArray::push2(int num)
{
  if (this->top2 == -1 && SIZE % 2 == 0)
    this->top2 = SIZE / 2 - 1;
  if (this->top2 == -1 && SIZE % 2 == 1)
    this->top2 = SIZE / 2;
  if (this->top2 == SIZE)
  {
    cout << "\033[1;31m STACK-2 IS FULL\033[0m" << endl;
    exit(1);
  }
  else
  {
    ++top2;
    this->arr[this->top2] = num;
  }
}
int TwoStacksArray::pop1()
{
  if (this->top1 == -1)
    return -1;
  int popped;
  popped = this->arr[top1];
  --top1;
  return popped;
}
int TwoStacksArray::pop2()
{
  if (this->top2 == SIZE / 2 - 1 && SIZE % 2 == 0 || this->top2 == -1)
    return -1;
  if (this->top2 == SIZE / 2 && SIZE % 2 == 1 || this->top2 == -1)
    return -1;
  int popped;
  popped = this->arr[top2];
  --top2;
  return popped;
}
int main()
{
  TwoStacksArray stackArray_1;
  stackArray_1.push1(2);
  stackArray_1.push1(3);
  stackArray_1.push2(4);
  cout << stackArray_1.pop1() << " " << stackArray_1.pop2() << " " << stackArray_1.pop2() << endl;
}