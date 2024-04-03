#include<iostream>

using namespace std;

class queue
{
	private:
		int *arr;
		
		int front;
		int back;
		
		int size;
		
	public:
		queue(const int s)
		{
			size = s;
			arr = new int[size];
			front = back = -1;
		}
		
		void push(const int &val)	// FIFO
		{
			if( back == size - 1)		// means stack is full.
			{
				cout<<"Queue overflow"<<endl;
				return ;
			}
			
			back++;
			arr[back] = val;
			
			if(front == -1)		// Means first entry of the stack 
			{
				front++;
			}
		}
		
		void pop()
		{
			if( front == -1 || front > back)	// this means queue is empty
			{
				cout<<"No elements in queue "<<endl;
				return ;
			}
			
			front ++;
		}
		
		int peek()
		{
			if( front == -1 || front > back)	// this means queue is empty
			{
				cout<<"No elements in queue "<<endl;
				return -1;
			}
			
			return arr[front];
		}
		
		bool empty()
		{
			if( front == -1 || front > back)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}

};

int main()
{
	
	queue q(5);
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	while(!q.empty())
	{
		cout<<q.peek()<<endl;
		q.pop();
	}
	
	q.pop();
	
	
	return 0;
}