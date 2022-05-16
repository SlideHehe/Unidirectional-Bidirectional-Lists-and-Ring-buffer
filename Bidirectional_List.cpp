#include "Bidirectional_List.h"

Bidirectional_List::Bidirectional_List() {
    head = tail = nullptr;
    count = 0;
}

Bidirectional_List::Bidirectional_List(const Bidirectional_List &otherList) {
    head = tail = nullptr;
    count = 0;

    if (otherList.count > 0) {
        head = new Node();
        head->data = otherList.head->data;
        count++;

        Node *newNode, *currNode = head;

        for (Node *currOther = otherList.head->next; currOther != nullptr; currOther = currOther->next) {
            newNode = new Node();
            newNode->data = currOther->data;
            currNode->next = newNode;
            newNode->prev = currNode;
            currNode = currNode->next;
            count++;
        }
        tail = currNode;
        tail->next = nullptr;
    } else cerr << "List is empty";
}

Bidirectional_List::~Bidirectional_List() { delAll(); }

void Bidirectional_List::print() {
    if (count > 0) {
        Node *currNode = head;
        int i = 0;

        while (currNode != nullptr) {
            cout << i++ << ") " << currNode->data << endl;
            currNode = currNode->next;
        }

    } else cerr << "List is empty";
}

void Bidirectional_List::push(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        head->prev = nullptr;
        tail = head;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
    }

    tail = newNode;
    count++;

}

void Bidirectional_List::insert(int data, int position) {
    if (position <= count) {
        Node *newNode = new Node();
        newNode->data = data;

        if (position == 0) {
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

            count++;

        } else if (position == count) {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;

            count++;

        } else if (position > 0 && position < count) {
            int currPos = 0;
            Node *currNode;

            for (currNode = head; currNode != nullptr && currPos != position; currNode = currNode->next, currPos++);
            if (currPos == position) {
                newNode->prev = currNode->prev;
                newNode->prev->next = newNode;
                currNode->prev = newNode;
                newNode->next = currNode;
            }

            count++;
        }
    } else cerr << "Such position doesn't exist";
}

int Bidirectional_List::pop() {
    if (count > 0) {
        Node *tmp = tail;

        if (head == tail)
            head = tail = nullptr;
        else {
            if (tail->prev)
                tail = tail->prev;
            tail->next = nullptr;
        }

        delete tmp;
        count--;

    } else cerr << "List is empty";
}

int Bidirectional_List::erase(int position) {
    if (count > 0) {
        Node *tmp;

        if (position == 0) {
            tmp = head;
            if (head == tail)
                head = tail = nullptr;
            else {
                if (head->next)
                    head = head->next;
                head->prev = nullptr;
            }

            delete tmp;
            count--;

        } else if (position == count - 1) {
            tmp = tail;

            if (head == tail)
                head = tail = nullptr;
            else {
                if (tail->prev)
                    tail = tail->prev;
                tail->next = nullptr;
            }

            delete tmp;
            count--;
        } else if (position > 0 && position < count - 1) {
            int currPos = 0;

            for (tmp = head; tmp != nullptr && currPos != position; tmp = tmp->next, currPos++);

            if (currPos == position) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                delete tmp;
            }

            count--;
        } else cerr << "Such position doesn't exist";
    } else cerr << "List is empty";
}

void Bidirectional_List::delAll() {
    Node *tmp;

    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }

    tail = nullptr;
    count = 0;
}

Iterator Bidirectional_List::begin() const { return Iterator(head); }

Iterator Bidirectional_List::end() const { return Iterator(tail); }

int Bidirectional_List::getByHead(int position) const {
    if (count > 0 && position < count && position >= 0) {
        Node *tmp;
        int currPos = 0;

        for (tmp = head; tmp != nullptr && currPos != position; tmp = tmp->next, currPos++);

        if (tmp != nullptr)
            return tmp->data;
    }
    cerr << "List is empty or entered number is greater than number of elements";
    return 0;
}

int Bidirectional_List::getByTail(int position) const {
    if (count > 0 && position < count && position >= 0) {
        Node *tmp;
        int currPos = 0;

        for (tmp = tail; tmp != nullptr && currPos != position; tmp = tmp->prev, currPos++);

        if (tmp != nullptr)
            return tmp->data;
    }
    cerr << "List is empty or entered number is greater than number of elements";
    return 0;
}

int Bidirectional_List::getCount() const { return count; }

bool Bidirectional_List::operator==(const Bidirectional_List &otherList) const { return (count == otherList.count); }

bool Bidirectional_List::operator!=(const Bidirectional_List &otherList) const { return (count != otherList.count); }

bool Bidirectional_List::operator>(const Bidirectional_List &otherList) const { return (count > otherList.count); }

bool Bidirectional_List::operator>=(const Bidirectional_List &otherList) const { return (count >= otherList.count); }

bool Bidirectional_List::operator<(const Bidirectional_List &otherList) const { return (count < otherList.count); }

bool Bidirectional_List::operator<=(const Bidirectional_List &otherList) const { return (count <= otherList.count); }

Iterator::Iterator() { currNode = nullptr; }

Iterator::Iterator(Bidirectional_List::Node *node) { currNode = node; }

Iterator::Iterator(const Iterator &otherIter) { currNode = otherIter.currNode; }

Iterator &Iterator::operator++() {
    if (currNode)
        currNode = currNode->next;
    return *this;
}

Iterator Iterator::operator++(int) {
    Bidirectional_List::Node *oldNode = currNode;
    if (currNode)
        currNode = currNode->next;
    return oldNode;
}

Iterator &Iterator::operator--() {
    if (currNode)
        currNode = currNode->prev;
    return *this;
}

Iterator Iterator::operator--(int) {
    Bidirectional_List::Node *oldNode = currNode;
    if (currNode)
        currNode = currNode->prev;
    return oldNode;
}

Iterator &Iterator::operator=(const Iterator &otherIter) {
    if (this == &otherIter)
        return *this;
    currNode = otherIter.currNode;
    return *this;
}

int &Iterator::operator*() const { return currNode->data; }

int Iterator::operator->() const { return currNode->data; }

bool Iterator::operator==(const Iterator &otherIter) const { return currNode == otherIter.currNode; }

bool Iterator::operator!=(const Iterator &otherIter) const { return currNode != otherIter.currNode; }

Bidirectional_List::Node::Node() {
    prev = next = nullptr;
    data = 0;
}