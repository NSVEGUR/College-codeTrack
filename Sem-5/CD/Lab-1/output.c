#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(int argc, char **argv)
{
FILE * fpin, * fpout;
char buf[2000], *token;
int lines, i = 1, j, k;
double array[2000][3];
if(argc != 3) {
fprintf(stderr,"Usage: .a.out <InputFile> <OutputFile>\n");
return 0;
}
fpin = fopen(argv[1], "r");
fpout = fopen(argv[2], "w");
if(fpin == NULL) {
fprintf(stderr, "Error: Invalid Input Filename\n");
return 0;
}
fgets(buf, 2000, fpin);
token = strtok(buf, " \t");
lines = atoi(token);
printf("%d\n", lines);
while(fgets(buf, 2000, fpin) != NULL) {
token = strtok(buf, " \t");
token = strtok(NULL, " \t");
j=1;
while(token != NULL) {
array[i][j] = atof(token);
 token = strtok(NULL, " \t");
j++;
}
i++;
}
 printf("numer of nodes in the given test file = %d\n", lines);
double temp;
int dist[lines+1][lines+1];
 for(i = 1; i <= lines; i++)
for(j = 1; j <= lines; j++) {
temp = 0;
for(k = 1; k <= 2; k++)
temp += (array[i][k] - array[j][k]) * (array[i][k] - array[j][k]);
dist[i][j] = (int)(sqrt(temp)+0.5); }
fprintf(fpout, "%d\n", lines);
for(i = 1; i <= lines; i++) {
for(j = 1; j <= lines; j++)
fprintf(fpout, "%d ", dist[i][j]);
fprintf(fpout, "\n");
} fclose(fpin);
fclose(fpout);
return 0;
}