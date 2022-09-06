//Roll: CS20B1016
//Name: V Nagasai

/*
2)  Write a menu driven program to implement LRC with following options:
3. Send message:You need to take <Data bits> from user. Then, perform LRC and display the
output as <Data bits>+<LRC code bits>
4. Receve message: You need to take input as <Data bits>+<LRC code bits> from user. Then,
perform LRC and display <Data bits> and detection message (Accept/Reject)
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char msg[33], temp[32], parity[9],check[9];
    for (int i = 0; i < 32; i++)
    {
        msg[i] = '0';
    }
    printf("Enter Message: ");
    scanf("%s", temp);
    int len = strlen(temp);
    for (int i = 0; i < len; i++)
    {
        msg[32 - len + i] = temp[i];
    }
    msg[32] = '\0';
    printf("%s \n", msg);
    int choice;
    printf("For even pairty '1' and odd parity '0': \n");
    scanf("%d", &choice);
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        count = 0;
        for (int j = i; j < 32; j += 8)
        {
            if (msg[j] == '1')
            {
                count++;
            }
        }
        if (choice == 1)
        {
            if (count % 2 == 0)
            {
                parity[i] = '0';
                parity[i + 1] = '\0';
            }
            else
            {
                parity[i] = '1';
                parity[i + 1] = '\0';
            }
        }
        else if (choice == 0)
        {
            if (count % 2 == 0)
            {
                parity[i] = '1';
                parity[i + 1] = '\0';
            }
            else
            {
                parity[i] = '0';
                parity[i + 1] = '\0';
            }
        }
        else
        {
            printf("Invalid!! \n");
        }
    }
    
    printf("%s \n", msg);
    for (int i = 0; i < 32; i++)
    {
        printf("%c", msg[i]);
        if ((i + 1) % 8 == 0)
            printf("\n");
    }
    printf("--------\n");
    printf("%s \n", parity);
    printf("message sent: %s+%s \n",msg,parity);
    printf("enter message received:\n");
    scanf("%s",msg);
    for (int i = 0; i < 8; i++)
    {
        count = 0;
        for (int j = i; j < 32; j += 8)
        {
            if (msg[j] == '1')
            {
                count++;
            }
        }
        if (choice == 1)
        {
            if (count % 2 == 0)
            {
                check[i] = '0';
                check[i + 1] = '\0';
            }
            else
            {
                check[i] = '1';
                check[i + 1] = '\0';
            }
        }
        else if (choice == 0)
        {
            if (count % 2 == 0)
            {
                check[i] = '1';
                check[i + 1] = '\0';
            }
            else
            {
                check[i] = '1';
                check[i + 1] = '\0';
            }
        }
        else
        {
            printf("Invalid!! \n");
        }
    }
    printf("%s \n", msg);
    for (int i = 0; i < 32; i++)
    {
        printf("%c", msg[i]);
        if ((i + 1) % 8 == 0)
            printf("\n");
    }
    printf("--------\n");
    printf("%s \n", check);
    for(int i=0;i<strlen(parity);i++)
    {
        if(parity[i] != check[i])
        {
            printf("Invalid\n");
            return 0;
        }
    }
    printf("valid\n");
    return 0;
}