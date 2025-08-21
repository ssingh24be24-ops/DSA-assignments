#include <stdio.h>
int main()
{
	int i;int j;int size=3;
	int a[size];

	printf("enter the values");
	
		for(i=0;i<size;i++)
	{       
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i==j)    
			printf("%d",a[i]);
			else
			printf("0");
		}            
		printf("\n");
	}

	return 0; 
	
	}

