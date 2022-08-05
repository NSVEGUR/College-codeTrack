#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Binary
{
public:
  string num_1, num_2;
  int n1, n2;
  string result_binary;
  int result_int;
  string convertToBinary(int num);
  string addBinary(string a, string b);
  string multiplyBinary(string a, string b);
  int convertToInt(string str);
};

string Binary::convertToBinary(int num)
{
  string str = "";
  num = abs(num);
  while (num != 0)
  {
    str += to_string(num % 2);
    num = num / 2;
  }
  reverse(str.begin(), str.end());
  return str;
}

string Binary::addBinary(string a, string b)
{
  string result = ""; // Initialize result
  int s = 0;          // Initialize digit sum

  // Traverse both strings starting from last
  // characters
  int i = a.size() - 1, j = b.size() - 1;
  while (i >= 0 || j >= 0 || s == 1)
  {
    // Comput sum of last digits and carry
    s += ((i >= 0) ? a[i] - '0' : 0);
    s += ((j >= 0) ? b[j] - '0' : 0);

    // If current digit sum is 1 or 3, add 1 to result
    result = char(s % 2 + '0') + result;

    // Compute carry
    s /= 2;

    // Move to next digits
    i--;
    j--;
  }
  return result;
}

string Binary::multiplyBinary(string a, string b)
{
  string result_a = "", result_b = "";
  int i = a.size() - 1, j = b.size() - 1;
  int temp = i;
  for (; i >= 0; --i)
  {
    if (result_a == "")
    {
      for (int k = j; k >= 0; --k)
      {
        char x = a[i];
        char y = b[k];
        result_a += to_string((atoi(&x) % 10) * (atoi(&y) % 10));
      }
    }
    else
    {
      result_b = "";
      // cout << "a = " << a << endl;
      // cout << "b = " << b << endl;
      for (int k = j; k >= 0; --k)
      {
        char x = a[i];
        char y = b[k];
        // cout << "a[" << i << "] = " << a[i] << endl;
        // cout << "b[" << k << "] = " << b[k] << endl;
        result_b += to_string((atoi(&x) % 10) * (atoi(&y) % 10));
        // cout << "result b: " << result_b << endl;
      }
      // cout << "temp = " << temp << " and i = " << i << endl;
      for (int l = 0; l < temp - i; l++)
        result_b += "0";
      cout << "result a: " << result_a << endl;
      cout << "result b: " << result_b << endl;
      result_a = this->addBinary(result_a, result_b);
      cout << "final result a: " << result_a << endl;
    }
  }
  // cout << "result a: " << result_a << endl;

  return result_a;
}

int Binary::convertToInt(string str)
{
  int result = 0;
  int i = str.size() - 1;
  int temp = i;
  while (i >= 0)
  {
    char x = str[i];
    // cout << "result = " << result << endl;
    // cout << "stoi(&x) % 10 = " << stoi(&x) % 10 << endl;
    result += (stoi(&x) % 10) * pow(2, temp - i);
    --i;
  }
  return result;
}

int main()
{
  Binary num;
  cout << "-----Program to process binary multiplication through bits-----" << endl;
  cout << "Enter the first number: ";
  cin >> num.n1;
  cout << "Enter the second number: ";
  cin >> num.n2;
  num.num_1 = num.convertToBinary(num.n1);
  num.num_2 = num.convertToBinary(num.n2);
  cout << "binary -1: " << num.num_1 << endl;
  cout << "binary -2: " << num.num_2 << endl;
  num.result_binary = num.multiplyBinary(num.num_1, num.num_2);
  cout << "result-binary: " << num.result_binary << endl;
  num.result_int = num.convertToInt(num.result_binary);
  cout << "Multiplication of both numbers is: " << num.result_int << endl;
  return 0;
}