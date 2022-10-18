#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


int main(){
	int ipaddress[4], hBits, n;

	printf("\nEnter IP address with space: ");
	for(int i=0;i<4;i++){
		scanf("%d",&ipaddress[i]);
	}

	int className=ipaddress[0];

	if(className>=0 && className<=127){
		hBits=24;
		printf("Class A IP address\n");
	}
	else if(className>=128 && className<=191){
		hBits=16;
		printf("Class B IP address\n");
	}
	else if(className>=192 && className<=223){
		hBits=8;
		printf("Class C IP address\n");
	}
	else{
		printf("IP address is out of range\n");
		return 0;
	}

	printf("Enter number of Subnets: ");
	scanf("%d",&n);

	int subnetMask[4];
	printf("Enter subnet mask address with space: ");
	for(int i=0;i<4;i++){
		scanf("%d",&subnetMask[i]);
	}


	int bits = ceil(log(n)/log(2));
	printf("Bits needed for Subnet ID: %d\n",bits);

	int subnetMaskSum=0;
	int subnetMaskSumArray[4];

	for(int i=0;i<4;i++){
		subnetMaskSumArray[i]=0;
	}

	subnetMaskSumArray[0]=255;
	int temp = 1;

	if(hBits==16){
		temp=2;
		subnetMaskSumArray[1]=255;
	}
	else if(hBits==8){
		temp=3;
		subnetMaskSumArray[1]=255;
		subnetMaskSumArray[2]=255;
	}

	int octetBits=0;

	for(int i=hBits;i>hBits-bits;i--){
		if(i>8 && i<=16){
			octetBits=i-9;   
		}else if(i>16){
			octetBits=i-17;
		}else{
			octetBits=i-1;
		}
		subnetMaskSum+=(int)pow(2,octetBits);
		if(i%8==1 || i==hBits-bits+1){
			subnetMaskSumArray[temp]=subnetMaskSum;
			subnetMaskSum=0;
			temp++;
		}
	}

	printf("Actual Subnet Mask Address:");
	for(int i=0;i<4;i++){
		printf("%d.",subnetMaskSumArray[i]);
	}

	for(int i=0;i<4;i++){
		if(subnetMask[i]!=subnetMaskSumArray[i]){
			printf("Subnets Impossible\n");
			return 0;
		}
	}

	printf("Subnets Possible\n");

	int subnetId[4];

	for(int i=0;i<4;i++){
		subnetId[i]=subnetMaskSumArray[i]&ipaddress[i];
	}

	printf("IP belongs to the Subnet ID: ");
	for(int i=0;i<4;i++){
		printf("%d.",subnetId[i]);
	}
	printf("\n");
 	return 0;
}