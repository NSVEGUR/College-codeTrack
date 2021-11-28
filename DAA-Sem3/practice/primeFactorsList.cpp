#include <iostream>
#include <cmath>
using namespace std;

#define SIZE 1000

class primeClass
{
public:
  int actualSize = 0, arr[SIZE];
  bool checkPrime(int num);
  void checkPrimeFactors(int num);
  void listPrimeFactors();
};

bool primeClass::checkPrime(int num)
{
  int n, flag = 0;
  for (n = 2; n <= sqrt(num); ++n)
  {
    if (num % n == 0)
    {
      flag = 1;
      break;
    }
    else
      continue;
  }
  if (flag)
    return false;
  else
    return true;
}

void primeClass::checkPrimeFactors(int num)
{
  int n;
  for (n = 2; n <= num; ++n)
  {
    if (this->checkPrime(n) && num % n == 0)
    {
      this->arr[this->actualSize] = n;
      this->actualSize++;
    }
    else
      continue;
  }
}

void primeClass::listPrimeFactors()
{
  cout << "Prime factors of the given number are: " << endl;
  for (int i = 0; i < this->actualSize; ++i)
  {
    cout << this->arr[i] << endl;
  }
}
int main()
{
  primeClass primeClass_1;
  int num;

  cout << "-----Program to list the prime factors of the given number-----" << endl;
  cout << "Enter a number: " << endl;
  cin >> num;
  primeClass_1.checkPrimeFactors(num);
  primeClass_1.listPrimeFactors();
  return 0;
}