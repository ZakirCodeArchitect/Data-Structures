#include<iostream>

using namespace std;

template<typename T>
struct tnode
{
	T data;
	tnode<T> *left;
	tnode<T> *right;
};

template<typename T>
class bst
{
	private:
		tnode<T> *root;
		int n;
		
	public:
		bst()
		{
			root = NULL;
			n = 0;
		}
		
		void insert(const T &val)
		{
			insert_R(root,val);
			n++;
		}
		
		
		void insert_R(tnode<T> *&ptr , const T &val)
		{
			if(ptr == NULL)
			{
				ptr = new tnode<T>;
				ptr->data = val;
				ptr->left = ptr->right = NULL;
				return;
			}
			else if(val < ptr->data)
			{
				insert_R(ptr->left , val);
			}
			else
			{
				insert_R(ptr->right , val);
			}
		}
		
		void display_R()
		{
			display(root);	
		}
		
		void display(tnode<T> *ptr)
		{
			if(ptr == NULL)
			{
				return;
			}
			else
			{
				cout<<ptr->data<<" ";
				display(ptr->left);
				display(ptr->right);
			}	
		}
		
		void delete_R(const T &val)
		{
			del(root,val);
			n++;
		}
		
		void del(tnode<T> *&ptr , const T &val)
		{
			if(ptr == NULL)
			{
				return;
			}
			else if(val < ptr->data)
			{
				del(ptr->left , val);
			}
			else if( val > ptr->data)
			{
				del(ptr->right , val);
			}
			else
			{
				if(ptr->left == NULL && ptr->right == NULL)
				{
					delete ptr;
					ptr = NULL;
				}
				else if(ptr->left != NULL && ptr->right == NULL)
				{
					tnode<T> *temp;
					temp = ptr->left;
					delete ptr;
					ptr = temp;
				}
				else if(ptr->left == NULL && ptr->right != NULL)
				{
					tnode<T> *temp;
					temp = ptr->right;
					delete ptr;
					ptr = temp;
				}
				else if(ptr->left != NULL && ptr->right != NULL)
				{
					tnode<T> *temp = ptr->left;
					tnode<T> *max;
					max = find(temp);
					ptr->data = max->data;
					del(ptr->left , max->data);
				}

					
			}
		}
		
		tnode<T> *find(tnode<T> *ptr)	// ptr->left
		{
			tnode<T> *temp = ptr;
			while(temp->right != NULL)
			{
				temp = temp->right;
			}
			ptr = temp;		// to remember it.
			return ptr;
		}
};

int main()
{
	bst<int> t;
	
	t.insert(60);
	t.insert(30);
	t.insert(80);
	t.insert(45);
	t.insert(90);
	t.insert(85);
	t.insert(40);
	t.insert(15);
	t.insert(20);
	
	cout<<"Binary Tree : ";	
	t.display_R();
	cout<<endl;
	
	t.delete_R(60);
	
	cout<<"\nBinary Tree after deleting : ";
	t.display_R();
	
	return 0;
}