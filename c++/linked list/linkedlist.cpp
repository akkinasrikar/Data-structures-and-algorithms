#include<iostream>
using namespace std;

class linkedlist
{
	private:
		struct node
		{
			int data;
			node *link;
		}*p;
	public:
		linkedlist();
		void addlast(int value);
		void addfirst(int value);
		void addafter(int position,int value);
		void display();
		void count();
		void Delete(int value);
		~linkedlist();
};

linkedlist::linkedlist()
{
	p=NULL;
}

void linkedlist::addlast(int value)
{
	node *temp,*r;
	if(p==NULL)
	{
		temp=new node;
		temp->data=value;
		temp->link=NULL;
	}
	else
	{
		temp=p;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		r=new node;
		r->data=value;
		r->link=NULL;
		temp->link=r;
	}
}

void linkedlist::addfirst(int value)
{
	node *temp;
	temp=new node;
	temp->data=value;
	temp->link=p;
	p=temp;
}

void linkedlist::addafter(int position,int value)
{
	node *temp,*r;
	temp=p;
	for(int i=0;i<position;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			cout<<"You are out of bounds"<<endl;
			return;
		}
	}
	r=new node;
	r->data=value;
	r->link=temp->link;
	temp->link=r;
}

void linkedlist::display()
{
	node *temp;
	temp=p;
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}

void linkedlist::count()
{
	node *temp;
	int c=0;
	temp=p;
	while(temp!=NULL)
	{
       temp=temp->link;
       c++;
	}
	cout<<"No of element are: "<<c<<endl;
}

void linkedlist::Delete(int value)
{
	node *temp,*old;
	temp=p;
	while(temp!=NULL)
	{
		if(temp->data==value)
		{
			if(temp==p)
			{
				p=temp->link;
			}
			else
			{
				old->link=temp->link;
			}
			delete temp;
			return;
		}
		else
		{
			old=temp;
			temp=temp->link;
		}
	}
	cout<<"element is not Found"<<endl;
}

linkedlist::~linkedlist()
{
	node *q;
	while(p!=NULL)
	{
		q=p->link;
		delete p;
		p=q;
	}
}

int main()
{
	linkedlist s;
	int n,item,e,p;
	cout<<"these are the available options: "<<endl;
	cout<<"1:addfirst\n2:addlast\n3:addafter\n4:delete\n5:count\n6:display\n7:Exit"<<endl;
	do
	{
	   cout<<"choose the any number u want "<<endl;
	   cin>>n;
       switch(n)
       {
       	 case 1:
       	 {
            cout<<"enter the number"<<endl;
            cin>>item;
            s.addfirst(item);
            break;
       	 }
       	 case 2:
       	 {
            cout<<"enter the number"<<endl;
            cin>>item;
            s.addlast(item);
            break;
       	 }
       	 case 3:
       	 {
            cout<<"enter the position and number"<<endl;
            cin>>p>>item;
            s.addafter(p,item);
            break;
       	 }
       	 case 4:
       	 {
            cout<<"enter the number"<<endl;
            cin>>item;
            s.Delete(item);
            break;
       	 }
       	 case 5:
       	 {
       	 	s.count();
       	 	break;
       	 }
       	 case 6:
       	 {
            s.display();
            break;
       	 }
         case 7:
         {
            e=3;
            cout<<"Exit";
            break;
         }
       }
	}
	while(e!=3);
	return 0;
}