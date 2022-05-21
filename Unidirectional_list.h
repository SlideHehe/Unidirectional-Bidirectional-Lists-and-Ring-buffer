#ifndef UNIDIRECTIONAL_LIST_H
#define UNIDIRECTIONAL_LIST_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class Iterator_uni;

class Unidirectional_list {
    struct Node {
        int data = 0;
        Node* next = nullptr;
    };

public:
    friend class Iterator_uni;

    Unidirectional_list();

    Unidirectional_list(const Unidirectional_list& otherlist);

    ~Unidirectional_list();

    void print();

    void push(int data);

    void push_first(int data);

    void insert(int data, int position);

    int pop();

    int pop_first();

    int erase(int position);

    void delAll();

    Iterator_uni begin() const;

    Iterator_uni end() const;

    int getCount() const;

    void Xoar();

    Unidirectional_list Div_list(int d);

    bool operator==(const Unidirectional_list& otherlist) const;

    bool operator!=(const Unidirectional_list& otherlist) const;

    bool operator>(const Unidirectional_list& otherlist) const;

    bool operator>=(const Unidirectional_list& otherlist) const;

    bool operator<(const Unidirectional_list& otherlist) const;

    bool operator<=(const Unidirectional_list& otherlist) const;

private:
    Node* head;
    int count;

    void sort_b(int* a, int left, int right);

};

class Iterator_uni {
public:
    friend struct Unidirectional_list::Node;

    Iterator_uni();

    Iterator_uni(Unidirectional_list::Node* Node);

    Iterator_uni(const Iterator_uni& otheriter);

    Iterator_uni& operator++();

    Iterator_uni operator++(int);

    Iterator_uni& operator=(const Iterator_uni& otheriter);

    int& operator*() const;

    int operator->() const;

    bool operator==(const Iterator_uni& otheriter) const;

    bool operator!=(const Iterator_uni& otheriter) const;

private:
    Unidirectional_list::Node* currNode;
};

#endif //UNIDIRECTIONAL_LIST_H
