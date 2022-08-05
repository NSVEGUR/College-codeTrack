// Here is the top-down approach of
// dynamic programming
#include <iostream>
#include <math.h>
using namespace std;
#define SIZE 1000

class Knapsack
{
public:
	int W, n;
	double wt[SIZE], val[SIZE];

	Knapsack(int W, double wt[], double val[], int n)
	{
		this->n = n;
		this->W = W;
		for (int i = 0; i < n; i++)
		{
			this->wt[i] = wt[i];
			this->val[i] = val[i];
		}
	}

	double knapSack();
};

// Returns the value of maximum profit
double knapSackRec(int W, double wt[], double val[], int i, double **dp)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W)
	{
		// variant added to check for 1/2 weight.
		if (wt[i] / 2 > W)
		{
			dp[i][W] = knapSackRec(W, wt,
														 val, i - 1,
														 dp);
		}
		else
		{
			dp[i][W] = max(val[i] / 2 + knapSackRec(W - wt[i] / 2,
																							wt, val,
																							i - 1, dp),
										 knapSackRec(W, wt, val,
																 i - 1, dp));
		}

		return dp[i][W];
	}
	else
	{
		// Store value in a table before return
		// finding max btw half anf full values of objects.
		dp[i][W] = max(val[i] / 2 + knapSackRec(W - wt[i] / 2,
																						wt, val,
																						i - 1, dp),
									 max(val[i] + knapSackRec(W - wt[i],
																						wt, val,
																						i - 1, dp),
											 knapSackRec(W, wt, val,
																	 i - 1, dp)));

		// Return value of table after storing
		return dp[i][W];
	}
}

double Knapsack::knapSack()
{
	// double podoubleer to declare the
	// table dynamically
	double **dp;
	dp = new double *[n];

	// loop to create the table dynamically
	for (int i = 0; i < n; i++)
		dp[i] = new double[W + 1];

	// loop to initially filled the
	// table with -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
	int W;
	cout << "Enter Total Weight OF Knapsack:";
	cin >> W;
	int n;
	cout << "Enter The Number OF Weights :";
	cin >> n;
	double wt[n], val[n];
	cout << "Enter The Weights and Profits:";
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the weight of object - " << i + 1 << " : ";
		cin >> wt[i];
		cout << "Enter the profit earned by object - " << i + 1 << " : ";
		cin >> val[i];
	}
	Knapsack knapSack(W, wt, val, n);
	cout << "\033[1;34mTotal profit earned: " << knapSack.knapSack() << endl;
	return 0;
}

/*
**OPTIMAL SUBSTRUCTURE :**
In the 0­/1 Knapsack Problem,
1)Let "M" be an optimal subset of all n items with weight
limit W.

1. We want to show that M contains a solution to all subinstances.
– CASE 1: If M does not contain item n, then it is clearly an optimal subset of the first (n -­ 1) items.

– CASE 2: If M does contain item n, then O­-{n} is a solution to
the problem instance that includes the first  (n - 1) items, and a weight limit W - wn(weight of nth item).

So in short,
The maximum value that can be obtained from ‘n’ items is the max of the following two values.

1. Maximum value obtained by n-1 items and W weight (excluding nth item).
2. Value of nth item plus maximum value obtained by n-1 items and W minus the weight of the nth item (including nth item).

If the weight of ‘nth’ item is greater than ‘W’, then the nth item cannot be included .

*/