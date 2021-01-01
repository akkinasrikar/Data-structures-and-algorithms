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


void insertionsort(int array[], int l)
{
	int element,j;
	for (int i=1; i<l; i++)
	{
       element=array[i];
       j=i-1;
       while(j>=0 && element<array[j])
       {
          array[j+1]=array[j];
          j=j-1;
       }
       array[j+1]=element;
       cout<<"Iteration "<<i<<": ";
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
	insertionsort(array,n);
	cout<<"Sorted array: "<<" ";
	display(array,n);
	return 0;


}
