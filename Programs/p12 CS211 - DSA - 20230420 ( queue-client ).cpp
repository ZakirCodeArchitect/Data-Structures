#include "p12 CS211 - DSA - 20230420 ( queue-array ).h"

#include<iostream>

using namespace std;
int main()
{
	queue<int> s;
	
	s.push(10);
	s.push(20);
	
	cout<<"s: "<<s<<endl;
	cout<<"s has "<<s.size()<<" elements. "<<endl;
	
	queue<int> t;
	
	t.push(5);
	t.push(2);
	t.push(7);
	
	cout<<"\nt: "<<t<<endl;
	
	t=s;

	cout<<"\nAfter assigning equal operator "<<endl;
	cout<<"t: "<<t<<endl;
	
	cout<<"\nEmptying s "<<endl;
	while(!s.empty())
	{
		cout<<s.front()<<" ";
		s.pop();
	}
	
	cout<<endl;
	
}