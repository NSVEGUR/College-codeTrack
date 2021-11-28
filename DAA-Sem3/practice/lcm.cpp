#include <iostream>

using namespace std;

class Lcm
{
public:
  int findLcm(int m, int n)
  {
    int gcd;
    for (int i = 1; i <= m && i <= n; ++i)
    {
      if (m % i == 0 && n % i == 0)
      {
        gcd = i;
      }
    }
    return (m * n) / gcd;
  }
};
int main()
{
  Lcm lcm_1;
  int m, n;
  cout << "-----Program to find the LCM of two given numbers-----" << endl;
  cout << "Enter the value of m: ";
  cin >> m;
  cout << "Enter the value of n: ";
  cin >> n;
  cout << "LCM of " << m << " & " << n << " = " << lcm_1.findLcm(m, n) << endl;
  return 0;
}