#include "dnode.h"
#include <iostream>

using namespace std;

template<typename T>
class list 
{
	private:
		dnode<T> *FRONT;
		dnode<T> *BACK;
    	int n;
	public:
	    list() 
		{
	        FRONT = BACK = NULL;
	        n = 0;        
	    }
	
	    list(const list &src) 
		{
	        FRONT = BACK = NULL;
	        operator=(src);
	    }
	
	    ~list() 
		{
	        clear();
	    }
	
	    void push_front(const T &val) 
		{
	        dnode<T> *temp;
	        temp = new dnode<T>;
	
	        if (temp == NULL) {
	            throw("List Overflow!");
	        }
	
	        temp->data = val;
	        temp->prev = NULL;
	
	        if (FRONT == NULL) //list is empty
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
	        dnode<T> *temp;
	        temp = new dnode<T>;
	        
	        temp->data = val;
	        temp->next = NULL;
	        
			if (BACK == NULL)	// if forward doubly list is empty.
			{
	        	FRONT = BACK = temp;
	            temp->prev = NULL;
	        }
			else
			{
	            temp->prev = BACK;	// linking the new node to the previous last node.
	            BACK->next = temp;	//  linking the previous last node to the new last node.
	            BACK = temp;
	        }
	        n++;
	    }
	
	    T front() const 
		{
	        if (FRONT == NULL)
	            throw("List Underflow!");
	        return FRONT->data;
	    }
	
	    T back() const {
	        if (FRONT == NULL)
	            throw("List Underflow!");
	        return BACK->data;
	    }
	
	    void pop_front()  
		{
	        if (FRONT == NULL)
	            throw("List Underflow!");
	
	        dnode<T> *temp;
	
	        temp = FRONT;
	
	        FRONT = FRONT->next;		// effectively removing front node from the list.
	
	        delete temp;
	
	        if (FRONT != NULL) 
			{
	            FRONT->prev = NULL;		// indicating it is first node in the list.
	        } 
			else 
			{
	            BACK = NULL;
	        }
	        n--;
	    }
	
	    // void pop_front_no_temp()  {
	    //     if (FRONT == NULL)
	    //         throw("List Underflow!");
	
	    //     if (FRONT == BACK) {
	    //         delete FRONT;
	    //         FRONT = BACK = NULL;
	    //     } else {
	    //         FRONT = FRONT->next;
	    //         delete FRONT->prev;
	    //         FRONT->prev = NULL;
	    //     }
	    
	    // }
	
	    void pop_back()  
		{
	        if (FRONT == NULL)
	            throw("List Underflow!");
	
	        dnode<T> *temp;
	        temp = BACK;
	
	        BACK = BACK->prev;		// effectively removing the last node from the list.
	
	        delete temp;
	
	        if (BACK == NULL) 
			{
	            FRONT = NULL;		// indicating list is now empty
	        } 
			else 
			{
	            BACK->next = NULL;			// done to indicate that it is now the last node in the list.
	        }
	        n--;
	    }

	    bool empty() const {
	        // return FRONT == NULL;
	        if (FRONT == NULL)
	            return true;
	        else
	            return false;
	    }
	
	    bool full() const 
		{
	        dnode<T> *temp;
	        temp = new dnode<T>;
	        
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
	        while(!empty()) {
	            pop_front();
	        }
	        // n = 0;
	    }
	
	    bool find(T &val) const 
		{
	        dnode<T> *temp;
	        temp = FRONT;
	        while (temp != NULL) 
			{
	            if (temp->data == val) 
				{
	                val = temp->data; //copy satellite data. Only useful for stuctures and objects
	                return true;
	            } 
				else 
				{
	                temp = temp->next;
	            }
	        }
	        return false;
	    }
	
	    int size() const {
	        return n;
	    }
	
};