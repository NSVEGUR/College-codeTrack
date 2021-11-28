// Dynamic Programming for Matrix Chain Multiplication

#include <iostream>
using namespace std;

int MatrixChainOrder(int p[], int n)
{
  int m[n][n];
  int i, j, k, x, q;

  for (i = 1; i < n; i++)
  {
    m[i][i] = 0;
  }

  for (x = 2; x < n; x++)
  {
    for (i = 1; i < n - x + 1; i++)
    {
      j = i + x - 1;
      m[i][j] = 100000000;
      for (k = i; k <= j - 1; k++)
      {
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
          m[i][j] = q;
      }
    }
  }
  return m[1][n - 1];
}

int main()
{
  int n;
  cout << "Enter the total number of matrices: ";
  cin >> n;
  int a[n + 1];
  cout << "If there are 'n' matrices, then enter 'n+1' dimensions: ";
  for (int i = 0; i < n + 1; i++)
  {
    cin >> a[i];
  }
  cout << "Minimum number of multiplications is " << MatrixChainOrder(a, n + 1) << endl;
  return 0;
}
