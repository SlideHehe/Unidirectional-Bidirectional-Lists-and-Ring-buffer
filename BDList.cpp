#include "BDList.h"

BDList::BDList() {
    head = tail = nullptr;
    count = 0;
}

BDList::BDList(const BDList& otherList) {
    head = tail = nullptr;
    count = 0;

    if (otherList.count > 0) {
        head = new Node();
        head->data = otherList.head->data;
        count++;

        Node* newNode, * currNode = head;

        for (Node* currOther = otherList.head->next; currOther != nullptr; currOther = currOther->next) {
            newNode = new Node();
            newNode->data = currOther->data;
            currNode->next = newNode;
            newNode->prev = currNode;
            currNode = currNode->next;
            count++;
        }
        tail = currNode;
        tail->next = nullptr;
    }
    else cerr << "List is empty";
}

BDList::~BDList() { delAll(); }

void BDList::print() {
    if (count > 0) {
        Node* currNode = head;
        int i = 0;

        while (currNode != nullptr) {
            cout << i+1 << ")" << currNode->data << " ";
            i++;
            currNode = currNode->next;
        }
        cout << endl;
    }
    else cerr << "List is empty";
}

void BDList::pushBegin(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;

    if (!head) {
        head = newNode;
        head->next = nullptr;
        tail = head;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
    }

    head = newNode;
    count++;

}

void BDList::pushEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        head->prev = nullptr;
        tail = head;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
    }

    tail = newNode;
    count++;

}

void BDList::insert(int data, int position) {
    if (position <= count) {
        Node* newNode = new Node();
        newNode->data = data;

        if (position == 0) pushBegin(data);
        else if (position == count) pushEnd(data);
        else if (position > 0 && position <= count / 2) {
            int currPos = 0;
            Node* currNode;

            for (currNode = head; currNode != nullptr && currPos != position; currNode = currNode->next, currPos++);

            if (currPos == position) {
                newNode->prev = currNode->prev;
                newNode->prev->next = newNode;
                currNode->prev = newNode;
                newNode->next = currNode;
            }

            count++;

        }
        else if (position < count - 1 && position > count / 2) {
            int currPos = count - 1;
            Node* currNode;

            for (currNode = tail; currNode != nullptr && currPos != position; currNode = currNode->prev, currPos--);

            if (currPos == position) {
                newNode->prev = currNode->prev;
                newNode->prev->next = newNode;
                currNode->prev = newNode;
                newNode->next = currNode;
            }

            count++;
        }

    }
    else cerr << "Such position doesn't exist";
}

int BDList::popBegin() {
    if (count > 0) {
        Node* tmp = head;

        if (head == tail)
            head = tail = nullptr;
        else {
            if (head->next)
                head = head->next;
            head->prev = nullptr;
        }

        int ret = tmp->data;
        delete tmp;
        count--;
        return ret;

    }
    else cerr << "List is empty";
}

int BDList::popEnd() {
    if (count > 0) {
        Node* tmp = tail;

        if (head == tail)
            head = tail = nullptr;
        else {
            if (tail->prev)
                tail = tail->prev;
            tail->next = nullptr;
        }

        int ret = tmp->data;
        delete tmp;
        count--;
        return ret;

    }
    else cerr << "List is empty";
}

int BDList::erase(int position) {
    if (count > 0) {
        if (position == 0) popBegin();
        else if (position == count - 1) popEnd();
        else if (position > 0 && position <= count / 2) {
            Node* tmp;
            int currPos = 0;

            for (tmp = head; tmp != nullptr && currPos != position; tmp = tmp->next, currPos++);

            if (currPos == position) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
            }

            int ret = tmp->data;
            delete tmp;
            count--;
            return ret;

        }
        else if (position < count - 1 && position > count / 2) {
            Node* tmp;
            int currPos = count - 1;

            for (tmp = tail; tmp != nullptr && currPos != position; tmp = tmp->prev, currPos--);

            if (currPos == position) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
            }

            int ret = tmp->data;
            delete tmp;
            count--;
            return ret;

        }
        else cerr << "Such position doesn't exist";

    }
    else cerr << "List is empty";
}

