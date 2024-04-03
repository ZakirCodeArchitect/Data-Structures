#include"fnode.h"
#include<iostream>

using namespace std;

template<typename T>
class f_list
{
	private:
		node<T> *FRONT;
		int n;
		
	public:
		f_list()
		{
			FRONT = NULL;
			n = 0;
		}
		
		~f_list()
		{
			make_empty();
		}
		
		f_list(const f_list &src)
		{
			FRONT = NULL;
			operator=(src);
		}
		
		void push(const T &val)
		{
			node<T> *temp;
			temp = new node<T>;
			
			if(temp == NULL)
			{
				throw("List overflow!");
			}
			
			temp->data = val;
			
			if(temp == NULL)
			{
				temp->next = NULL;
			}
			else
			{
				temp->next = FRONT;
			}
			
			FRONT = temp;
			n++;
			
		}
		
		void pop()
		{
			if(empty())
			{
				throw("List underflow!");
			}
			
			node<T> *temp;
			temp = FRONT; 
			
			FRONT = FRONT->next;
			delete temp;
			
			n--;	
		}
		
		T front() const
		{
			if(empty())
			{
				throw("List underflow!");
			}
			
			return FRONT->data;
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
		}
		
		void make_empty()
		{
			while(!empty())
			{
				pop();
			}
		}
		
		int size()	const
		{
			return n;
		}
		
		friend ostream& operator<<(ostream &out, const f_list &src)
		{
			node<T> *temp;
			temp = src.FRONT;
			
			while(temp != NULL)
			{
				out<<temp->data<<" ";
				temp = temp->next;
			}
			
			return out;
		}
		
		bool find(const T &val) const
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
		
		/*
		void operator=(const forward_list &src)
		{
			// Emptying the whole forwrd list : 
			if(FRONT != NULL)
			{
				make_empty();
			}
			
			node<T> *temp;
			temp = NULL;
			
			node<T> *temp_src;
			node<T> *nn;
			nn = new node<T>;
			
			temp_src = src.FRONT;
			
			while(temp_src != NULL)
			{
				
				
				nn->data = temp_src->data;
				nn->next = NULL;
				
				if(FRONT == NULL)
				{
					FRONT = nn;		// -> If the current list is empty (i.e., FRONT is NULL), it means this is the first node being added. In this case, we update FRONT to point to the new node (nn).
					temp = FRONT;
				}
				else
				{
					temp->next = nn;	// -? If the current list is not empty, we update the next pointer of the previous node (temp) to point to the new node (nn).
					temp = temp->next;// -> After linking the new node to the current list, we update temp to point to the new node (nn), so it keeps track of the last node in the current list.
				}
				
				temp_src = temp_src->next;
			}
			n = src.n;	//  We update the size of the current list (n) to match the size of the source list (src.n).
		}*/
		
		
		void operator=(const f_list& src)
		{
        // Emptying the whole forward list
        if(FRONT != NULL)
        {
        	make_empty();
		}
	

        node<T> *temp = NULL;
        node<T> *temp_src;
        node<T> *nn;

        temp_src = src.FRONT;

        while (temp_src != NULL) 
		{
            nn = new node<T>;

            nn->data = temp_src->data;
            nn->next = NULL;

            if (FRONT == NULL) 
			{
                FRONT = nn;
                //temp = FRONT;
            }
            else 
			{
                temp->next = nn;
                //temp = temp->next;
            }
			
			temp = nn;
            temp_src = temp_src->next;
        }

        n = src.n;
    }
};