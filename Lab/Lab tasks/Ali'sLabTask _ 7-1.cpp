#include<iostream>
using namespace std;

template<typename A>
struct tnode
{
	tnode<A> *left;
	tnode<A> *right;
	A data;
};

template <typename A>
class BST
{
	private:
		
		tnode<A> *root;
		int n;
		
	public:
		
		// Inserting Values:
        void insert_rec ( tnode<A> *&ptr, const A &val )
        {
	        if ( ptr == NULL )
	        {
		        ptr = new tnode<A>;
		        ptr->data = val;
		        ptr->left = ptr->right = NULL;
            }
	
        	else if ( val < ptr->data )
	        {
		        insert_rec ( ptr->left , val );
	        }
	
        	else 
	        {
		        insert_rec ( ptr->right , val );
	        }
        }
        
        // removing pointer from parameter:
        void insert ( const A &val )
        {
        	insert_rec ( root, val );
        	n++;
		}
		
		// Deleting value:
        void removeN ( tnode<A> *&ptr, const A &val )
        {
	        if (ptr == NULL)
		        return;

	        if (val < ptr->data)
		        removeN(ptr->left, val);
		        
	        else if (val > ptr->data)
	        	removeN(ptr->right, val);
	        	
	        else
        	{
		        if (ptr->left == NULL && ptr->right == NULL)
	         	{
		         	delete ptr;   // dangling pointer
		        	ptr = NULL;
		        }
		        
	        	else if (ptr->left == NULL)
		        {
         			tnode<A> *temp;
					temp = ptr;
			        ptr = ptr->right;
		        	delete temp;
		        }
		        
		        else if (ptr->right == NULL)
		        {
			        tnode<A> *temp;
					temp = ptr;
			        ptr = ptr->left;
			        delete temp;
		        }
		        
	        	else
		        {
			        tnode<A> *temp;
					temp = ptr->right;
			        
		        	while (temp->left != NULL)
				        temp = temp->left;
				
			        ptr->data = temp->data;
		        	removeN(ptr->right, temp->data);
		        }
	        }
	
        }
        
        // removing pointer from paramters:
        void removeNode ( const A &val )
        { 	
        	removeN ( root, val );
        	n++;
		}
		
		// Displaying values;
        void display ( const tnode<A> *ptr )
        {
	        if (ptr == NULL)
	    	return;
		
            cout << ptr->data << " ";
    
	        display ( ptr->right );
	        display ( ptr->left );
        }     
        
        // removing pointers from parameters:
        void displaypreorder ()
        {	
        	display ( root );
		}
};

int main()
{
	BST<int> B;
	
	// Inserting values:
	B.insert( 5 );
	B.insert( 7 );
	B.insert( 11);
	B.insert( 17);
	B.insert( 25);
	B.insert( 2 );
    B.insert( 4 );
	B.insert( 3 );
	B.insert( 8 );
	
	// Pre-ordered transversal:
	B.displaypreorder ();
	cout << endl;
	
	B.removeNode ( 2 );
	
	// Root aftr deletion of value:
	B.displaypreorder ();
	cout << endl;
	
  return 0;	
}
	