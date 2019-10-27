#include<stdio.h>
#include<stdlib.h>

void radix(int a[],int n)
{
	int i,max=a[0],exp=1;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	while(exp<=max)
	{
		int b[10]={0};
		for(i=0;i<n;i++)
			b[a[i]/exp%10]++;
		for(i=1;i<10;i++)
			b[i]+=b[i-1];
		int *t=(int*)malloc(sizeof(int)*n);
		for(i=n-1;i>=0;i--)
			t[--b[a[i]/exp%10]]=a[i];
		for(i=0;i<n;i++)
			a[i]=t[i];
		exp*=10;
	    free(t);
	}
	
}

void main()
{
int n;
int array[]={2,4,7,1,33,90,12,43,23};
printf("\n");
radix(array,9);
for(int i=0;i<9;i++)
printf("%d\t",array[i]);
}