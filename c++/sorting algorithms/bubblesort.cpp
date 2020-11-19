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

void bubblesort(int array[],int l)
{
   for(int i=0;i<l;i++)
   { 
   	    bool swapped=0; 
   		for(int j=0;j<l-i-1;j++)
   		{
   			if(array[j]>array[j+1])
   			{
   				swap(array[j],array[j+1]);
   				swapped=1;
   			}
   		}
   		if(swapped==0)
   		{
   			break;
   		}
	   	cout<<"Iteration: "<<i+1<<" ";
	    display(array,l);
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
	bubblesort(array,n);
	cout<<"Sorted array: "<<" ";
	display(array,n);
	return 0;


}