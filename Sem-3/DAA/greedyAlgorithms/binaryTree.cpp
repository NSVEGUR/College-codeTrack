#include <iostream>
using namespace std;
#define SIZE 1000

class Array
{
public:
  int keys[SIZE], freq[SIZE], actualSize;
  Array(int actualSize, int keys[], int freq[])
  {
    this->actualSize = actualSize;
    for (int i = 0; i < actualSize; ++i)
    {
      this->keys[i] = keys[i];
      this->freq[i] = freq[i];
    }
  }
  void selectionSort();
  void swap(int *a, int *b);
  int sum(int freq[], int i, int j);
  int optCost(int freq[], int i, int j);
  int optimalSearchTree();
};

void Array::swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Array::selectionSort()
{
  for (int i = 0; i < this->actualSize - 1; ++i)
    for (int j = i + 1; j < this->actualSize; ++j)
      if (this->keys[i] > this->keys[j])
      {
        this->swap(&this->keys[i], &this->keys[j]);
        this->swap(&this->freq[i], &this->freq[j]);
      }
}

int Array::optCost(int freq[], int i, int j)
{
  if (j < i) // no elements in this subarray
    return 0;
  if (j == i) // one element in this subarray
    return freq[i];

  // Get sum of freq[i], freq[i+1], ... freq[j]
  int fsum = this->sum(freq, i, j);

  // Initialize minimum value
  int min = INT_MAX;

  for (int r = i; r <= j; ++r)
  {
    int cost = this->optCost(freq, i, r - 1) +
               this->optCost(freq, r + 1, j);
    if (cost < min)
      min = cost;
  }

  // Return minimum value
  return min + fsum;
}

int Array::optimalSearchTree()
{
  this->selectionSort();
  return this->optCost(this->freq, 0, this->actualSize - 1);
}

int Array::sum(int freq[], int i, int j)
{
  int s = 0;
  for (int k = i; k <= j; k++)
    s += freq[k];
  return s;
}

int main()
{
  int n;
  cout << "\033[1;32m------Program for finding cost of building optimal binary tree using greedy algorithm-----\033[0m" << endl;
  cout << "Enter the size of the array: ";
  cin >> n;
  int keys[n];
  int freq[n];
  cout << "Enter the elements and their frequencies of the array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "\033[1;33mEnter the element - " << i + 1 << " : \033[0m";
    cin >> keys[i];
    cout << "\033[1;33mEnter the frequency of element(can't be negetive) - " << i + 1 << " : \033[0m";
    cin >> freq[i];
  }
  Array arr(n, keys, freq);
  cout << "\033[1;34mCost of Optimal BST is "
       << arr.optimalSearchTree() << "\033[0m" << endl;
  return 0;
}