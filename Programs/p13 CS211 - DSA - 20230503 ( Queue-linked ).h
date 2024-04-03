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
			node<T> *temp;
			temp = q.FRONT;
			while( temp != NULL )
			{
				out<<temp->data<<" ";	// Sending all the values to the outstream.
				temp = temp->next;		// It assigns the value of temp->next to temp, effectively moving the temp pointer to the next node in the list.
				}
				
				// - > By repeating this step in a loop or iteration, you can traverse through the linked list and access each node sequentially.
			return out;
		}
		
		
		// Time complexity: O(1)
		queue()
		{
			FRONT = BACK = NULL;
			n = 0;
		}
		
		// TODO
		// Time complexity: O(n)
		queue(const queue<T> &src)		// ?copy constructer. ??
		{
			FRONT = BACK = NULL;
			operator=(src);
		}
		
		~queue()
		{
			make_empty();
		}
		
		// TODO
		void operator=(const queue<T> &src) 
		{
			if(!empty())
			{
				make_empty();
			}
			
			node<T> *temp;		// temporary pointer.
			temp=src.FRONT;
			
			/* We took a pointer and stored first value of Queue in it
				and then pushed that value in the new stack and we 
				gave validation till the loop ends.
			*/
			
			// Storing value one by one in the destination Queue.			
			while( temp!=NULL)
			{
				push(temp->data);
				temp = temp->next;	// To move pointer to next.
			}
			
		}
		
		
		// Instead of top()
		T front() const		// Read only function.
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			return FRONT->data;
		}
		
		// Instead of top()
		T back() const
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			return BACK->data;
		}
		
		void pop()
		{
			if(empty())
			{
				throw("Queue underflow!");
			}
			
			node<T> *temp;
			temp=FRONT; 
			
			//if (FRONT == BACK )
				//BACK = NULL
			
			FRONT = FRONT->next;	// FRONT = temp->next
			delete temp;	// To free the memory.
			
			if( FRONT == NULL )	// WIth this BACK will no more be a Dangling pointer.
			{
				BACK = NULL;
			}
			
			n--;
		}
		
		// Time complexity: O(1)
		bool empty() const
		{
			return FRONT == NULL;	// BACK == NULL;
			// return n;
			// return n==0;
		}
		
		// Time complexity: O(1)
		bool full() const
		{
			node<T> *temp;
			temp=new node<T>;
			
			if( temp == NULL )
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
		
		// Time complexity: O(1)
		void make_empty()
		{
			while( !empty())
			{
				pop();
			}
			n=0;
		}
		
		int size() const
		{
			return n;
		}
		
		void push(const T &val)		// -> Overall, the code appends a new node to the end of the queue, updating the BACK pointer accordingly, and correctly links the nodes together.
		{
			/*
			// Code implemented by students : 			
			if( FRONT == NULL )	 	// if(empty()){}
			{
				FRONT = BACK = new node<T>;
			}
			else
			{
				BACK->next = new node<T>;	// new node address is assigned to the next pointer of the current BACK node. This links the newly created node to the end of the queue.
				BACK = BACK->next;		// The BACK pointer is updated to point to the newly created node, making it the new last node in the queue.
			}	
			
			BACK->data=val;
			BACK->next=NULL;	// The next pointer of the BACK node is set to NULL, indicating that it is the last node in the queue.
			n++;
			*/
			// Code implemented by Sir Rabi : 
			
			
			node<T> *temp;
			temp=new node<T>;
			
			// check if queue is empty
			if( temp == NULL )
			{
				throw("Queue underflow");
			}
			temp->data=val;
			
			
			if( FRONT == NULL)
			{
				temp->next=NULL;
				FRONT = BACK = temp;
			}
			else
			{
				BACK->next=temp;
				BACK=temp;
			}
			
			n++;
		}

};