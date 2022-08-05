#include <iostream>
using namespace std;
#define SIZE 1000

class Knapsack
{
public:
	int weights[SIZE];
	int profits[SIZE];
	int actualSize;
	int maximumWeight;
	Knapsack(int weights[], int profit, int size, int maximumWeight)
	{
		this->actualSize = size;
		this->maximumWeight = maximumWeight;
		for (int i = 0; i < this->actualSize; i++)
		{
			this->weights[i] = weights[i];
			this->profits[i] = profit;
		}
		this->quickSort(this->weights, 0, this->actualSize - 1);
	}
	int findProfit();
	void quickSort(int arr[], int low, int high);
};

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);		 // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void Knapsack::quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
					 at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int Knapsack::findProfit()
{
	int profitSum = 0;
	int weightSum = 0;
	int i = 0;
	// cout << "Maximum weight: " << this->maximumWeight << endl;
	while (weightSum <= this->maximumWeight && i < this->actualSize)
	{
		if (weightSum + this->weights[i] > this->maximumWeight)
			break;
		weightSum += this->weights[i];
		profitSum += this->profits[i];
		// cout << "profit: " << profitSum << endl;
		++i;
	}
	return profitSum;
}

int main()
{
	cout << "\033[1;32m-----Program for knapsack problem with same profits----\033[0m" << endl;
	int size, profit, maximumWeight;
	cout << "Enter the size of objects to fill knapsack: ";
	cin >> size;
	int weights[size];
	cout << "Enter the maximum weight of the knapsack: ";
	cin >> maximumWeight;
	cout << "Enter the profit earned by each object(profit is same for all): ";
	cin >> profit;
	cout << "Enter the weights of each object: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the weight of object - " << i + 1 << " :";
		cin >> weights[i];
	}
	Knapsack knapsack(weights, profit, size, maximumWeight);
	cout << "\033[1;34mMaximum profit can be earned by knapsack: " << knapsack.findProfit() << endl;
	return 0;
}
