#include <bits/stdc++.h>
using namespace std;

vector<int> denominations = {1, 2, 5, 10, 50, 100, 200, 500, 2000};

int MinCoins(int value)
{

    vector<int> dp(value + 1, value + 1);

    // Setting the first element to 0
    dp[0] = 0;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < denominations.size(); j++)
        {
            if (denominations[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - denominations[j]] + 1);
            }
        }
    }

    return dp[value] == (value + 1) ? -1 : dp[value];
}

int main()
{
    int amount;
    cout << "Enter the amount:";
    cin >> amount;
    int minimum_coins = MinCoins(amount);

    cout << minimum_coins << endl;

    return 0;
}