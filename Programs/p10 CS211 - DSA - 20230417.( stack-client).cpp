#include "p10 CS211 - DSA - 20230417 ( stack-linked header ).h"
#include<iostream>

using namespace std;

void f()
{
	stack<int> a,b;
}

int main()
{
	/*
	stack s(2);
	
	try
	{
		s.push(5);
		s.push(2);
		s.push(7);
		s.push(9);
	}
	catch(const char *msg)
	{
		cout<<"Error: "<<msg<<endl;
	}
	stack t(s);		// copy constructor
	
	cout<<"Displaying and emptying the stack : "<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	cout<<endl;	
	
	
	
	try
	{
		s.pop();
		t.push(10);		// Adding at the top if the stack		
		s.push(20);		// Adding at the last of the stack
		s.push(30);
	}
	catch(const char*msg)
	{
		cout<<"Error : "<<msg<<endl;	
	}
	
	cout<<"Displaying and emptying the stack : "<<endl;
	while(!t.empty())
	{
		cout<<t.top()<<endl;
		t.pop();
	}
	cout<<endl;
	
	stack u;
	u=s;
	
	cout<<"Displaying and emptying the stack : "<<endl;
	while(!u.empty())
	{
		cout<<u.top()<<endl;
		u.pop();
	}
	cout<<endl;
	*/
	
	stack<int> u,v;
	
	u.push(3);
	u.push(2);
	u.push(1);
	
		
	v.push(2);
	v.push(6);
	v.push(5);
	v.push(4);
	
	
	if(u.lessthan(v))
	{
		cout<<"u is smaller than v "<<endl;
	}
	else
	{
		cout<<"v is smaller than or equal to u "<<endl;
	}
	
	
	cout<<u.top()<<" is on the top of u "<<endl;
	
	
	cout<<"\nStack Information : "<<endl;
	cout<<"\nu: "<<u<<endl;
	cout<<"v: "<<v<<endl;
	
	
	
	stack<string>s_str;
	s_str.push("Zakir");
	s_str.push("Ali");
	s_str.push("Abdullah");
	
	cout<<"\ns_str: "<<s_str<<endl;
	
	cout<<"\nDisplaying and emptying the stack s_str : \n"<<endl;
	while(!s_str.empty())
	{
		cout<<s_str.top()<<endl;
		s_str.pop();
	}
	cout<<endl;
	
	
	
	return 0;
}