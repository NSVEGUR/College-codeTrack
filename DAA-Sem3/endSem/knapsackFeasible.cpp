#include <iostream>
using namespace std;
int w, count = 0;

void Combi(int a[], int reqLen, int s, int currLen, bool check[], int l)
{
	if (currLen > reqLen)
		return;
	else if (currLen == reqLen)
	{
		int sum = 0;
		for (int i = 0; i < l; i++)
			if (check[i] == true)
				sum += a[i];
		if (sum <= w)
		{
			count++;
			for (int i = 0; i < l; i++)
				if (check[i] == true)
					cout << a[i] << " ";
			cout << "\n";
		}

		return;
	}
	if (s == l)
	{
		return;
	}
	check[s] = true;
	Combi(a, reqLen, s + 1, currLen + 1, check, l);
	check[s] = false;
	Combi(a, reqLen, s + 1, currLen, check, l);
}
int main()
{
	int i, n;
	bool check[n];
	cout << "Enter the number of element array have: ";
	cin >> n;
	cout << "\nEnter max weight that the knapsack can hold : ";
	cin >> w;
	int a[n];
	int b[n];
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		cout << "Enter weight of element " << i + 1 << " : ";
		cin >> a[i];
		cout << "Enter profit of element " << i + 1 << " : ";
		cin >> b[i];
		check[i] = false;
	}

	for (i = 1; i <= n; i++)
	{
		// cout<<"\n possible solution with "<<i<<" objects :\n";
		Combi(a, i, 0, 0, check, n);
	}
	cout << " total number of feasible solutions : " << count;
	return 0;
}