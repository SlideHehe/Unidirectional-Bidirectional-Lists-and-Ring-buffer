#ifndef RING_BUF_H
#define RING_BUF_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class RingIterator;

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

	void quick_sort_array(int* , int*);

public:
	friend class RingIterator;

	Ring_buf(int );

	Ring_buf(const Ring_buf &);

	void quick_sort();

	void list_split(Ring_buf&, Ring_buf&, const int&);

	void push(int );

	void clear();

	int pop();

	void insert(int , int );

	RingIterator begin() const;

	RingIterator end() const;


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

class RingIterator {
public:
    friend struct Ring_buf::Node;

    RingIterator();

    RingIterator(Ring_buf::Node*);

    RingIterator(const RingIterator&);

    RingIterator &operator++();

    RingIterator operator++(int);

    RingIterator &operator=(const RingIterator&);

    int &operator*() const;

    int operator->() const;

    bool operator==(const RingIterator&) const;

    bool operator!=(const RingIterator&) const;

private:
    Ring_buf::Node *currNode;
};



#endif //RING_BUF_H