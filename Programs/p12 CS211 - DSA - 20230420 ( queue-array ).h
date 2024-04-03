#include<iostream>

using namespace std;

template<typename T>
class queue
{
	private:
		int SIZE;	// size of an array 
		int TOP;
		
		T *data;	// To store data
		int FRONT;	// index pointing to front of the stack.
		int BACK;	// index pointing to back of the queue.
		
		int n; // number of elements in the stack
		
	public:
		friend ostream& operator<<(ostream &out,const queue<T> &q)
		{
			int f = q.FRONT;
			int b = q.BACK;
			
			while( f != b )
			{
				out<<q.data[f]<<" ";
				f = (f+1)%q.SIZE;		//  This updates f to the next index in a circular manner, ensuring that it wraps around when it reaches the end of the array.
			}
			
			return out;
		}
		
		// Time complexity: O(1)
		queue(int s=100)
		{
			FRONT = BACK = 0;	// Index.
			SIZE = s+1;	// For extra space -> The reason for adding 1 to the specified size (s) is to accommodate an extra space in the array. This extra space is used to differentiate between an empty queue and a full queue.
			data = new T[SIZE];
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
			if(BACK == 0) 		// First index.
			{
				return data[SIZE-1]; // Retrieves the value at the last index of the array.	
			}
			else	// If other than first index.
			{
				return data[BACK-1];	// Retrieves the latest added value of the stack.
			}		
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			FRONT = (FRONT+1)%SIZE;		// 1. After removing an element from the queue, we need to update the front index to point to the new front element.	2. ->  we use the modulo operator % to ensure that the front index wraps around to 0 when it reaches the end of the array.
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
			return FRONT == ((BACK+1)%SIZE) ; // BACK+1=0+1;  That 0 == 0 is meant to be done.
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