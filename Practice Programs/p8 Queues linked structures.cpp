#include<iostream>

using namespace std;

template<typename U>
struct node
{
	U data;
	node *next;
};

template<typename T>
class queue
{
	private:
		 node<T> *FRONT;
		 node<T> *BACK;
		 
		 int n;
		 
	public:
		queue()
		{
			FRONT = BACK = NULL;
			n = 0;
		}
		
		~queue()
		{
			make_empty();
		}
		
		void make_empty()
		{
			while(!empty())
			{
				pop();
			}
			
			n = 0;
		}
		
		void push(const T &val)
		{
			if(FRONT == NULL)
			{
				FRONT = BACK = new node<T>;
			}
			else
			{
				BACK->next = new node<T>;
				BACK = BACK->next;
			}
			BACK->next = NULL;
			BACK->data = val;
			
			n++;
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			node<T> *temp;
			
			temp = FRONT;
			
			FRONT = FRONT->next;
			delete temp;
			
			if(FRONT == NULL)
			{
				BACK = NULL;
			}
			n--;
		}
		
		bool empty() const
		{
			return FRONT == NULL;
		}
		
		bool full() const
		{
			node<T> *temp;
			temp = new node<T>;
			
			if(temp == NULL)
			{
				return true;
			}
			else
			{
				delete temp;
				return false;	
			}
			return 0;	
		}
		
	friend ostream& operator<<(ostream &out, const queue<T> &src)
	{
	    node<T> *temp;
	    temp = src.FRONT;
	
	    while ( temp != NULL )
	    {
	        out << temp->data << " ";
	        temp = temp->next;
	    }	
	
	    	return out;
	}

		
		queue(const queue<T> &q)
		{
			FRONT = BACK = NULL;
			operator=(q);
		}
		
		T front() const
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			return FRONT->data;
		}
		
		T back() const
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			return BACK->data;
			
		}
		
		int SIZE()
		{
			return n;
		}
		
		
};

int main()
{
	queue<int> q;
	
	try
	{
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"q : "<<q<<endl;
	
	cout<<"Top value in the Queue : "<<q.front()<<endl;
	
	
	return 0;
}