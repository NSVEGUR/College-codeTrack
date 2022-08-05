#include<iostream>
#include<time.h>
#include "functionTemplate.h"
using namespace std;


int main()
{
    int n,choice;
    while(1){
    cout<<"\n-----AVAILABLE CHOICES------"<<endl;
    cout<<"\n1.Integers \n2.Double numbers \n3.Characters \n4.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        //for integers
        case 1:{
        cout<<"\nIntegers"<<endl;
        cout<<"Enter the array size: ";
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
        a[i]=rand()%40;
        }
        cout<<"Array elements: ";
        for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        }
        maxmin(a,n);
        }
        break;
        // for double numbers
        case 2:{
        cout<<"\nDouble numbers"<<endl;
        cout<<"Enter the size of the array: ";
        cin>>n;
        double b[n];
        cout<<"Enter the values of the array: "; 
        for(int i=0;i<n;i++){
        cin>>b[i];
        }
        cout<<"Array elements: ";
        for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
        }
        maxmin(b,n);
        }
        break;
        // for characters
        case 3:{
        cout<<"\nCharacters"<<endl;
        cout<<"Enter the size of the array: ";
        cin>>n;
        char c[n]; // character array
        cout<<"Enter the values of the array: ";
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        cout<<"Array elements: ";
        for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
        }
        maxmin(c,n);
        }
        break;
        case 4:
        cout<<"\n\nEnd of the program"<<endl;
        return 1;
        default:
        cout<<"\nINVALID CHOICE!!!"<<endl;
    }
    }
    return 0;
}
