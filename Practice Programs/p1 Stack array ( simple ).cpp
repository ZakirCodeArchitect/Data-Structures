#include<iostream>

using namespace std;

// ADT Cod
class stack
{
	private:
		int *arr;	// dynamic array
		int top;	// Index pointing at top element.
		int n;
		
	public:
		stack(const int size=100)
		{
			arr = new int[n];
			top = -1;
			n=size;
		}
		
		~stack()
		{
			delete []arr;
		}
		
		void push(const int x)
		{
			if(top == n-1)
			{
				cout<<"Stack overflow!"<<endl;
				return;
			}
			
			top++;		// because top = -1 , while initialized.
			arr[top]=x;
		}
		
		int TOP()
		{
			if( top == -1)
			{
				cout<<"No element in the stack!"<<endl;
				return -1;
			}
			
			return arr[top];
		}
		
		void pop()
		{
			if( top == -1 )
			{
				cout<<"No element to pop ! "<<endl;
				return;
			}
			
			top--;
			
		}
		
		int empty() const
		{
			return top==-1;
		}
		
		int size() const
		{
			return top+1;
		}

};

//Client code
int main()
{
	stack s(3);
	
	s.push(1);
	s.push(2);
	s.push(3);
	
	cout<<"Total elements in the stack : "<<s.size()<<endl;
	
	// Displaying and emptying the stack : 
	while(!s.empty())
	{
		cout<<"Top value : "<<s.TOP()<<endl;
		s.pop();
	}
	
	
	return 0;
}

