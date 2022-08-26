//Roll: CS20B1016
//Name: V Nagasai

/*
2)  Write a menu driven program to implement LRC with following options:
3. Send message:You need to take <Data bits> from user. Then, perform LRC and display the
output as <Data bits>+<LRC code bits>
4. Receve message: You need to take input as <Data bits>+<LRC code bits> from user. Then,
perform LRC and display <Data bits> and detection message (Accept/Reject)
*/

#include<stdio.h>

//Taken as ODD PARITY

int main()
{
	int n,a;

	printf("Enter no.of bits in the data(multiple of 4) : ");
	scanf("%d",&n);

	if(n%4 != 0)
	{
		printf("Entered no.of bits is not a multiple of 4\n");
		return 0;
	}

	a = 4;

	int data[n],par[a],data_r[n],par_r[a];

	printf("Enter the data : ");

	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
		
		if(data[i] >= 2)
		{
			printf("Data is incorrect(Data can only be in 0's and 1's)\n");
			return 0;
		}
	}

	int c;

	for(int i=0;i<4;i++)
	{
		c = 0;
		for(int j=0;j<n/4;j++)
		{
			if(data[i+4*j] == 1)
			{
				c++;
			}
		}

		if(c%2 == 0)
		{
			par[i] = 0;
		}

		else
		{
			par[i] = 1;
		}
	}

	for(int i=0;i<4;i++)
	{
		printf("%d ",par[i]);
	}
	printf("\n");

	printf("Enter the data(for the reciever) : ");

	for(int i=0;i<n;i++)
	{
		scanf("%d",&data_r[i]);
		
		if(data_r[i] >= 2)
		{
			printf("Data is incorrect(Data can only be in 0's and 1's)\n");
			return 0;
		}
	}

	int r;

	for(int i=0;i<a;i++)
	{
		r = 0;
		for(int j=0;j<n/4;j++)
		{
			if(data_r[i+4*j] == 1)
			{
				r++;
			}
		}

		if(r%2 == 0)
		{
			par_r[i] = 0;
		}

		else
		{
			par_r[i] = 1;
		}
	}

	for(int i=0;i<4;i++)
	{
		printf("%d ",par_r[i]);
	}
	printf("\n");

	int b=0;

	for(int k=0;k<4;k++)
	{
		if(par[k] == par_r[k])
		{
			b++;
		}
	}

	if(b == a)
	{
		printf("Accept\n");
	}

	else
	{
		printf("Reject\n");
	}

	return 0;
}