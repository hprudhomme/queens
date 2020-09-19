#include<stdio.h>
#include<stdlib.h>
int t[10] = {-1};
int sol = 1;

void printsol()
{
	int i,j;
	char crossboard[10][10];
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			crossboard[i][j]='_';
		}
	}
	for(i=0;i<10;i++)
	{
			crossboard[i][t[i]]='q';
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c ",crossboard[i][j]);
		}
		printf("\n");
	}  
}
int empty(int i)
{
	int j=0;
	while((t[i]!=t[j])&&(abs(t[i]-t[j])!=(i-j))&&j<10)j++;
	return i==j?1:0;
}

void queens(int i)
{
	for(t[i] = 0;t[i]<10;t[i]++)
	{
		if(empty(i))
		{
			if(i==7){
				printsol();
				printf("\n solution %d\n",sol++);
			}
			else
			queens(i+1);
		}
	}
}

	

int main()
{
	queens(0);
	return 0;
}