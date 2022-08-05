#include<iostream>
#include<time.h>
using namespace std;

template <class T>
void maxmin(T arr[], int n){
    T max, min;
    int i;
    if (n % 2 == 0){
        if (arr[0] > arr[1]){
            max = arr[0];
            min = arr[1];
        }
        else{
            min = arr[0];
            max = arr[1];
        }
        i = 2;
    }
    else{
        min = arr[0];
        max = arr[0];
        i = 1;
    }
    while (i < n - 1){
        if (arr[i] > arr[i + 1]){
            max = arr[i] > max ? arr[i] : max;
            min = arr[i + 1] < min ? arr[i + 1] : min;
        }
        else{
            max = arr[i + 1] > max ? arr[i + 1] : max;
            min = arr[i] < min ? arr[i] : min;
        }
        i += 2;
    }
    cout << "\nThe maximum is : " << max << endl;
    cout << "The minimun is : " << min << endl;
}
