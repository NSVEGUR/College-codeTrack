//NAME:- V Nagasai
//ROLL NO:-CS20B1016
//Q:-GIVEN A CFG, DO RECURSIVE DESCENT PARSING 

#include<stdio.h>

char inputStr[1000];
int i=0;
void fs();
void fa();
void fb();

void fb(){
    switch(inputStr[i]){
        case 'b':
        {
            i++;
            fa();
            break;
        }
        case 'a':
        {
            fs();
            break;
        }
        case 'c':
        {
            fs();
            break;
        }
        default:
            break;
    }
}

void fa(){
    switch (inputStr[i]){
        case 'b':
        {
            i++;
            if(inputStr[i]=='a'){
                i++;
            }
            else{
                printf("\nRejected\n");
            }
            break;
        }
        case 'a':
        {
            fs();
            fb();
            break;
        }
        case 'c':
        {
            fs();
            fb();
            break;
        }
        default:
            break;
    }
}

void fs(){
    switch (inputStr[i])
    {
    case 'a':
    {
        i++;
        fa();
        fs();
        break;
    }
    case 'c':
    {
        i++;
        break;
    }
    default:
        break;
    }
}

int main(){
    int n;
    printf("Enter the size of the input string: ");
    scanf("%d",&n);
    printf("Enter the String: ");
    for(int j=0;j<n;j++){
        scanf(" %c",&inputStr[j]);
    }

    fs();

    if(inputStr[i]=='$'){
        printf("Accepted.\n");
    }
    else{
        printf("Rejected.\n");
    }

}