void BDList::delAll() {
    Node* tmp;

    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }

    tail = nullptr;
    count = 0;
}

BDList BDList::split(int value) {
    if (count > 0) {
        BDList newList;
        Node* currNode = head;
        int position = 0;

        while (currNode != nullptr) {
            if (currNode->data < value) {
                newList.pushEnd(currNode->data);
                currNode = currNode->next;
                erase(position);
            }
            else {
                position++;
                currNode = currNode->next;
            }
        }

        return newList;
    }
    else cerr << "Source list is empty";
}

void BDList::quickSort() {
    if (count > 0) {
        _quickSort(head, tail);
    }
    else cerr << "List is empty";
}

BDListIterator BDList::begin() const { return BDListIterator(head); }

BDListIterator BDList::end() const { return BDListIterator(tail); }

int BDList::getByHead(int position) const {
    if (count > 0 && position < count && position >= 0) {
        Node* tmp;
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
        Node* tmp;
        int currPos = 0;

        for (tmp = tail; tmp != nullptr && currPos != position; tmp = tmp->prev, currPos++);

        if (tmp != nullptr)
            return tmp->data;
    }
    cerr << "List is empty or entered number is greater than number of elements";
    return 0;
}

int BDList::getCount() const { return count; }

bool BDList::operator==(const BDList& otherList) const { return (count == otherList.count); }

bool BDList::operator!=(const BDList& otherList) const { return (count != otherList.count); }

bool BDList::operator>(const BDList& otherList) const { return (count > otherList.count); }

bool BDList::operator>=(const BDList& otherList) const { return (count >= otherList.count); }

bool BDList::operator<(const BDList& otherList) const { return (count < otherList.count); }

bool BDList::operator<=(const BDList& otherList) const { return (count <= otherList.count); }

BDList::Node* BDList::partition(Node* left, Node* right) {
    Node* pointer = left->prev;

    for (Node* i = left; i != right; i = i->next) {
        if (i->data <= right->data) {
            pointer = (pointer == nullptr) ? left : pointer->next;
            std::swap(pointer->data, i->data);
        }
    }

    pointer = (pointer == nullptr) ? left : pointer->next;
    std::swap(pointer->data, right->data);

    return pointer;
}

void BDList::_quickSort(Node* left, Node* right) {
    if (right != nullptr && left != right && left != right->next) {
        Node* pointer = partition(left, right);

        _quickSort(left, pointer->prev);
        _quickSort(pointer->next, right);
    }
}

BDListIterator::BDListIterator() { currNode = nullptr; }

BDListIterator::BDListIterator(BDList::Node* node) { currNode = node; }

BDListIterator::BDListIterator(const BDListIterator& otherIter) { currNode = otherIter.currNode; }

BDListIterator& BDListIterator::operator++() {
    if (currNode)
        currNode = currNode->next;
    return *this;
}

BDListIterator BDListIterator::operator++(int) {
    BDList::Node* oldNode = currNode;
    if (currNode)
        currNode = currNode->next;
    return oldNode;
}

BDListIterator& BDListIterator::operator--() {
    if (currNode)
        currNode = currNode->prev;
    return *this;
}

BDListIterator BDListIterator::operator--(int) {
    BDList::Node* oldNode = currNode;
    if (currNode)
        currNode = currNode->prev;
    return oldNode;
}

BDListIterator& BDListIterator::operator=(const BDListIterator& otherIter) {
    if (this == &otherIter)
        return *this;
    currNode = otherIter.currNode;
    return *this;
}

int& BDListIterator::operator*() const { return currNode->data; }

int BDListIterator::operator->() const { return currNode->data; }

bool BDListIterator::operator==(const BDListIterator& otherIter) const { return currNode == otherIter.currNode; }

bool BDListIterator::operator!=(const BDListIterator& otherIter) const { return currNode != otherIter.currNode; }

BDList::Node::Node() {
    prev = next = nullptr;
    data = 0;
}
