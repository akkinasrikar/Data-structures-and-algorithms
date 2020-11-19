#include <iostream>
#include <cstdlib>
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

void selectionsort(int array[],int l)
{
	int index;
	for(int i=0;i<l;i++)
	{ 
		index=i;
		for(int j=i+1;j<l;j++)
		{
			if(array[index]>array[j])
			{
				index=j;
			}
		}
    swap(&array[index], &array[i]);
    cout<<"Iteration: "<<i+1<<" ";
    display(array,l);
	}
}

int main()
{
	int array[10],n;
	for (int i = 0; i < 10;i++)
	{
		array[i] =rand()%(100-1)+1;
	}
	n=sizeof(array)/sizeof(array[0]);
	cout<<"Unsorted array: "<<" ";
	display(array,n);
	selectionsort(array,n);
	cout<<"Sorted array: "<<" ";
	display(array,n);
	return 0;


}


/*
[a;b) to get numbers in range
rdno = rand() % (b-a) + a
*/