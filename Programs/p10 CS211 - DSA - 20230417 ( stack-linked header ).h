#include<iostream>
#include"p13 node.h"
#include<string>


using namespace std;

template<typename T>
class stack
{
	private:
		node<T> *TOP;
		int n;	// Number of elements in the stack.
		
	public:
		
		// Time complexity: O(n) as the while loops runs n times as per the values in the stack.
		friend ostream& operator<<(ostream &out, const stack<T> &s) 
		{
			node<T> *temp;
			temp=s.TOP;
			while(temp!=NULL)	// Because at the end temp==NULL.
			{
				out<<temp->data<<" "; // to displat the value
				temp=temp->next;	// To get the address of next value.
			}
			return out;
		}
		
		// Time complexity: order 1
		stack()
		{
			TOP=NULL;		// No data type exists.
			n=0;
		}
		
		/*
		stack(const stack &src)
		{
			SIZE=src.SIZE;
			TOP=src.TOP;
			data=new int[SIZE];		// Allocating new memory
			for(int i=0;i<=TOP;i++)
			{
				data[i]=src.data[i];
			}
		}
		*/	
	
		// TODO: Implement copy constructer
		// Its time complexity is same as of operator equal to as it is being called in here.
		// Time complexity order n -> O(n) 
		stack(const stack<T> &src)
		{
			TOP=NULL;
			operator=(src);
		}
		
		// TODO:
		// In case of v=u ( u will become local perimeter i.e , src ). This member variables directly accedded
		// will be of v ( which is on left side of = operator ) 
		// Time complexity: O(n)
		void operator=(const stack<T> &src)
		{
			make_empty();
			node<T> *temp_ptr;
			stack<T> temp_stk;
			temp_ptr=src.TOP;
			
			while(temp_ptr!=NULL)
			{
				temp_stk.push(temp_ptr->data);
				temp_ptr=temp_ptr->next;
			}
			
			while(!temp_stk.empty())
			{
				int temp_val;
				temp_val=temp_stk.top();
				push(temp_val);
				temp_stk.pop(); // removing value.
			}
		}	// n=src.n this will be done automatically in the push function.
		
		// v < u, u will be accessible via src
		// member variables will represent v
		
		//TODO: Home work.
		// Time comlexity: O(n) 
		// -> Worst time case complexity / Best case: O(1) because it will come out of the loop on first iteration. Loop will only execute only one time.
		bool lessthan(const stack<T> &rhs) const
		{
			return true;
		}
	
		/*
		bool lessthan(const stack<T> &rhs) const
		{
		    int i = 0;
		    while (i <= TOP && i <= rhs.TOP) {
		        if (data[i] >= rhs.data[i]) {
		            return false;
		        }
		        i++;
		    }
		    return (i > TOP);
		}*/
		
		
		// Time complexity: O(n) because of while loop in the make_empty function.
		~stack()
		{
			make_empty();
		}

		// Time complexity: O(1)
		void push(const T &val)	
		{
			node<T> *temp;		// temporary poineter to store address of node type.
			// TODO: For every new statement there must be a delete statement. Free memory->( Destructer[when object scopes ends] and make_empty and TOP ) 
			temp=new node<T>;		// allocate memory and return address.
			temp->data=val;		// Pushing next value.
			if(TOP==NULL)
			{
				temp->next=NULL;	// Storing Null in next part.
			}
			else
			{
				temp->next=TOP;
			}
			TOP=temp;		// coping the address of temp in TOP.
			n++;	// We pushed one extra value in the stack.
		}
		
		// Time complexity: O(1) as it returns only one value and no other thing or call in it.
		T top() const
		{
			if(empty())
			{
				throw("Stsck Underflow!");
			}
			return TOP->data;
		}
		
		// Time complexity: O(1)
		void pop()
		{
			if(empty())
			{
				throw("Stack underflow! ");
			}
			
			node<T> *temp;		// In pop , donot create new memory.
			temp=TOP;	// storing the address of TOP In temporary pointer.
			
			// Can also write TOP=temp->next;
			TOP=TOP->next;		// Storing the address of new node.
			delete temp;
			
			// At the end stack is now empty , and has NULL value.
			n--;
		}
		
		//Time complexity: O(1)
		bool empty() const
		{
			if(TOP==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
			
			// return TOP == NULL;
			// return TOP == NULL ? true : false; ( Turnary operator ).
		}
		
		// Time complexity: O(1) as no repitition and fixed number of statements.
		bool full() const
		{
			node<T> *temp;
			temp=new node<T>;	// checking id there any place in the RAM.
			if(!temp==NULL)
			{
				return true;
			}
			else
			{
				delete temp;	// Required to free the memory.
				return false;
			}
		}
		
		// Same , worst and best case as in Time complexity.
		// Time complexity: O(n) as it executes n times.
		void make_empty()		// There are some values in the stack , we ahve to make it empty.
		{
			// TOP = NULL would result in memory leakage.
			while(!empty())
			{
				pop();
			}
		}
		
		// Time complexity: O(1) best case as it executes only one time.
		int size() const
		{
			return n; // Returning all the values in the stack.
		}
};
/*
template<typename T>
T stack<T>::top() const
{
	if(empty())
	{
		throw("Stack underflow ! ");
	}
	return data[TOP];
}
*/
// Displaying all the values in the stack.

//stack s,t,v;
//...
// cout<<s<<" "<<t<<" "<<v<<endl; 
/*
template<typename T>
ostream& operator<<(ostream &out, const stack<T> &s)
{
	out<<"Stack has "<<s.TOP+1<<" values. ";
	return out;
}*/



