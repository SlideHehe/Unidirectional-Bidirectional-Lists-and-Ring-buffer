#include "BDList.h"

BDList::BDList() {
    head = tail = nullptr;
    count = 0;
}

BDList::BDList(const BDList &otherList) {
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

BDList::~BDList() { delAll(); }

void BDList::print() {
    if (count > 0) {
        Node *currNode = head;
        int i = 0;

        while (currNode != nullptr) {
            cout << i++ << ") " << currNode->data << endl;
            currNode = currNode->next;
        }

    } else cerr << "List is empty";
}

void BDList::push(int data) {
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

void BDList::insert(int data, int position) {
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

        } else if (position > 0 && position <= count / 2) {
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
        } else if (position < count - 1 && position > count / 2) {
            int currPos = count - 1;
            Node *currNode;

            for (currNode = tail; currNode != nullptr && currPos != position; currNode = currNode->prev, currPos--);

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

int BDList::pop() {
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

int BDList::erase(int position) {
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
        } else if (position > 0 && position <= count / 2) {
            int currPos = 0;

            for (tmp = head; tmp != nullptr && currPos != position; tmp = tmp->next, currPos++);

            if (currPos == position) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                delete tmp;
            }

            count--;
        } else if (position < count - 1 && position > count / 2) {
            int currPos = count - 1;

            for (tmp = tail; tmp != nullptr && currPos != position; tmp = tmp->prev, currPos--);

            if (currPos == position) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                delete tmp;
            }

            count--;
        } else cerr << "Such position doesn't exist";
    } else cerr << "List is empty";
}

void BDList::delAll() {
    Node *tmp;

    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }

    tail = nullptr;
    count = 0;
}

BDListIterator BDList::begin() const { return BDListIterator(head); }

BDListIterator BDList::end() const { return BDListIterator(tail); }

int BDList::getByHead(int position) const {
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

int BDList::getByTail(int position) const {
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

int BDList::getCount() const { return count; }

bool BDList::operator==(const BDList &otherList) const { return (count == otherList.count); }

bool BDList::operator!=(const BDList &otherList) const { return (count != otherList.count); }

bool BDList::operator>(const BDList &otherList) const { return (count > otherList.count); }

bool BDList::operator>=(const BDList &otherList) const { return (count >= otherList.count); }

bool BDList::operator<(const BDList &otherList) const { return (count < otherList.count); }

bool BDList::operator<=(const BDList &otherList) const { return (count <= otherList.count); }

BDListIterator::BDListIterator() { currNode = nullptr; }

BDListIterator::BDListIterator(BDList::Node *node) { currNode = node; }

BDListIterator::BDListIterator(const BDListIterator &otherIter) { currNode = otherIter.currNode; }

BDListIterator &BDListIterator::operator++() {
    if (currNode)
        currNode = currNode->next;
    return *this;
}

BDListIterator BDListIterator::operator++(int) {
    BDList::Node *oldNode = currNode;
    if (currNode)
        currNode = currNode->next;
    return oldNode;
}

BDListIterator &BDListIterator::operator--() {
    if (currNode)
        currNode = currNode->prev;
    return *this;
}

BDListIterator BDListIterator::operator--(int) {
    BDList::Node *oldNode = currNode;
    if (currNode)
        currNode = currNode->prev;
    return oldNode;
}

BDListIterator &BDListIterator::operator=(const BDListIterator &otherIter) {
    if (this == &otherIter)
        return *this;
    currNode = otherIter.currNode;
    return *this;
}

int &BDListIterator::operator*() const { return currNode->data; }

int BDListIterator::operator->() const { return currNode->data; }

bool BDListIterator::operator==(const BDListIterator &otherIter) const { return currNode == otherIter.currNode; }

bool BDListIterator::operator!=(const BDListIterator &otherIter) const { return currNode != otherIter.currNode; }

BDList::Node::Node() {
    prev = next = nullptr;
    data = 0;
}