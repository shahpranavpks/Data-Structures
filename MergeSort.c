#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int low,int mid,int high)
{
	int *t=(int*)malloc(sizeof(int)*(high+low-1));
	int i=low,j=mid+1,k=0;
	while(i<=mid&&j<=high)
		t[k++]=a[i]<a[j]?a[i++]:a[j++];
	while(i<=mid)
		t[k++]=a[i++];
	while(j<=high)
		t[k++]=a[j++];
	for(k=0,i=low;i<=high;i++,k++)
	a[i]=t[k];
}


void mergeSort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void main()
{
int n;
int array[]={2,4,7,1,33,90,12,43,23};
printf("\n");
n=9;
mergeSort(array,0,n-1);
for(int i=0;i<9;i++)
printf("%d\t",array[i]);
}