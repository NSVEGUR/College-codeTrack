#include<stdio.h>

int main(){
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", n);
	for(int i = 0; i < n; i++){
		printf("Enter the Arrival Time of P - %d: ", i);
	}
	return 0;
}