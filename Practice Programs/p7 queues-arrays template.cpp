#include<iostream>
using namespace std;

template<typename T>
class queue
{
	private:
		T *data;
		int FRONT;
		int BACK;
		
		int size;
		int n;
		
	public:
		queue(const int s=100)
		{
			FRONT = BACK = 0;
			size = s + 1;
			data = new T[size];
			n=0;
		}
		
		~queue()
		{
			delete []data;
		}
		
		void push(const T &val)
		{
			if(full())
			{
				throw("Queue overflow!");
			}
			
			data[BACK] = val;
			BACK++;
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Queue unerflow!");
			}
			
			
			FRONT = (FRONT+1)%size;
			n--;
		}
		
		T front() const
		{
			if(empty())
			{
				throw("Queue underflow!");
				
			}
			return data[FRONT];
		}

		T back() const
		{
			if(BACK == 0)
			{
				return data[size-1];
			}
			else
			{
				return data[BACK-1];
			}
		}
		
		bool full() const
		{
			return FRONT == ((BACK+1)%size);
		}
		
		bool empty() const
		{
			return FRONT == BACK;
		} 
		
		int SIZE() const
		{
			return n;
		}
		
		void make_empty()
		{
			FRONT = BACK = 0;
			n = 0;
		}
		
		friend ostream& operator<<(ostream & out, const queue<T> &src)
		{
			int f = src.FRONT;
			int b = src.BACK;
			
			while( f != b)
			{
				out<<src.data[f]<<" ";
				f = ((f+1)%src.size);
			}
			
			return out;
		}
		
		
		queue(const queue &q)
		{
			data = NULL;
			operator=(q);
		}

};

int main()
{
	queue<int> q(4);
	
	try
	{
		q.push(11);
		q.push(22);
		q.push(33);
		q.push(44);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	queue<int> x(4);
	x = q;
	
	queue<int> y(x);
	
	cout<<"y : "<<y<<endl;
	
	while(!y.empty())
	{
		cout<<y.front()<<endl;
		y.pop();
	}
	

	return 0;
}

