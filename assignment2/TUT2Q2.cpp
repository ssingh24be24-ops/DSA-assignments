#include <stdio.h>
#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
	int i;int j;int size=5;
	int a[size];

	printf("enter the values");
	
		for(i=0;i<size;i++)
	{       
		scanf("%d",&a[i]);
	}
	
	printf("before swaping\n");
		for(i=0;i<size;i++)
		{
			printf("%d,",a[i]);
		}
		printf("\n");
	for(j=0;j<size-1;j++)
	{	
    for(i=0;i<size-1;i++)
	{
		if(a[i]>a[i+1])
		swap(&a[i],&a[i+1]);
		
    }
		
		
	}
	for(i=0;i<size;i++)
		{
			printf("%d,",a[i]);
		}
	
    return 0;
	}

