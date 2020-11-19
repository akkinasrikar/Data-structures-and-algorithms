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

void insertionsortRecursive(int array[],int n)
{
	int last_element,j;
	if(n<=1)
	{
		return;
	}
    insertionsortRecursive(array,n-1);
    last_element=array[n-1];
    j=n-2;
    while (j>=0 && array[j]>last_element)
    {
    	array[j+1]=array[j];
    	j=j-1;
    }
    array[j+1]=last_element;
    display(array,n);
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
	insertionsortRecursive(array,n);
	cout<<"Sorted array: "<<" ";
	display(array,n);
	return 0;


}
