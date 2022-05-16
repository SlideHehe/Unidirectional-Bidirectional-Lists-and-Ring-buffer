#include "Ring_buf.h"


Node::Node(int data)
{
	this->data = data;
	next = nullptr;
}


bool Ring_buf::emptyness()
{
	if(current_size == 0)
	{
		cerr << "\nSo sorry, buffer is empty.\n";
		return false;
	}
	else 
		return true;
}


bool Ring_buf::overflow()
{
	if(current_size == max_size)
	{
		cerr << "\nSo sorry, buffer is full.\n";
		return false;
	}
	else 
		return true;
}


Ring_buf::Ring_buf(int size): max_size(size)
{ 
	head = nullptr; 
	tail = nullptr; 
	current_size = 0;
}

void Ring_buf::push(int data)
{
	Node *new_node = new Node(data);
	if(head == nullptr) 
	{
		head = new_node;
		tail = new_node;
		current_size++;
	}
	else
	{
		Node *buf = head;
		if (overflow())
		{
			new_node->next = head;
			tail->next = new_node;
			tail = new_node;
			current_size++;
		}
	}
}

int Ring_buf::pop()
{
	if (emptyness())
	{
		int data = head->data;
		Node *new_node = head;
		head = head->next;
		tail->next = head;
		current_size--;
		delete new_node;
		return data;
	}
	return false;	
}


void Ring_buf::insert(int data, int index)
{
	Node *new_node = new Node(data);
	Node *node = head;
	Node *buf = head;
	int i = 1;
	if(index < 0)
	{
		cout << "The index can't be less than 0, so sorry. \n";
	}
	else if(index > current_size-1)
	{
		cout << "\nBuf have not " << index << " elements, buf is less then you think.\n";
	}
	else if (overflow())
	{
		if(index == 0)
		{
			new_node->next = head;
			head = new_node;
			tail->next = head;
			current_size++;
		}
		else if (index == current_size-1)
		{
			delete new_node;
			push(data);
		}
		else 
		{ 
			for(int i = 0; i < index ; i++)
			{
				buf = node;
				node = node->next;
			}
			new_node->next = node;
			buf->next = new_node;
			current_size++;
		}
	}
}

Node* Ring_buf::begin() const { 
	return head;
}

Node* Ring_buf::end() const { 
	return tail;
}


void Ring_buf::delete_node(int index)
{
	Node *node = head->next;
	Node *buf = head;
	Node *buf2 = head;
	if(index < 0)
	{
		cout << "The index can't be less than 0, so sorry. \n";
	}
	else if(index > current_size-1)
	{
		cout << "\nBuf have not " << index << " elements, buf is less then you think.\n";
	}
	else if(emptyness())
	{ 
		if(index == 1 || index == 0)
		{
			if(index == 0)
			{
				delete buf;
				head = node;
				tail->next = head;
			} else
			{
				head->next = node->next;
				delete node;
			}
		}
		else if (index == current_size-1)
		{
			pop();
		}
		else
		{
			for(int i = 1; i < index ; i++)
			{
				buf = node;
				node = node->next;
			}
			
			buf->next = node->next;
			delete node;		
		}
			current_size--;
	}
}

int Ring_buf::count()
{
	return current_size;
}

void Ring_buf::show()
{
	if(emptyness()) 
	{
		Node *node = head;
		for(int i = 0; i < current_size; i++)
		{
			cout << node->data << endl;
			node = node->next;
		} 
	}
}

bool Ring_buf::operator == (const Ring_buf& a) const 
{
	if (this == &a) 
		return true;
	

	if (current_size != a.current_size) 
		return false;


	Node* current_buf = begin();
	Node* a_buf = a.begin();
	while (current_buf != end()) 
	{
		current_buf = current_buf->next;
		a_buf = a_buf->next;

		if (current_buf->data != a_buf->data) 
			return false;
		
	}
	return true;
}


bool Ring_buf::operator != (const Ring_buf& a)  const 
{
	if (this == &a) 
		return false;
		

	if (current_size != a.current_size) 
		return false;
		

	Node* current_buf = begin();
	Node* a_buf = a.begin();

	while (current_buf != end()) 
	{
		current_buf = current_buf->next;
		a_buf = a_buf->next;

		if (current_buf->data == a_buf->data) 
			return true;
		
	}
	return false;
}

bool Ring_buf::operator < (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
		

	if (current_size != a.current_size) 
		return false;
		

	Node* current_buf = begin();
	Node* a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (current_buf->data >= a_buf->data)
			return false;

		current_buf = current_buf->next;
		a_buf = a_buf->next;
	}
	return true;
}

bool Ring_buf::operator <= (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
	

	if (current_size != a.current_size) 
		return false;
		

	Node* current_buf = begin();
	Node* a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (current_buf->data > a_buf->data)
			return false;
		
		current_buf = current_buf->next;
		a_buf = a_buf->next;
	}
	return true;
}

bool Ring_buf::operator > (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
	

	if (current_size != a.current_size) 
		return false;
	

	Node* current_buf = begin();
	Node* a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (current_buf->data <= a_buf->data)
			return false;
			
		current_buf = current_buf->next;
		a_buf = a_buf->next;
	}
	return true;
}

bool Ring_buf::operator >= (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
		

	if (current_size != a.current_size) 
		return false;
		

	Node* current_buf = begin();
	Node* a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (current_buf->data < a_buf->data)
			return false;
			
		current_buf = current_buf->next;
		a_buf = a_buf->next;
	}
	return true;
}


Ring_buf::~Ring_buf()
{
	Node *node = head;
	while(node->next != tail)
	{
		Node *buf = node->next;
		delete node;
		node = buf;
	}
	delete node;		
}
