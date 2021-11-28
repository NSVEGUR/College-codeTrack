// A dynamic programming based solution for 0-1 Knapsack problem
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main()
{
	int w, n;
	cout << "Enter the capacity of the bag(maximum weight): ";
	cin >> w;
	cout << "Enter the total number of values(objects): ";
	cin >> n;
	int a[n], b[n];
	cout << "Enter the weights(Must be in increasing order): ";
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the weight of object - " << i + 1 << " : ";
		cin >> b[i];
	}
	cout << "Enter the values(profits gained by each): ";
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the profit gained by object - " << i + 1 << " : ";
		cin >> a[i];
	}
	cout << "Maximum profit can be gained by the bag = " << knapSack(w, b, a, n) << endl;
	return 0;
}