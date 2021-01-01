#include<iostream>
#include <queue>
using namespace std;


struct Node
{
  int data;
  struct Node* left;
  struct Node* right;

};

Node* CreateNode(int data)
{
	Node* node = new Node();
	if(!node)
	{
		cout << "Memory error"<<endl;
		return NULL;
	}

	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

Node* InsertNode(Node* root,int data)
{
	if (root == NULL)
	{
		root=CreateNode(data);
		return root;
	}

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* temp=q.front();
		q.pop();

		if (temp->left !=NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left =CreateNode(data);
			return root;
		}
		if (temp->right !=NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right =CreateNode(data);
			return root;
		}
	}
}


void inorder(Node *temp)
{
	if(temp==NULL)
	{
		return;
	}

	inorder(temp->left);
	cout<<temp->data<<endl;
	inorder(temp->right);
}

int main()
{
	Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout << "Inorder traversal before insertion: "<<endl;
    inorder(root);
    cout << endl;

    int key=12;
    root=InsertNode(root,key);

    cout << "Inorder traversal after insertion: "<<endl;
    inorder(root);
    cout << endl;

    return 0;
}