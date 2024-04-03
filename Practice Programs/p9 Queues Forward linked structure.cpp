#include <iostream>

using namespace std;

template<typename U>
struct node
{
	U data;
	node<U> *next;
};


template<typename T>
class forward_list
{
	private:
    	node<T>* FRONT;
    	int n;

	public:
    	forward_list()
    	{
        	FRONT = NULL;
        	n = 0;
    	}

	    forward_list(const forward_list& src)
	    {
	        FRONT = NULL;
	        operator=(src);
	    }
	
	    void operator=(const forward_list& src)
	    {
	        if (this == &src)
	        {
	        	return;
			}
	
	        clear();
	        node<T>* srcTemp = src.FRONT;
	        node<T>* destTemp = NULL;
	
	        while (srcTemp != NULL)
	        {
	            node<T>* newNode = new node<T>;
	            newNode->data = srcTemp->data;
	
	            if (FRONT == NULL)
	            {
	                FRONT = newNode;
	                destTemp = newNode;
	            }
	            else
	            {
	                destTemp->next = newNode;
	                destTemp = destTemp->next;
	            }
	
	            srcTemp = srcTemp->next;
	        }
	
	        n = src.n;
	    }
	
	    ~forward_list()
	    {
	        clear();
	    }
	
	    void clear()
	    {
	        while (!empty())
	        {
	            pop_front();
	        }
	    }
	
	    void push_front(const T& val)
	    {
	        node<T>* temp;
			temp = new node<T>;
			
	        /*if (temp == NULL)
	        {
	            throw "List Overflow!";
	        }*/
	
	        temp->data = val;
	        
	        if(temp == NULL)		// if list is empty
	        {
	        	temp->next = NULL;
			}
			else		// if list is not empty.
			{
				temp->next = FRONT;
			}
	        
	        FRONT = temp;
	        n++;
	    }
	
	    T front() const
	    {
	        if (empty())
	        {
	            throw "List underflow!";
	        }
	
	        return FRONT->data;
	    }
	
	    void pop_front()
	    {
	        if (empty())
	        {
	            throw "List underflow!";
	        }
	
	        node<T>* temp;
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
	        node<T>* temp;
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
	
	    bool find(const T& val) const
	    {
	        node<T>* temp;
			temp = FRONT;
			
	        while (temp != NULL)
	        {
	            if (temp->data == val)
	            {
	                return true;
	            }
	            temp = temp->next;
	        }
	        return false;
	    }
	    
	    
};


int main()
{
	
	forward_list<int> q;
	
	try
	{
		q.push_front(1);
		q.push_front(2);
		q.push_front(3);
		q.push_front(4);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop_front();
	}
	
	//cout<<"q : "<<q<<endl;
	
	return 0;
	
}