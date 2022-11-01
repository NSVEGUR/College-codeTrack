//Name: V Nagasai
//Roll: CS20B1016
//Q: Routing table implementation using Distance vector algorithm

#include<stdio.h>
#define MAX_SIZE 31

typedef struct
{
    unsigned distance[MAX_SIZE];
    unsigned fromNode[MAX_SIZE];
}Node;
Node routing_table[MAX_SIZE];

void inputAdjacencyMatrix(int n, int adj_matrix[][n]){
	printf("\nEnter the adjacency list [ a -> b node cost for all routers (2d matrix) ] \n");
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
					scanf("%d",&adj_matrix[i][j]);
					adj_matrix[i][i]=0;
					routing_table[i].distance[j]=adj_matrix[i][j];
					routing_table[i].fromNode[j]=j;
			}
	}
}

void printAdjacencyMatrix(int n, int adj_matrix[][n]){
	printf("\n-----Initial Routing Table-----\n\n");
	for(int i = 0; i < n; i++){
		printf("\n Router - %d distances to all other routers -- \n\n", i+1);
		for(int j = 0; j < n; j++){
			printf("\t\033[0;32mTo router %d distance is %d \n", j+1, adj_matrix[i][j]);
		}
		printf("\n\033[0m");
	}
	printf("-------------------------------------\n\n");
}

void updateRoutingTable(int n, int adj_matrix[][n]){
	int count = 0;
	do
	{
			count = 0;
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<n;j++)
				{
					for(int k = 0;k<n;k++)
					{
						if(routing_table[i].distance[j]>adj_matrix[i][k]+routing_table[k].distance[j])
						{
								routing_table[i].distance[j]=routing_table[i].distance[k]+routing_table[k].distance[j];
								routing_table[i].fromNode[j]=k;
								count++;
						}
					}
				}
			}
	}while(count!=0);
}

void printRoutingTable(int n){
	printf("\n-----Updated Routing Table-----\n\n");
	for(int i=0;i<n;i++)
		{
				printf("\n Router - %d distances to all other routers -- \n\n", i+1);
				for(int j=0;j<n;j++)
				{
						printf("\t\033[0;34mTo router %d via %d distance is %d \n",j+1,routing_table[i].fromNode[j]+1,routing_table[i].distance[j]);
				}
				printf("\n\033[0m");
		}
	printf("-------------------------------------\n\n");
}

int main()
{
	int adj_matrix[MAX_SIZE][MAX_SIZE];
	int n;
	printf("\nEnter the total routers count : ");
	scanf("%d",&n);
	inputAdjacencyMatrix(n, adj_matrix);
	printAdjacencyMatrix(n, adj_matrix);
	updateRoutingTable(n, adj_matrix);
	printRoutingTable(n);
	return 0;
}