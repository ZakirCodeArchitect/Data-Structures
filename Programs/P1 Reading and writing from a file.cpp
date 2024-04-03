#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string name;
	
	fstream f;
	f.open("fileA.txt", ios::in );
	if(f.is_open())		// when file opens
	{		
		
		while(!f.eof())		// Till end of file
		{
			getline(f,name,'\n');		// reading from file
			//f>>name;
			cout<<name;	// printing the read text
		}
		
	}
	else
	{
		cout<<"Failed to open "<<endl;
	}
	
	
	
	f.close();
	
	return 0;
}