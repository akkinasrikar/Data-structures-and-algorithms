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

void deletedeepestnode(struct Node* root, struct Node* d_node)
{
	queue<struct Node*> q; 
    q.push(root); 
    struct Node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
}

Node* DeleteNode(struct Node* root,int key)
{
	if (root == NULL)
	{
		return NULL;
	}
    
    if(root->left==NULL && root->right==NULL)
    {
    	if (root->data==key)
    	{
    		return NULL;
    	}
    	else
    	{
    		return root;
    	}
    }


	queue<Node*> q;
	q.push(root);
	struct Node* key_node = NULL; 
    struct Node* temp; 

	while (!q.empty())
	{
		temp=q.front();
		q.pop();

		if(temp->data==key)
		{
             key_node=temp;
		}

		if (temp->left)
		{
			q.push(temp->left);
		}

		if (temp->right)
		{
			q.push(temp->right);
		}
	}

	if(key_node!=NULL)
	{
		int x = temp->data;
		deletedeepestnode(root,temp);
		key_node->data=x;
	}
	return root;
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
    root->left->right = CreateNode(12);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout << "Inorder traversal before insertion: "<<endl;
    inorder(root);
    cout << endl;

    int key=11;
    root=DeleteNode(root,key);

    cout << "Inorder traversal after Deletion: "<<endl;
    inorder(root);
    cout << endl;

    return 0;
}