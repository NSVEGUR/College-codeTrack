#include <iostream>
using namespace std;

class Two_pivot_Quick_sort
{
  int arr[1000];
  int n;

public:
  void swap(int *a, int *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void DualPivotQuickSort(int *arr, int low, int high)
  {
    if (low < high)
    {
      // lp means left pivot, and rp means right pivot.
      int lp, rp;
      rp = partition(arr, low, high, &lp);
      DualPivotQuickSort(arr, low, lp - 1);
      DualPivotQuickSort(arr, lp + 1, rp - 1);
      DualPivotQuickSort(arr, rp + 1, high);
    }
  }

  int partition(int *arr, int low, int high, int *lp)
  {
    if (arr[low] > arr[high])
      swap(&arr[low], &arr[high]);

    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g)
    {

      // if elements are less than the left pivot
      if (arr[k] < p)
      {
        swap(&arr[k], &arr[j]);
        j++;
      }

      // if elements are greater than or equal
      // to the right pivot
      else if (arr[k] >= q)
      {
        while (arr[g] > q && k < g)
          g--;
        swap(&arr[k], &arr[g]);
        g--;
        if (arr[k] < p)
        {
          swap(&arr[k], &arr[j]);
          j++;
        }
      }
      k++;
    }
    j--;
    g++;

    swap(&arr[low], &arr[j]);
    swap(&arr[high], &arr[g]);

    *lp = j; // because we cannot return two elements
    // from a function.

    return g;
  }
};

// Driver code
int main()
{
  Two_pivot_Quick_sort T_1;
  int n, i;
  std::cout << "Enter the size of the array : ";
  cin >> n;
  int arr[n];
  std::cout << "Enter the elements of the array : ";
  for (i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  T_1.DualPivotQuickSort(arr, 0, n);
  int x, y;

  std::cout << "Enter the x : ";
  cin >> x;
  std::cout << "Enter the y : ";
  cin >> y;
  cout << "Sorted array : \n";
  for (i = 0; i < n; i++)
  {
    cout << " " << arr[i];
  }
  cout << endl;
  if (x < y)
  {
    std::cout << " First Window which contains The elements less than x are \n";
    for (i = 0; i < n; i++)
    {
      if (x == arr[0])
      {
        cout << " No elements \n";
        break;
      }
      else if (arr[i] < x)
      {
        std::cout << " " << arr[i];
      }
    }
    std::cout << endl;
    std::cout << " Second Window which contains The elements between x and y are \n";
    for (i = 0; i < n; i++)
    {
      if (x == arr[i] && y == arr[i + 1])
      {
        cout << " No elements \n";
        break;
      }
      if (arr[i] > x && arr[i] < y)
      {
        std::cout << " " << arr[i];
      }
    }
    std::cout << endl;
    std::cout << " Third Window which contains The elements greater than y are \n";
    for (i = 0; i < n; i++)
    {
      if (y == arr[n - 1])
      {
        cout << " No elements \n";
        break;
      }
      else if (arr[i] > y)
      {
        std::cout << " " << arr[i];
      }
    }
    std::cout << endl;
  }
  else if (x > y)
    cout << "x should be less than y \n";

  return 0;
}