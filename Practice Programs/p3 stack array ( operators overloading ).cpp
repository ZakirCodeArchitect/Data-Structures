#include<iostream>

using namespace std;

class stack
{
	private:
		int *arr;
		int top;
		int size;
		friend ostream& operator<<(ostream &out,const stack &src);
		
	public:
		stack(const int s=100)
		{
			arr = new int[s];
			size =s ;
			top = -1;
		}
		
		~stack()
		{
			delete []arr;
		}
		
		stack(const stack &src)
		{
			arr = NULL;
			operator=(src);
		}
		
		int push(const int &x)
		{
			if(full())
			{
				throw("Stack overflow!");
			}
			
			top++;
			return arr[top];
		}
		
		int TOP()
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			return top[arr];
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Stack underflow!");
			}
			
			top--;
		}
		
		bool empty() const
		{
			return top == -1;
		}
		
		bool full() const
		{
			return top == size-1;
		}

		int make_empty()
		{
			top=-1;
		}

		int SIZE() const
		{
			return top+1;
		}
		
		void operator=(const stack &src)
		{
			top = src.top;
			size = src.size;
			
			if( arr != NULL)
			{
				delete []arr;
			}
			
			arr = new int[size];
			
			for(int i=0;i<=size;i++)
			{
				arr[i] = src.arr[i];
			}
		}
		
		bool operator>(const stack &src)
		{
			return top > src.top;
		}
	
};

ostream& operator<<(ostream &out , const stack &s)
{
	out<<"stack has "<<s.top+1<<" values."<<endl;
	return out;
}


int main()
{
	
	stack s;
	
	try
	{
		s.push(1);
		s.push(2);
		s.push(3);
	
	}
	catch( const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"s "<<s<<endl;
	
	/*
	cout<<"Stack s : "<<endl;
	while(!s.empty())
	{
		cout<<s.TOP()<<endl;
		s.pop();
	}
	*/
	
	stack v;
	
	try
	{
		v.push(11);
		v.push(12);
		v.push(13);
		v.push(14);
	}
	catch( const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"v "<<v<<endl;
	
	if(s>v)
	{
		cout<<"s is greater than v "<<endl;
	}
	else
	{
		cout<<"s is smaller than v "<<endl;
	}
	
	
	return 0;
}