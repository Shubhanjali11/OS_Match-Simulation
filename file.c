#include<stdio.h>
#include "header.h"
typedef struct match
{
	int team;
	int W;
	int D;
	int L;
	int GS;
	int Points;
}match;
 int main()
 {
 	FILE *fPointer;
 	int number1,number2;
 	fPointer = fopen("team.txt","r");
 	int count =0, i=1,j=2;
 	fscanf(fPointer,"%d",&count);
 	match ar[count], temp;
 	//pid_t id[count];
 	for(int i = 0;i<count;i++)
 	{
 		ar[i].team = i+1;
 		//id[i] = fork();
 		//printf("%d\n",id[i]);
 	}
 	for(int i=0;i<count;i++)
 	{
 	 ar[i].W=0; 
 	 ar[i].D=0;
 	 ar[i].L=0; 
 	 ar[i].GS=0;
 	 ar[i].Points=0;
 	}
 	fscanf(fPointer,"%d",&i);
 	fscanf(fPointer,"%d",&j);
 	//printf("%d\n",i);
 	while(!feof(fPointer))
 	{
 		printf("Starting match: Team %d vs Team %d\n",i,j);
 		printf(" Match ended: Team %d vs Team %d\t" ,i,j);
 		number1 = rand()%10;
 		number1 = ceil(number1/2);
 		number2 = rand()%10;
 		number2 = ceil(number2/2);
 		printf("Result: %d - %d\n", number1,number2);
 		if(number1>number2)
 		{
 			ar[i-1].W+=1;
 			ar[i-1].GS+=number1;
 			ar[j-1].L+=1;
 			ar[j-1].GS+=number2;
 			ar[i-1].Points+=3;
 		}
 		else if(number2>number1)
 		{
 			ar[i-1].L+=1;
 			ar[i-1].GS+=number1;
 			ar[j-1].W+=1;
 			ar[j-1].GS+=number2;
 			ar[j-1].Points+=3;
 		}
 		else
 		{
 			ar[i-1].D+=1;
 			ar[j-1].D+=1;
 			ar[i-1].GS+=number1;
 			ar[j-1].GS+=number2;
 		}
 		fscanf(fPointer,"%d",&i);
 		fscanf(fPointer,"%d",&j); 
 	}
 	printf("Team\tW\tD\tL\tGS\tPoints\n");
 	for(int i=0;i<count;i++)
 	{
 		for(int j=0;j<(count-1-i);j++)
 		{
 			if(ar[j].Points < ar[j+1].Points)
 			{
 				temp = ar[j];
 				ar[j] = ar[j+1];
 				ar[j+1] = temp;
 			}
 		}
 	}
 	
 	for(int i=0;i<count;i++)
 	{
 		printf("%d\t%d\t%d\t%d\t%d\t%d\n", ar[i].team, ar[i].W, ar[i].D, ar[i].L, ar[i].GS, ar[i].Points);
 	}
 	fclose(fPointer);
 	return 0;
 }
