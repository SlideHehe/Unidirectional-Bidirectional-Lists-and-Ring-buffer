#ifndef BIDIRECTIONAL_LIST_H
#define BIDIRECTIONAL_LIST_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class Iterator;

class Bidirectional_List {
    struct Node {
        Node();

        int data;
        Node *next, *prev;
    };

public:
    friend class Iterator;

    Bidirectional_List();

    Bidirectional_List(const Bidirectional_List &otherList);

    ~Bidirectional_List();

    void print();

    void push(int data);

    void insert(int data, int position);

    int pop();

    int erase(int position);

    void delAll();

    Iterator begin() const;

    Iterator end() const;

    int getByHead(int position) const;

    int getByTail(int position) const;

    int getCount() const;

    bool operator==(const Bidirectional_List &otherList) const;

    bool operator!=(const Bidirectional_List &otherList) const;

    bool operator>(const Bidirectional_List &otherList) const;

    bool operator>=(const Bidirectional_List &otherList) const;

    bool operator<(const Bidirectional_List &otherList) const;

    bool operator<=(const Bidirectional_List &otherList) const;

private:
    Node *head, *tail;
    int count;
};

class Iterator {
public:
    friend struct Bidirectional_List::Node;

    Iterator();

    Iterator(Bidirectional_List::Node *node);

    Iterator(const Iterator &otherIter);

    Iterator &operator++();

    Iterator operator++(int);

    Iterator &operator--();

    Iterator operator--(int);

    Iterator &operator=(const Iterator &otherIter);

    int &operator*() const;

    int operator->() const;

    bool operator==(const Iterator &otherIter) const;

    bool operator!=(const Iterator &otherIter) const;

private:
    Bidirectional_List::Node *currNode;
};

#endif //BIDIRECTIONAL_LIST_H