#include <iostream>

using namespace std;

class Gcd
{
public:
  int findGcd(int m, int n)
  {
    int gcd;
    for (int i = 1; i <= m && i <= n; ++i)
    {
      if (m % i == 0 && n % i == 0)
      {
        gcd = i;
      }
    }
    return gcd;
  }
};
int main()
{
  Gcd gcd_1;
  int m, n;
  cout << "-----Program to find the gcd of two given numbers-----" << endl;
  cout << "Enter the value of m: ";
  cin >> m;
  cout << "Enter the value of n: ";
  cin >> n;
  cout << "GCD of " << m << " & " << n << " = " << gcd_1.findGcd(m, n) << endl;
  return 0;
}