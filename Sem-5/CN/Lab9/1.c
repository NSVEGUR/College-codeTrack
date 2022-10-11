#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>




int ipAddress[4], subnetMask[4];
int subnets;

void takeInput(){
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
	scanf("%d", &subnets);
}

int checkTwoPower(int n){
	int i = 1;
	int val = pow(2, i);
	while(val <= n){
		if(n == val){
			return i;
		}
		i++;
		val = pow(2, i);
	}
	return -1;
}

int findNetworkBitsFromSubnetMask(int subnetBits){
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

int findClassFromIpAddress(){
	int x = ipAddress[0];
	if(x >= 1 && x <= 126)
		return 1;
	else if(x>=128 && x <= 191)
		return 2;
	else if(x>=192 && x <= 223)
		return 3;
	return -1;
}

int findNetworkBitsFromClass(int class){
	if(class == 1)
		return 8;
	if(class == 2)
		return 16;
	if(class == 3)
		return 24;
	else{
		printf("SubNetting is not possible [not belongs to class A or B or C]\n");
		exit(1);
	}
}

void findSubnetID(unsigned long ip, int octet)
{
    unsigned long int ip_octet[octet];
    for (int i = 0; i < octet - 1; i++)
    {
        ip_octet[i] = ip % 256;
        ip >>= 8;
    }
    for (int i = octet; i >= 0; i--)
    {
        if (i == 0)
            printf("%ld\n", ip_octet[i]);
        else
            printf("%ld.", ip_octet[i]);
    }
}

void printIps(int networkBits, int hostBits, int class){
	int octet = 0;
	if(class==1){
		octet = 3;
	}else if(class==2){
		octet = 2;
	}else{
		octet = 1;
	}
	for(int i = 8; i <= 24; i +=8){
		if(networkBits == i){
			int fixed = i/8;
			for(int j = 0; j <= subnets ; j++){
				for(int k = 0; k < fixed; k++){
					printf("%d.", ipAddress[k]);
				}
				findSubnetID(pow(2, hostBits)*j, octet);
			}
		}
	}
}

int main(){
	int subnetBits, networkBits;
	takeInput();
	subnetBits = checkTwoPower(subnets);
	if(subnetBits == -1){
		printf("SubNetting is not possible[cause its not 2 power]\n");
		exit(1);
	}
	networkBits = findNetworkBitsFromSubnetMask(subnetBits);
	printf("Network Bits: %d, Subnet Bits: %d\n", networkBits, subnetBits);
	int class = findClassFromIpAddress();
	int nBits = findNetworkBitsFromClass(class);
	printf("%d class, %d nBits\n", class,nBits);
	if(nBits != networkBits){
		printf("SubNetting is not possible[network bits calculated from subnet Mask and from network Id based on class varies]\n");
		exit(1);
	}
	int hostBits = 32 - (networkBits+subnetBits);
	if(pow(2, hostBits) < subnets){
		printf("SubNetting is not possible[host bits are not enough]\n");
		exit(1);
	}
	printf("SubNetting is Possible\n");
	printIps(networkBits, hostBits, class);
	return 0;
}