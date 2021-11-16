#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	FILE *fp;
	int ch;
	fp = fopen("team.txt","w");
	scanf("%d",&ch);
	while(ch!=EOF)
	{
		puts("Enter");
		scanf("%d",&ch);
		fprintf(fp, "%d", ch);
	}
	fclose(fp);
	return 0;
}

