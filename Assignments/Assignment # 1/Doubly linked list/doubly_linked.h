#include"doublynode.h"
#include<iostream>

using namespace std;

template<typename T>
class doubly_list
{
	private:
		node<T> *FRONT;
		node<T> *BACK;
		
		int n;
		
	public:
		doubly_list()
		{
			FRONT = BACK = NULL;
			n = 0;
		}
		
		~doubly_list()
		{
			make_empty();	
		}		
		
		void push_front(const T &val)
		{
			/*if(FRONT == NULL)
			{
				throw("List underflow!");
			}*/
			
			node<T> *temp;
			temp = new node<T>;
			
			temp->data = val;
			temp->prev = NULL;
			
			if(FRONT == NULL)
			{
				FRONT = BACK = temp;
				temp->next = NULL;
			}
			else
			{
				temp->next = FRONT;		// This step ensures that the new node is linked to the existing front node, effectively placing it at the front of the list.
				FRONT->prev = temp;		// The previous front node's prev pointer is updated to point to the new node (FRONT->prev = temp).   //  This step establishes the backward link from the front node to the new node.
				FRONT = temp;
			}
			
			n++;
		}
		
		void push_back(const T &val)
		{
			if(FRONT == NULL)
			{
				throw("List underlow!");
			}
			
			node<T> *temp;
			temp = new node<T>;
			
			temp->data = val;
			temp->next = NULL;
			
			if(BACK == NULL)	// if forward doubly list is empty.
			{
				FRONT = BACK = temp;
				temp->prev = NULL;
			}
			else
			{
				temp->prev = BACK;
				BACK->next = temp;
				BACK = temp;
			}
			
			n++;
		}
		
		void front_pop()
		{
			if(FRONT == NULL)
			{
				throw("List underflow!");
			}
			
			node<T> *temp;
			
			temp = FRONT;
			
			FRONT = FRONT->next;	// effectively removing front node from the list.
			
			if(FRONT != NULL)
			{
				FRONT->prev = NULL;		// indicating it is first node in the list.
			}
			else
			{
				BACK = NULL;
			}
			
			delete temp;
			n--;
		}
		
		void back_pop()
		{
			if(BACK == NULL)
			{
				throw("List underflow!");
			}
			
			node<T> *temp;
		
			temp = BACK;
			
			BACK = BACK->prev;
			
			if(BACK != NULL)
			{
				BACK->next = NULL;
			}
			else
			{
				FRONT = NULL;
			}
			
			delete temp;
			n--;
		}
		
		T front() const
		{
			if(FRONT == NULL)
			{
				throw("List underflow!");
			}
			
			return FRONT->data;
		}
		
		T back() const
		{
			if(BACK == NULL)
			{
				throw("List underflow!");
			}
			return BACK->data;
		}
		
		bool empty() 
		{
			return FRONT == NULL;
		}
		
		bool full()
		{
			node<T> *temp;
			temp = new node<T>;
			
			if(temp == NULL)
			{
				return true;
			}
			else
			{
				delete false;
				return false;
			}
		}
		
		void make_empty()
		{
			while(!empty())
			{
				front_pop();
			}
		}
		
		int size() const
		{
			return n;
		}
		
		bool find(T &val) const
		{
			node<T> *temp;
			
			temp = FRONT;
			
			while(temp != NULL)
			{
				if(temp->data == val)
				{
					return true;
				}
				temp = temp->next;
			}
			return false;
			
		}
		
};