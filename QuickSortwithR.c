#include<stdio.h>
#include<stdlib.h>

void QuickSort(int a[],int left,int right)
{
	if(left>=right)
		return;
	int l=left+1,r=right;
	int pivot=a[left],t=0;
	
	while(1)
	{
		while(l<=right&&pivot>a[l])
			l++;
			while(pivot<a[r])
				r--;
			if(l<r)
			{
				t=a[l];
				a[l]=a[r];
				a[r]=t;
			} 
			else{
				a[left]=a[r];
				a[r]=pivot;
				break;
			}
	}
	QuickSort(a,left,r-1);
	QuickSort(a,r+1,right);
	
}


void main()
{
int n;
int array[]={2,4,7,1,33,90,12,43,23};
n=9;
printf("\n");
QuickSort(array,0,n-1);
for(int i=0;i<9;i++)
printf("%d\t",array[i]);
}