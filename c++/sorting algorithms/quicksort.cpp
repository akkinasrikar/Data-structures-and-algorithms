#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void display(int array[],int l)
{
	for (int i=0; i<l; i++)
	{
		cout << array[i] << " "; 
	}
	cout<<endl;
}
void swap(int *x,int *y)
{
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

int partition(int array[],int low,int high)
{
	int i,pivot;
	i=low-1;
	pivot=array[high];
	for(int j=low;j<high;j++)
	{
		if(array[j]<pivot)
		{
			i=i+1;
			swap(&array[i],&array[j]);
		}
	}
	swap(&array[i+1],&array[high]);
	return i+1;
}

void quicksort(int array[],int low,int high)
{
	int pi;
	if(low<high)
	{
       pi=partition(array,low,high);
       quicksort(array,low,pi-1);
       quicksort(array,pi+1,high);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int array[10],n;
	for (int i = 0; i < 10;i++)
	{
		array[i] =rand()%(100-1)+1;
	}
	n=sizeof(array)/sizeof(array[0]);
	cout<<"Unsorted array: "<<" ";
	display(array,n);
	quicksort(array,0,n-1);
	cout<<"Sorted array: "<<" ";
	display(array,n);
	return 0;


}
