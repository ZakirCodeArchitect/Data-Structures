#include<iostream>
#include<exception>

using namespace std;

class stack
{
	private:
		int *arr;
		int top;
		int size;
		
	public:
		stack(const int s)
		{
			arr = new int[s];
			top = -1;
			size = s;
		}
		
		~stack()
		{
			delete []arr;
		}
		
		void push(const int &x)
		{
			if(full())
			{
				throw("Stack overflow!");
			}
			
			top++;
			arr[top]=x;
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			top--;
		}
		
		int TOP() const
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			return arr[top];
		}
		bool empty() const
		{
			return top == -1;
		}
		
		bool full() const
		{
			return top == size-1;
		}
		
		void make_empty()
		{
			top = -1;
		}
		
		stack(const stack &src)
		{
			arr = NULL;
			operator=(src);
		}
		
		int SIZE() const
		{
			return top+1;
		}
		
		void operator=(const stack &src)	// Must make the array empty before assigning another to it.
		{
			top=src.top;
			size=src.size;
			
			if( arr != NULL )
			{
				delete []arr;
			}
			
			arr = new int[size];
			
			for(int i=0;i<=top;i++)
			{
				arr[i]=src.arr[i];
			}
		}
		
		
};

int main()
{
	stack s(5);
	
	try
	{
		s.push(10);
		s.push(11);
		s.push(12);
		s.push(13);
		s.push(14);		// top value
	}
	catch(const char *mssg)
	{
		cout<<"Error : "<<mssg<<endl;
	}
	
	stack t(s);		// copying values 
	
	cout<<"Emptying and displaying the values of stack s : "<<endl;
	while(!s.empty())
	{
		cout<<"Top value : "<<s.TOP()<<endl;
		s.pop();
	}
	cout<<endl;
	
	stack u(5);		// overloading operator
	u=t;
	
	cout<<"Emptying and displaying the values of stack t : "<<endl;
	while(!t.empty())
	{
		cout<<"Top value : "<<t.TOP()<<endl;
		t.pop();
	}
	
	
	cout<<"Emptying and displaying the values of stack t : "<<endl;
	while(!u.empty())
	{
		cout<<"Top value : "<<u.TOP()<<endl;
		u.pop();
	}
	
	
	try
	{
		u.push(0);
		u.push(1);
		u.push(2);
		u.push(3);
		u.push(4);		// top value 
		
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"After changing the values of stack t into stack u : "<<endl;
	while(!u.empty())
	{
		cout<<"Top value : "<<u.TOP()<<endl;
		u.pop();
	}
	
	return 0;
}