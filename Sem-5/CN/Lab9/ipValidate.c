#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void takeInput(int *ipAddress, int *subnetMask, int *subnets){
	printf("#### Network IP address[a.b.c.d] ####\n");
	printf("Enter a: ");
	scanf("%d", &ipAddress[0]);
	printf("Enter b: ");
	scanf("%d", &ipAddress[1]);
	printf("Enter c: ");
	scanf("%d", &ipAddress[2]);
	printf("Enter d: ");
	scanf("%d", &ipAddress[3]);
	printf("####  Subnet Mask address[a.b.c.d] ####\n");
	printf("Enter a: ");
	scanf("%d", &subnetMask[0]);
	printf("Enter b: ");
	scanf("%d", &subnetMask[1]);
	printf("Enter c: ");
	scanf("%d", &subnetMask[2]);
	printf("Enter d: ");
	scanf("%d", &subnetMask[3]);
	printf("Enter the number of subnets: ");
	scanf("%d", subnets);
}

int findSubnetBits(int subnets){
	int i = 1;
	int val = pow(2, i);
	while(val <= subnets){
		if(subnets == val){
			return i;
		}
		i++;
		val = pow(2, i);
	}
	return -1;
}

int findNetworkBitsFromSubnetMask(int subnetMask[], int subnetBits){
	int count = 0;
	for(int i=0; i<4; i++){
		int x = subnetMask[i];
		int arr[8] = {0};
		int j = 0;
		while(x>0){
			arr[j] = x%2;
			j++;
			x = x/2;
		}
		int k, flag = 0;
		for(k = 7; k >= 0; k--){
			if(arr[k] == 1)
				count++;
			else{
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}
	return count - subnetBits;
}

int findClassFromIpAddress(int ipAddress[]){
	int x = ipAddress[0];
	if(x >= 1 && x <= 126)
		return 3;
	else if(x>=128 && x <= 191)
		return 2;
	else if(x>=192 && x <= 223)
		return 1;
	return -1;
}

int findNetworkBitsFromClass(int class){
	if(class == 3)
		return 8;
	if(class == 2)
		return 16;
	if(class == 1)
		return 24;
	else{
		printf("SubNetting is not possible [not belongs to class A or B or C]\n");
		exit(1);
	}
}

int main(){
	int ipAddress[4], subnetMask[4], subnets;
	takeInput(ipAddress, subnetMask, &subnets);
	int subnetBits, networkBits_subnetMask;
	subnetBits = findSubnetBits(subnets);
	if(subnetBits == -1){
		printf("Invalid [Cause No of subnets is not 2 powered]\n");
		exit(1);
	}
	networkBits_subnetMask = findNetworkBitsFromSubnetMask(subnetMask, subnetBits);
	int class = findClassFromIpAddress(ipAddress);
	int networkBits_class = findNetworkBitsFromClass(class);
	if(networkBits_class != networkBits_subnetMask){
		printf("Invalid [network bits calculated from subnet Mask and from network Id based on class varies.]\n");
		exit(1);
	}
	int hostBits = 32 - (networkBits_subnetMask+subnetBits);
	return 0;
}