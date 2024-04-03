#include"doubly_linked.h"
#include<iostream>

using namespace std;

int main()
{
	doubly_list<int> d;
	
	
	try
	{
		d.push_front(1);
		d.push_front(2);
		d.push_front(3);
		d.push_front(4);		// top
		
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"Doubly List : "<<endl;
	while(!d.empty())
	{
		cout<<d.front()<<" ";
		d.front_pop();
	}
	
	
	
	return 0;
}