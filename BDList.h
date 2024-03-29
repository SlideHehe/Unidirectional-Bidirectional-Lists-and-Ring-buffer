#ifndef BIDIRECTIONAL_LIST_H
#define BIDIRECTIONAL_LIST_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class BDListIterator;

class BDList {
    struct Node {
        Node();

        int data;
        Node *next, *prev;
    };

public:
    friend class BDListIterator;

    BDList();

    BDList(const BDList &otherList);

    ~BDList();

    void print();

    void pushBegin(int data);

    void pushEnd(int data);

    void insert(int data, int position);

    int popBegin();

    int popEnd();

    int erase(int position);

    void delAll();

    BDList split(int value);

    void quickSort();

    BDListIterator begin() const;

    BDListIterator end() const;

    int getByHead(int position) const;

    int getByTail(int position) const;

    int getCount() const;

    bool operator==(const BDList &otherList) const;

    bool operator!=(const BDList &otherList) const;

    bool operator>(const BDList &otherList) const;

    bool operator>=(const BDList &otherList) const;

    bool operator<(const BDList &otherList) const;

    bool operator<=(const BDList &otherList) const;

private:
    Node *head, *tail;
    int count;

    Node *partition(Node *left, Node *right);

    void _quickSort(Node *left, Node *right);
};

class BDListIterator {
public:
    friend struct BDList::Node;

    BDListIterator();

    BDListIterator(BDList::Node *node);

    BDListIterator(const BDListIterator &otherIter);

    BDListIterator &operator++();

    BDListIterator operator++(int);

    BDListIterator &operator--();

    BDListIterator operator--(int);

    BDListIterator &operator=(const BDListIterator &otherIter);

    int &operator*() const;

    int operator->() const;

    bool operator==(const BDListIterator &otherIter) const;

    bool operator!=(const BDListIterator &otherIter) const;

private:
    BDList::Node *currNode;
};

#endif //BIDIRECTIONAL_LIST_H
