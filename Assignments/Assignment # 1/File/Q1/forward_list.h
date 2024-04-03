#include "node.h"
#include <iostream>

using namespace std;

template<typename T>
class forward_list 
{
private:
    node<T> *FRONT;
    int n;
    
public:
    forward_list() 
    {
        FRONT = NULL;
        n = 0;        
    }

    forward_list(const forward_list &src) 
    {
        FRONT = NULL;
        operator=(src);
    }

    void operator=(const forward_list &src) 
    {
        if (FRONT != NULL)
            clear();

        node<T> *temp_src;
        node<T> *nn;
        node<T> *temp;
        
        temp_src = src.FRONT;
        
        while(temp_src != NULL)
        {
            nn = new node<T>;
            nn->data = temp_src->data;
            nn->next = NULL;
                
            if (FRONT == NULL)
                FRONT = nn;
            else            
                temp->next = nn;

            temp = nn;
            temp_src = temp_src->next;
        }
        n = src.n;
    }

    ~forward_list() 
    {
        clear();
    }

    void push_front(const T &val) 
    {
        node<T> *temp;
        temp = new node<T>;
        
        if (temp == NULL) 
        {
            throw("List Overflow!");
        }
        
        temp->data = val;
        
        if (FRONT == NULL) //if list is empty
            temp->next = NULL;
        else                //if list is not empty
            temp->next = FRONT;
        FRONT = temp;
        n++;
    }

    T front() const 
    {
        if (FRONT == NULL)
            throw("List Underflow!");
        return FRONT->data;
    }

    void pop_front()  
    {
        if (FRONT == NULL) { //if (empty())
            throw("List Underflow!");
        }
        node<T> *temp;
        temp = FRONT;
        FRONT = FRONT->next;
        delete temp;
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
        if (temp == NULL) 
        {
            return true;
        } 
        else 
        {
            delete temp;
            return false;
        }
    }

    void clear() 
    {
        while(!empty()) 
        {
            pop_front();
        }
        // n = 0;
    }

    bool find(T &val) const 
    {
        node<T> *temp;
        temp = FRONT;
        while (temp != NULL) 
        {
            if (temp->data == val) 
            {
                val = temp->data; //copy satellite data. Only useful in case of structures or objects.
                return true;
            } 
            else 
            {
                temp = temp->next;
            }
        }
        return false;
    }

    int size() const 
    {
        return n;
    }
    
    node<T>* merge( node<T> *ptr1, node<T> *ptr2 )
    {
    	
      	node<T> *ptr3 = NULL;
		node<T> *str = NULL;
		
		if( ptr1->data < ptr2->data)
		{
			ptr3 = ptr1;	// ptr3 is assigned the pointer that points to the smaller element.
			ptr1 = ptr1->next;
		}
		else
		{
			ptr3 = ptr2;
			ptr2 = ptr2->next;	
		}
		
		str = ptr3;		
		
		while(ptr1 != NULL && ptr2 != NULL)		// it compares the data of the current nodes pointed by ptr1 and ptr2 to determine which one is smaller.
		{
			if( ptr1->data < ptr2->data )
			{
				ptr3->next = ptr1;
				ptr1 = ptr1->next;	// moving to the next
			}
			else
			{
				ptr3->next = ptr2;
				ptr2 = ptr2->next;
			}
			ptr3 = ptr3->next;
		}
		
		while(ptr1 != NULL)
		{
			ptr3->next = ptr1;
			
			ptr1 = ptr1->next;
			ptr3 = ptr3->next;
		}
		
		while(ptr2 != NULL)
		{
			ptr3->next = ptr2;
			
			ptr2 = ptr2->next;
			ptr3 = ptr3->next;
		}
		
		return str;
		
	}
	
	node<T> reverse()
	{
		node<T> *prev = NULL;
		node<T> *curr = FRONT;
		nodE<T> *nextptr;
		
		while( curr != NULL )
		{
			nextptr = curr->next;
			curr->next = prev;
			
			prev = curr;
			curr = nextptr;
		}
		
		return prev;
	}
	
	void sort(forward_list &src)
	{
		node<T> *temp;
		
		node<T> *ptr1;
		node<T> *ptr2;
		
		ptr1 = src.FRONT;
		
		while( ptr1->next != NULL )
		{
			ptr2 = ptr1->next;
			while( ptr2 != NULL )
			{
				if( ptr1->data > ptr2->data )
				{
					temp = ptr1;
					ptr1 = ptr2;
					
					ptr2 = temp;
				}
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
		
	}
};
