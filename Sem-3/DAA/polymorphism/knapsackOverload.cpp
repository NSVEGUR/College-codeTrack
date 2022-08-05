#include<iostream>
using namespace std;

class functionOverloading{

public:
int n;

int max(int a, int b){
    return (a > b) ? a : b;
}

double max(double a, double b){
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[]){
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++){
        for (w = 0; w <= W; w++){
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else{
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

double knapsack(double W, double wt[], double val[]){
        int i, w;
        int iwt;
        int x=W/1.0;
        double K[n + 1][x + 1];
        for (i = 0; i <= n; i++){
            for (w = 0; w <= x; w++){
                if (i == 0 || w == 0){
                    K[i][w] = 0;
                }
                else if (wt[i - 1] <= w) {
                	iwt=wt[i-1];
                    K[i][w] = max(val[i - 1] + K[i - 1][w - iwt], K[i - 1][w]);
                }
                else{
                    K[i][w] = K[i - 1][w];
                }
            }
        }
        return K[n][x];
    }

int knapsack(int W,int w[]){

    int items=0,Weight=0;
    
for(int i=1 ; i<n ; i++){
    int j;
    int temp = w[i];
    for(j=i-1 ; j>=0 && w[j]>temp ; j--){
        w[j+1]=w[j];
    }
    w[j+1]=temp;
}

for(int i=0;i<n;i++){
    Weight+=w[i];
    if(Weight<=W){
        items+=1; 
    }
    else{
      break; 
    }
}
    return items;
}

float knapsack(int W,int w[],int p[],bool flag){
    
    float r[n],total=0;
    

    for(int i=0;i<n;i++){
        r[i]=(p[i]*1.0)/(w[i]*1.0);
    }

    for(int i=1;i<n;i++){
        int j;
        double temp=r[i];
        int temp1=w[i],temp2=p[i];

        for(j=i-1;j>=0 && r[j]>temp;j--){
            r[j+1]=r[j];
            w[j+1]=w[j];
            p[j+1]=p[j];
        }
        
        r[j+1]=temp;
        w[j+1]=temp1;
        p[j+1]=temp;
    }

    for(int i=n-1;i>=0;i--){
        if(W>0){
            if(w[i]<W){
                total=total+p[i];
                W=W-w[i];
            }
            else{
                total=total+(W*1.0/w[i])*1.0*p[i];
                return total;
            }
        }
        else{
            break;
        }
    }
    return total;
}


};

int main(){
    functionOverloading F;

    int n,W1;
    double W2;

    cout<<"\nInteger Data"<<endl;

    cout<<"Enter the capacity of the bag: ";
    cin>>W1;

    cout<<"\nEnter the number of items: ";
    cin>>n;
    F.n=n;

    int IW[n],IP[n];
    double DW[n],DP[n];

    cout<<"\nEnter the weight of "<<n<<" int items : ";
    for(int i=0;i<n;i++){
        cin>>IW[i];
    }
 
    cout<<"\nEnter the profit of respective weights : ";
    for(int i=0;i<n;i++){
        cin>>IP[i];
    }


    cout<<"\nDouble Data"<<endl;

    cout<<"Enter the capacity of the bag: ";
    cin>>W2;

    cout<<"\nEnter the weight of "<<n<<" int items : ";
    for(int i=0;i<n;i++){
        cin>>DW[i];
    }

    cout<<"\nEnter the profit of respective weights : ";
    for(int i=0;i<n;i++){
        cin>>DP[i];
    }

    cout<<"\nTotal profit in 0-1 Knapsack of integers: "<<F.knapsack(W1,IW,IP)<<endl;
    cout<<"\nTotal profit in 0-1 Knapsack of double: "<<F.knapsack(W2,DW,DP)<<endl;
    cout<<"\nMaximum items in bag- Knapsack Variant to maximise items: "<<F.knapsack(W1,IW)<<endl;
    cout<<"\nTotal profit in fractional Knapsack using greedy: "<<F.knapsack(W1,IW,IP,1)<<endl;

    return 0;
}