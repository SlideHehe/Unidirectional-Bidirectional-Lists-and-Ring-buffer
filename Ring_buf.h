#ifndef RING_BUF_H
#define RING_BUF_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class Iterator;

class Ring_buf 
{

private:

	struct Node
	{
		int data;
		Node* next;
		Node(int);
	};

	Node *head;
	Node *tail;
	int current_size;
	int max_size;

	bool emptyness();

	bool overflow();
public:
	friend class Iterator;

	Ring_buf(int );

	void push(int );

	int pop();

	void insert(int , int );

	Iterator begin() const;

	Iterator end() const;


	void delete_node(int );

	int count();

	void show();

	bool operator == (const Ring_buf& ) const;


	bool operator != (const Ring_buf& )  const;

	bool operator < (const Ring_buf& ) const;

	bool operator <= (const Ring_buf& ) const;

	bool operator > (const Ring_buf& ) const;

	bool operator >= (const Ring_buf& ) const;


	~Ring_buf();

};

class Iterator {
public:
    friend struct Ring_buf::Node;

    Iterator();

    Iterator(Ring_buf::Node*);

    Iterator(const Iterator&);

    Iterator &operator++();

    Iterator operator++(int);

    Iterator &operator=(const Iterator&);

    int &operator*() const;

    int operator->() const;

    bool operator==(const Iterator&) const;

    bool operator!=(const Iterator&) const;

private:
    Ring_buf::Node *currNode;
};



#endif //RING_BUF_H