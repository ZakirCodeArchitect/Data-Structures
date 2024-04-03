#include<iostream>

using namespace std;

template<typename T>
struct tnode
{
	T data;
	tnode<T> *left;
	tnode<T> *right;
};

template<typename U>
void insert(tnode<U> *&ptr , const U &val)
{
	if(ptr == NULL)
	{
		ptr = new tnode<U>;
		ptr->data = val;
		ptr->left = ptr->right = NULL;
		return;
	}
	else if(val < ptr->data)	// 7 < 5
	{
		insert( ptr->left , val);
	}
	else
	{
		insert(ptr->right , val); 
	}
	
}

template<typename U>
void d_InOrder(tnode<U> *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	cout<<ptr->data<<" ";
	d_InOrder(ptr->left);
	d_InOrder(ptr->right);
}

//Client code
int main()
{
	tnode<int> *root;
	
	root = NULL;
	
	insert(root,5);
	insert(root,7);
	insert(root,11);
	insert(root,17);
	insert(root,25);
	insert(root,2);
	insert(root,4);
	
	
	cout << "In-order Binary Tree : ";
	d_InOrder(root);
	cout << endl;
	
	return 0;
}