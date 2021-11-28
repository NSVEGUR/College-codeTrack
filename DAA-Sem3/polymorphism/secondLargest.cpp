/*
SECOND LARGEST ELEMENT
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> findLargest(int beg, int end, vector<int> arr, int n)
{
    if (beg == end)
    {
        vector<int> compared(n, 0);
        compared[0] = 1;
        compared[1] = arr[beg];
        return compared;
    }

    vector<int> i1 = findLargest(beg, (beg + end) / 2, arr, n);
    vector<int> i2 = findLargest((beg + end) / 2 + 1, end, arr, n);

    if (i1[1] > i2[1])
    {
        int k = i1[0] + 1;
        i1[0] = k;
        i1[k] = i2[1];
        return i1;
    }
    else
    {
        int k = i2[0] + 1;
        i2[0] = k;
        i2[k] = i1[1];
        return i2;
    }
}

void SMAX(int end, vector<int> arr)
{
    vector<int> i1 = findLargest(0, end - 1, arr, end);
    vector<int> i2 = findLargest(2, i1[0] + 2, i1, i1[0]);
    cout << i2[1];
}

int main()
{
    srand(time(0));
    int n, k;
    vector<int> arr;
    cout << "enter the array size:";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        k = rand() % 100;
        arr.push_back(k);
    }
    cout << "Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SMAX(n, arr);

    return 0;
}