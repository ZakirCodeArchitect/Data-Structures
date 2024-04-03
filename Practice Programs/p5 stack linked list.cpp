#include<iostream>
using namespace std;

template<typename U>
struct node
{
	U data;
	node<U> *next;
};

template<typename T>
class stack
{
	private:
		node<T> *top;
		int size;
		
	public:
		
		friend ostream& operator<<(ostream &out, const stack<T> &s)
		{
			node<T> *temp;	
			temp = s.top;
			// here new memory will not be allocated as there wiil be memory leak.
			
			// -> When you have to write the address of another pointer , you dont allocate new mememory.
			
			while(temp != NULL)
			{
				out<<temp->data<<" ";
				temp = temp->next;
			}
			return out;
		}
		
		stack()
		{
			top = NULL;
			size = 0;
		}
		
		~stack()
		{
			make_empty();
		}
		
		void make_empty()
		{
			while(!empty())
			{
				pop();	
			}	
		}
		
		void push(const int &val)
		{
			node<T> *temp;
			temp = new node<T>;
			
			temp->data = val;
			
			if( top == NULL)
			{
				temp->next = NULL;
			}
			else
			{
				temp->next = top;
			}
			
			top = temp;
			size++;
			
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			node<T> *temp;
			temp = top;		// The purpose of this is to be able to delete the top element after it has been removed from the stack.
			
			top = top->next;		// Next, the code updates the top pointer to point to the next element in the stack. This effectively removes the top element from the stack.
			delete temp;	// to prevent memory leak.
			size--;
		}
		
		bool empty() const
		{
			return top == NULL;
		}
		
		bool full() const
		{
			node<T> *temp;
			temp = new node<T>;
			
			if( temp == NULL)
			{
				return true;
			}
			else
			{
				delete temp;
				return false;	
			}
		}
		
		int TOP() const
		{
			if(empty())
			{
				throw("Stack overflow!");
			}
			return top->data;
			
		}
		
		void operator=(const stack<T> &src)
		{
			make_empty();
			
			node<T> *temp;
			
			stack stk;
			
			temp = src.top;
			
			while( temp !=	NULL)	// till the temo pointer points to NULL
			{
				stk.push(temp->data);
				temp = temp->next;
			}
			
			while( !stk.empty())	// till the stack is empty
			{
				int val;
				val = stk.TOP();
				push(val);
				stk.pop();
			}
			
		}
		
		int SIZE() const
		{
			return size;	
		}
		
		stack(const stack<T> &src)
		{
			top = NULL;
			operator=(src);
		}
};

int main()
{
	stack<int> s;
	
	try
	{
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
	}
	catch(const char msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"Stack information : "<<endl;
	cout<<"s : "<<s<<endl;
	
	stack<int> t;
	t=s;
	
	cout<<"t : "<<t<<endl;
	
	stack<int> x(t);
	
	cout<<"x : "<<x<<endl;
	
	return 0;
	
}