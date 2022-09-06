//V Nagasai
//cs20b1016

//Q: Implementation of CheckSum 

#include<stdio.h>
#include<stdlib.h>

int max_size = 72, answer[76];
char inputData[9];

void reserveBit(int str[],int max_size){

    int sum[4]={0,0,0,0};

    for(int i = 0;i < max_size;i = i + 4){
			int leastSignificantBit = 0,j = 4;
			while(j--){
					sum[j]= leastSignificantBit + sum[j] + str[i+j];
					if((sum[j]==1)||(sum[j]==0)){
						leastSignificantBit =0;
						continue;
					}
					if(sum[j]==2){
							leastSignificantBit =1;
							sum[j]=0;
					}
					if(sum[j]==3){
							leastSignificantBit =1;
							sum[j]=1;
					}
			} 
			if(leastSignificantBit ==1){
					if(sum[3]==0){
							sum[3]=1;
					}
					else if(sum[2]==0){
							sum[2]=1;
					}
					else if(sum[1]==0){
							sum[1]=1;
					}
					else{
							sum[0]=1;
					}
			}
    }
    for(int i=0;i<4;i++){
        str[max_size-4+i]= abs(1-sum[i]);
    }
}

int checkSum(int str[],int max_size){

    int sum[4]={0,0,0,0};
    
    for(int i=0;i<max_size;i=i+4){
        int leastSignificantBit =0,j=4;
        while(j--){
            sum[j]=leastSignificantBit + sum[j] + str[i+j];
            
            if((sum[j]==1)||(sum[j]==0)){
              leastSignificantBit =0;
              continue;
            }
            if(sum[j]==2){
                leastSignificantBit =1;
                sum[j]=0;
            }
            if(sum[j]==3){
                leastSignificantBit =1;
                sum[j]=1;
            }
           
        } 
        if(leastSignificantBit ==1){
            if(sum[3]==0){
                sum[3]=1;
            }
            else if(sum[2]==0){
                sum[2]=1;
            }
            else if(sum[1]==0){
                sum[1]=1;
            }
            else{
                sum[0]=1;
            }
        }

    }
    
    for(int i=0;i<4;i++){
        str[max_size-4+i]=abs(sum[i]-1);
        if(!sum[i]){
            return 0;
        }
    }
    return 1;
}

void Sender(){
	for(int i=0;i< max_size+4;i++){
			answer[i]=0;
	}
	int j=0,r=0;
	for(int i=0;i< max_size;i+=8){
		char bit = inputData[j];
		int value = bit;
		int ch[8];
		for(int l=0;l<8;l++){
			ch[l]=0;
		}
		int k=0;
		while(value>0){
			int rem=value%2;
			ch[k]=rem;
			value/=2;
			k++;
		}
		for(int m=7;m>=0;m--){
			answer[r]=ch[m];
			r++;
		}
		j++;
	}
	reserveBit(answer, max_size+4); 
	printf("Input Data in binary : \n");
	for(int i=0;i< max_size;i++){
			printf("\033[1;34m%d",answer[i]);
	}   
	printf("\n\033[0m");
	printf("Check sum bits for the input data[At Sender]:  ");
	for(int i= max_size;i< max_size+4;i++){
		printf("\033[1;36m%d",answer[i]);
	}
	printf("\033[0m");
}

void Receiver(){
	int flag = checkSum(answer, max_size+4);
	if(flag ==1){
			printf("\n---Received Data is Valid.---\n");
			for(int i=0;i< max_size;i++){
					printf("\033[1;34m%d",answer[i]);
			}
			printf("\n\033[0m");
			printf("Check sum bits for the received data[At Receiver]:  ");
			for(int i= max_size;i< max_size+4;i++){
					printf("\033[36m%d",answer[i]);
			}
			printf("\n\033[0m");
	}
	else{
			printf("\n\033[1;31m---Received Data is Invalid.\033[0m\n");
	}
}

int main(){
	printf("Enter your Roll No : \033[1;33m");
	for(int i=0;i<9;i++){
			scanf("%c",&inputData[i]);
	}
	printf("\033[0m");
	Sender();
	Receiver();
	return 0;
}