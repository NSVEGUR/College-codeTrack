// Dynamic Programming code for Optimal Binary Search

#include <iostream>
using namespace std;

int sum(int freq[], int i, int j)
{
  int s = 0;
  for (int k = i; k <= j; k++)
    s += freq[k];
  return s;
}

int optimalSearchTree(int keys[], int freq[], int n)
{

  int cost[n][n];

  for (int i = 0; i < n; i++)
  {
    cost[i][i] = freq[i];
  }

  for (int x = 2; x <= n; x++)
  {
    for (int i = 0; i <= n - x + 1; i++)
    {
      int j = i + x - 1;

      cost[i][j] = 100000000;

      for (int r = i; r <= j; r++)
      {
        int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
        if (c < cost[i][j])
          cost[i][j] = c;
      }
    }
  }
  return cost[0][n - 1];
}

int main()
{
  int n;
  cout << "Enter the total number of keys: ";
  cin >> n;
  int k[n];
  cout << "Enter the keys: ";
  for (int i = 0; i < n; i++)
  {
    cin >> k[i];
  }
  cout << endl;
  int f[n];
  cout << "Enter their frequencies: ";
  for (int i = 0; i < n; i++)
  {
    cin >> f[i];
  }
  cout << "Cost of Optimal BST is " << optimalSearchTree(k, f, n) << endl;
  return 0;
}
