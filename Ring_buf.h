#ifndef RING_BUF_H
#define RING_BUF_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

struct Node
{
	int data;
	Node* next;
	Node(int);
};

class Ring_buf 
{
private:
	Node *head;
	Node *tail;
	int current_size;
	int max_size;

	bool emptyness();

	bool overflow();
public:
	Ring_buf(int );

	void push(int );

	int pop();

	void insert(int , int );

	Node* begin() const;

	Node* end() const;


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



#endif //RING_BUF_H