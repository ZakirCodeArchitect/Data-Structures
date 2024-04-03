#include<iostream>
#include<exception>

using namespace std;

template<typename T>
class stack
{
	private:
		T *arr;
		int size;
		int top;
		
		template<typename U>
		friend ostream& operator<<(ostream &out, const stack<U> &s);
			
	public:
		stack(const int s=100)
		{
			size = s;
			arr = new T[size];
			top = -1;
		}
		
		stack(const stack<T> &src)
		{
			arr = NULL;
			operator=(src);
		}
		
		~stack()
		{
			delete []arr;
		}
		
		void push(const T &x)
		{
			if(full())
			{
				throw("Stack overflow!");
			}
			
			top++;
			arr[top] = x;
		}

		void pop()
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			top--;
		}
		
		T TOP()
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			return arr[top];
		}
		
		bool full() const
		{
			return top == size-1;
		}
		
		bool empty() const
		{
			return top == -1;
		}
		
		void make_empty()
		{
			top = -1;
		}
		
		void operator=(const stack<T> &src)
		{
			top = src.top;
			size = src.size;
			
			if( arr != NULL)
			{
				delete []arr;
			}
			
			arr = new T[size];
			
			for(int i=0;i<=top;i++)
			{
				arr[i] = src.arr[i];	
			}
			
		}
		
		bool operator>(const stack<T> &src) const
		{
			return top > src.top; 
		}
		
		int SIZE() const
		{
			return top+1;
		}
};


template<typename T>
ostream& operator<<(ostream &out , const stack<T> &s)
{
	out<<" stack has "<<s.top+1<<" value "<<endl;
	return out;
}

int main()
{
	stack<int> s(5);		//1st stack 
	
	try
	{
		s.push(1);
		s.push(2);
		s.push(3);		// top valie : LIFO
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	stack<int> t(s);		// copy constructer called.		// 2nd stack
	
	stack<int> x;	// 3rd stack
	x=t;		// assignment operator called.
	
	cout<<"Number of values in the stack t : "<<t.SIZE()<<endl;
	cout<<"\nt stack : "<<endl;
	while(!t.empty())
	{
		cout<<t.TOP()<<endl;
		t.pop();	
	}	
	cout<<endl;
	cout<<"Number of values in the stack t : "<<t.SIZE()<<endl;
	
	
	
	cout<<"\nNumber of values in the stack x : "<<x.SIZE()<<endl;
	cout<<"\nX stack : "<<endl;
	while(!x.empty())
	{
		cout<<x.TOP()<<endl;
		x.pop();	
	}
	cout<<endl;
	cout<<"Number of values in the stack x : "<<x.SIZE()<<endl;

	stack<int> y;		// 4th stack
	
	try
	{
		y.push(11);
		y.push(12);
		y.push(13);
		y.push(14);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"s "<<s<<endl;		// exerion operator called.
	cout<<"y "<<y<<endl;
	
	if(s>y)			// comparison operator called.
	{
		cout<<"s is greater than y "<<endl;
	}
	else
	{
		cout<<"s is smaller than y "<<endl;
	}
	
	stack<string> str;
	
	try
	{
		str.push("Zakir");
		str.push("Ali");
		str.push("Abdullah");
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"Stack str : "<<endl;
	while(!str.empty())
	{
		cout<<str.TOP()<<endl;
		str.pop();
	}
	cout<<endl;
	
	return 0;
	
}