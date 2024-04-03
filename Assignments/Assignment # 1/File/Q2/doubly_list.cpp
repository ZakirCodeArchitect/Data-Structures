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
	
	cout<<"Front element : "<<d.front()<<endl;
	
	cout<<" Sorted doubly list : "<<sort(d)<<endl;
	
	cout<<" Reversed doubly list : "<<reverse(d)<<endl;
	
	return 0;
}