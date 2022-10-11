#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calculatePower(int num)
{
    if(num == 1)
    {
        return 0;
    }

    if(num%2 == 1)
    {
        return 1;
    }

    calculatePower(num/2);
}

int main()
{
    char IP[15],x[6][5],m[5];
    int i=0,j=0,k=0,s,a,b,c,d;

    printf("Enter IP Address : ");
    scanf("%s",IP);

    while(IP[i] != '\0')
    {
        if(IP[i] == '.')
        {
            j++;
            i++;
            k = 0;
        }
        x[j][k] = IP[i];
        i++;
        k++;
    }

    a = atoi(x[0]);
    b = atoi(x[1]);
    c = atoi(x[2]);
    d = atoi(x[3]);

    printf("Enter no.of subnets : ");
    scanf("%d",&s);

    int n = calculatePower(s);

    if(n == 1)
    {
        printf("\nInvalid\n");
        return 0;
    }

    if(a >= 0 && a < 127)
    {
        int m = 256/s;
        int t = s,x=0,y=128;
        while(t != 1)
        {
            x = x+y;
            t = t/2;
            y = y/2;
        }
        printf("\nSubnet ID     Subnet mask\n");
        for(i=0;i<s;i++)
        {
            printf("%d.%d.0.0       255.%d.0.0\n",a,m*i,x);
        }
        printf("\n");
    }

    else if(a > 127 && a < 192)
    {
        int m = 256/s;
        int t = s,x=0,y=128;
        while(t != 1)
        {
            x = x+y;
            t = t/2;
            y = y/2;
        }
        printf("\nSubnet ID     Subnet mask\n");
        for(i=0;i<s;i++)
        {
            printf("%d.%d.%d.0       255.255.%d.0\n",a,b,m*i,x);
        }
        printf("\n");
    }

    else if(a >= 192 && a < 224)
    {
        if(s > 128)
        {
            printf("\nInvalid\n");
            return 0;
        }
        int m = 256/s;
        int t = s,x=0,y=128;
        while(t != 1)
        {
            x = x+y;
            t = t/2;
            y = y/2;
        }
        printf("\nSubnet ID     Subnet mask\n");
        for(i=0;i<s;i++)
        {
            printf("%d.%d.%d.%d       255.255.255.%d\n",a,b,c,m*i,x);
        }
        printf("\n");
    }

    else
    {
        printf("\nInvalid\n");
        return 0;
    }

}