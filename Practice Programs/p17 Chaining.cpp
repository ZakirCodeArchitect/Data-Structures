#include <iostream>
using namespace std;

template<typename U>
struct node
{
	U data;
	node<U> *next;
};

template<typename T>
class LinkedList
{
private:
	node<T> *head;
	int n;

public:
	LinkedList()
	{
		head = NULL;
		n = 0;
	}

	~LinkedList()
	{
		make_empty();
	}

	void make_empty()
	{
		while (!empty())
		{
			pop();
		}
	}

	void pop()
	{
		if (empty())
		{
			throw("List underflow!");
		}

		node<T> *temp = head;
		head = head->next;
		delete temp;
		n--;
	}

	void push(const T& val)
	{
		node<T> *temp = new node<T>;

		temp->data = val;

		if (head == NULL)
		{
			temp->next = NULL;
		}
		else
		{
			temp->next = head;
		}

		head = temp;
		n++;
	}

	bool empty() const
	{
		return head == NULL;
	}

	friend ostream& operator<<(ostream& out, const LinkedList<T>& list)
	{
		node<T> *temp;
		temp = list.head;

		while (temp != NULL)
		{
			out << temp->data << " ";
			temp = temp->next;
		}
		return out;
	}
	
	void remove(const T& val)
	{
		node<T> *current = head;
		node<T> *previous = NULL;

		while (current != NULL && current->data != val) 	// Finding the node to be deleted.
		{
			previous = current;		// if current value is not the one , then it is now the pewvious value
			current = current->next;	// current node iterated to the next one.
		}

		if (current == NULL)	// if empty.
		{
			cout << "Value " << val << " not found in the list." << endl;
			return;
		}

		if (previous == NULL)	// If the first node is to get deleted.
		{
			head = current->next;	// Removing the first node	//  it means that the value to be removed is in the first node of the linked list
		}
		else
		{
			previous->next = current->next;		//  the next pointer of the previous node is updated to skip over the current node ( eliminating the current node ).
		}

		delete current;		
		n--;
	}
	
	bool search(const T &key)
	{
		node<T> *temp = head;
		
		while(temp != NULL)
		{
			if(temp->data == key)
			{
				return true;
			}
			
			temp = temp->next;
		}
		return false;
	}
	
};

template<typename T>
class HashTable
{
	private:
		LinkedList<T> *data;
		int n;

	public:
		HashTable(int size)
		{
			n = size;
			data = new LinkedList<T>[size];
		}
	
		~HashTable()
		{
			delete[] data;
		}
	
		int hash(int key)
		{
			return key % n;
		}
	
		void insert(int key)
		{
			int index = hash(key);
			data[index].push(key);
		}
	
		void retrieve()
		{
			for (int i = 0; i < n; i++)
			{
				cout << "Slot " << i << ": " << data[i] << endl;
			}
		}
	
		void remove(const T& key)
		{
			int index = hash(key); // Finding index of the key to be deleted.
			data[index].remove(key);
		}
		
		bool find(const T& key)
		{
			int index = hash(key);		// Finding the index of the key to be searched.
			return data[index].search(key);
		}
};

int main()
{
	HashTable<int> ht(4);

	ht.insert(2);
	ht.insert(3);
	ht.insert(66);
	ht.insert(15);
	ht.insert(25);
	
	ht.retrieve();
	
	int del;
	cout<<"\nEnter value you want to be deleted : ";
	cin>>del;
	
	ht.remove(del);
	
	cout<<"\nAfter deleting : "<<endl;
	ht.retrieve();
	
	int value;
	
	cout<<"\nEnter value to be found : ";
	cin>>value;
	
	ht.find(value);
	
	if(ht.find(value) == 1 )
	{
		cout<<"Found = "<<value<<endl;
	}
	else
	{
		cout<<"Not Found !! "<<endl;
	}
	
	return 0;
}
