#include<iostream>
#include"p13 node.h"

using namespace std;

template<typename T>
class queue
{
	private:
		
		// two pointers
		node<T> *FRONT;		// Index pointing to the Front element of the Queue.
		node<T> *BACK;		// Index pointing to the Back element of the Queue.
		 
		int n; // number of elements in the Queue
		
	public:
		//TODO 
		friend ostream& operator<<(ostream &out,const queue<T> &q)
		{
			int f = q.FRONT;
			int b = q.BACK;
			
			while( f != b )
			{
				out<<q.data[f]<<" ";
				f = (f+1)%q.SIZE;
			}
			
			return out;
		}
		
		// TODO 
		// Time complexity: O(1)
		queue()
		{
			FRONT = NULL;
			BACK = NULL;
			n = 0;
		}
		
		// Time complexity: O(n)
		queue(const queue<T> &src)		// copy constructer. ??
		{
			data = NULL;
			operator=(src);
		}
		
		~queue()
		{
			delete []data;
		}
		
		
		void operator=(const queue<T> &src) 
		{
			if(data != NULL)
			{
				delete []data;		// freeing the existing memory.
			}
			
			FRONT = BACK = src.FRONT;		// destination queue
			
			n=0;
			SIZE=src.SIZE;
			
			data=new T[SIZE];
			
			int f= src.FRONT;
			int b= src.BACK;
			while( f != b )
			{
				push(src.data[f]); 		// pushing at the destination.			
				f=(f+1)%src.SIZE;
			}
			
		}
		
		
		// Instead of top()
		T front() const
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			return data[FRONT];
		}
		
		// Instead of top()
		T back() const
		{
			if(BACK == 0)
			{
				return data[SIZE-1]; // value at last index.	
			}
			else
			{
				return data[BACK-1];
			}
					
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			FRONT = (FRONT+1)%SIZE;
			n--;	// as we pop , elements will also decrease thats why we decrement n.
		}
		
		// Time complexity: O(1)
		bool empty() const
		{
			return BACK == FRONT;
		}
		
		// Time complexity: O(1)
		bool full() const
		{
			return ((BACK+1)%SIZE) == FRONT; // BACK+1=0+1;  That 0 == 0 is meant to be done.
			// return SIZE-1 == n;
		}
		
		// Time complexity: O(1)
		void make_empty()
		{
			FRONT = BACK = 0;
			n = 0;
		}
		
		int size() const
		{
			return n;
		}
		
		void push(const T &val)
		{
			if(full())
			{
				throw("Queue overflow");
			}
			data[BACK] = val;
			BACK++;	
			
			/*
			if(BACK==SIZE-1)
			{
				BACK=0;
			}
			else
			{
					BACK++;
			}*/
			
			
		}

};