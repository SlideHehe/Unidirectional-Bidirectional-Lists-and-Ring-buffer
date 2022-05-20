#include "Ring_buf.h"


void Ring_buf::list_split(Ring_buf& list_1, Ring_buf& list_2, const int& value)
{
	if (this == &list_1 || this == &list_2)
		cerr << "ERROR";
	
	if (&list_1 == &list_2)
		cerr << "ERROR";

	list_1.clear();
	list_2.clear();

	for (RingIterator it = begin(); it != end(); ++it)
		if (*it < value)
			list_1.push(*it);
		else
			list_2.push(*it);
}




void Ring_buf::quick_sort()
{
	if(emptyness()){
	int size = current_size;
	int* array_buf = new int[size];
	int k = 0;
	RingIterator it = begin();
	for (; it != end(); ++it)
		array_buf[k++] = *it;

	array_buf[k] = *it;

	int* array_left = array_buf;
	int* array_right = array_left + k;
	quick_sort_array(array_left, array_right);
	clear();
	

	for (int i = 0; i < size; i++){
		push(array_buf[i]);
	}

	delete[] array_buf;
}
}

void Ring_buf::clear()
{
	while(current_size != 0)
		pop();
}


void Ring_buf::quick_sort_array(int* left, int* right)
{
	if (right - left <= 1) return;

	int center = *(left + (right - left)/2);

	int* l = left;
	int* r = right - 1;

	do
	{
		while (*l < center)
			l++;

		while (*r > center)
			r--;

		if (l <= r){
			std::swap(*l, *r);
			l++;
			r--;
		}
	} while (l <= r);



	if (left < r)
		quick_sort_array(left, r + 1);

	if (l < right)
		quick_sort_array(l, right);
}



Ring_buf::Ring_buf(const Ring_buf &otherList) {
    head = tail = nullptr;
    current_size = 0;
    max_size = otherList.max_size;

    if (otherList.current_size != 0) {
        head = new Node(otherList.head->data);
        current_size++;

        Node *newNode, *currNode = head;
        Node *currOther = nullptr;

        for (currOther = otherList.head->next; currOther != otherList.tail; currOther = currOther->next) {
            newNode = new Node(currOther->data);
            currNode->next = newNode;
            currNode = currNode->next;
            current_size++;
        }
        newNode = new Node(currOther->data);
        currNode->next = newNode;
        currNode = currNode->next;
        current_size++;
        tail = currNode;
        tail->next = head;
    } else cerr << "\nSo sorry, buffer is empty.\n";
}



Ring_buf::Node::Node(int data)
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
	if(current_size == 1)
	{
		int data = head->data;
		Node *new_node = head;
		head = head->next;
		tail->next = head;
		current_size--;
		delete new_node;
		head = nullptr;
		tail = nullptr;
		return data;
	}
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


RingIterator Ring_buf::begin() const { 
	return RingIterator(head); 
}

RingIterator Ring_buf::end() const { 
	return RingIterator(tail); 
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


	RingIterator current_buf = begin();
	RingIterator a_buf = a.begin();
	while (current_buf != end()) 
	{

		if (*current_buf != *a_buf) 
			return false;
		
		current_buf++;
		a_buf++;
	}
	return true;
}


bool Ring_buf::operator != (const Ring_buf& a)  const 
{
	if (this == &a) 
		return false;
		

	if (current_size != a.current_size) 
		return false;
		

	RingIterator current_buf = begin();
	RingIterator a_buf = a.begin();


	while (current_buf != end()) 
	{

		if (*current_buf == *a_buf) 
			return true;

		current_buf++;
		a_buf++;
		
	}
	return false;
}

bool Ring_buf::operator < (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
		

	if (current_size != a.current_size) 
		return false;
		

	RingIterator current_buf = begin();
	RingIterator a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (*current_buf >= *a_buf)
			return false;
			
		current_buf++;
		a_buf++;
	}
	return true;
}

bool Ring_buf::operator <= (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
	

	if (current_size != a.current_size) 
		return false;
		

	RingIterator current_buf = begin();
	RingIterator a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (*current_buf > *a_buf)
			return false;
			
		current_buf++;
		a_buf++;
	}
	return true;
}

bool Ring_buf::operator > (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
	

	if (current_size != a.current_size) 
		return false;
	

	RingIterator current_buf = begin();
	RingIterator a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (*current_buf <= *a_buf)
			return false;
			
		current_buf++;
		a_buf++;
	}
	return true;
}

bool Ring_buf::operator >= (const Ring_buf& a) const 
{
	if (this == &a) 
		return false;
		

	if (current_size != a.current_size) 
		return false;
		
	RingIterator current_buf = begin();
	RingIterator a_buf = a.begin();

	for ( ; current_buf != end(); )
	{
		if (*current_buf != *a_buf)
			return false;
			
		current_buf++;
		a_buf++;
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

RingIterator::RingIterator() { currNode = nullptr; }

RingIterator::RingIterator(Ring_buf::Node *node) { currNode = node; }

RingIterator::RingIterator(const RingIterator &otherIter) { currNode = otherIter.currNode; }

RingIterator &RingIterator::operator++() {
    if (currNode)
        currNode = currNode->next;
    return *this;
}

RingIterator RingIterator::operator++(int) {
    Ring_buf::Node *oldNode = currNode;
    if (currNode)
        currNode = currNode->next;
    return oldNode;
}

RingIterator &RingIterator::operator=(const RingIterator &otherIter) {
    if (this == &otherIter)
        return *this;
    currNode = otherIter.currNode;
    return *this;
}

int &RingIterator::operator*() const { return currNode->data; }

int RingIterator::operator->() const { return currNode->data; }

bool RingIterator::operator==(const RingIterator &otherIter) const { return currNode == otherIter.currNode; }

bool RingIterator::operator!=(const RingIterator &otherIter) const { return currNode != otherIter.currNode; }