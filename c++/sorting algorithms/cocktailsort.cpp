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

void cocktailsort(int array[],int n)
{
   int start,end,check;
   start=0;
   end=n;
   while(start!=end)
   {
      check=1;
      for(int i=start;i<end-1;i++)
      {
      	if(array[i]>array[i+1])
      	{
      		swap(&array[i],&array[i+1]);
      		check=0;
      	}
      }
      end=end-1;
      display(array,n);
      if(check==1)
      {
      	break;
      }
      check=1;
      for(int i=end;i>start;i--)
      {
      	if(array[i]<array[i-1])
      	{
      		swap(&array[i-1],&array[i]);
      		check=0;
      	}
      }
      start=start+1;
      display(array,n);
      if(check==1)
      {
      	break;
      }
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
	cocktailsort(array,n);
	cout<<"Sorted array: "<<" ";
	display(array,n);
	return 0;


}
