
//Name: V Nagasai
//Roll: CS20B1016
//Q: Value numbering

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 63

int t_count = 1;
typedef struct T{
	int value;
	struct T* next;
}T;

T* top_T = NULL;

void pushT(int value){
	// printf("value pushed: %d\n", value);
	T* temp = malloc(sizeof(T));
	temp->value = value;
	temp->next = top_T;
	top_T = temp;
}

int popT(){
	if(top_T == NULL){
		printf("Stack is empty!\n");
		exit(1);
	}
	int value = top_T->value;
	// printf("value popped: %d\n", value);
	top_T = top_T->next;
	return value;
}


void mixed(char *expression, int i){
	int len = strlen(expression);
	int end = 0;
	if(i+4 == len){
		end = 1;
	}
	if(!end){
		if(top_T == NULL){
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("T%d = %c %c T%d\n", t_count, expression[i-1] , expression[i], t_count - 1);
		}else{
			int value = popT();
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("T%d = T%d %c T%d\n", t_count, value , expression[i], t_count - 1);
		}
	}else{
		if(top_T == NULL){
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("out = %c %c T%d\n", expression[i-1] , expression[i], t_count - 1);
		}else{
			int value = popT();
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("out = T%d %c T%d\n",  value , expression[i], t_count - 1);
		}
	}
	pushT(t_count);
	t_count+=1;
}

void div_mul(char *expression, int i){
	int len = strlen(expression);
	int end = 0;
	if(i+2 == len){
		end = 1;
	}
	if(!end){
		if(top_T == NULL){
		printf("T%d = %c %c %c\n", t_count, expression[i-1], expression[i], expression[i+1]);
		}else{
			int value = popT();
			printf("T%d = T%d %c %c\n", t_count, value, expression[i], expression[i+1]);
		}
	}else{
		if(top_T == NULL){
		printf("out = %c %c %c\n", expression[i-1], expression[i], expression[i+1]);
		}else{
			int value = popT();
			printf("out = T%d %c %c\n", value, expression[i], expression[i+1]);
		}
	}
	pushT(t_count);
	t_count+=1;
}

void add_sub(char *expression, int i){
	int len = strlen(expression);
	int end = 0;
	if(i+2 == len){
		end = 1;
	}
	if(!end){
		if(top_T == NULL){
		printf("T%d = %c %c %c\n", t_count, expression[i-1], expression[i], expression[i+1]);
		}else{
			int value = popT();
			printf("T%d = T%d %c %c\n", t_count, value, expression[i], expression[i+1]);
		}
	}else{
		if(top_T == NULL){
		printf("out = %c %c %c\n", expression[i-1], expression[i], expression[i+1]);
		}else{
			int value = popT();
			printf("out = T%d %c %c\n", value, expression[i], expression[i+1]);
		}
	}
	pushT(t_count);
	t_count+=1;
}

int main()
{
	char expression[MAX_SIZE];
	printf("\nEnter the expression with arithmetic operator[without assignment]: ");
	scanf("%s", expression);
	int len = strlen(expression);
	for(int i = 0; i < len; i++){
		if(expression[i] == '+' || expression[i] == '-'){
			if(expression[i+2] == '*' || expression[i+2] == '/'){
				mixed(expression, i);
				i+=2;
			}else{
				add_sub(expression, i);
			}
		}else if(expression[i] == '*' || expression[i] == '/'){
			div_mul(expression, i);
		}
	}
	return 0;
}