#include "Unidirectional_list.h"

Unidirectional_list::Unidirectional_list() {
    head = nullptr;
    count = 0;
}

Unidirectional_list::Unidirectional_list(const Unidirectional_list& otherlist) {
    head = nullptr;
    count = 0;

    if (otherlist.count > 0) {
        head = new Node();
        head->data = otherlist.head->data;
        count++;

        Node *lastnode=head;

        for (Node* currother = otherlist.head->next; currother != nullptr; currother = currother->next) {
            Node *newnode = new Node;
            lastnode->next = newnode;
            newnode->data = currother->data;
            lastnode = newnode;
            count++;
        }

        lastnode->next = nullptr;
    }
    else cerr << "List is empty\n";
}

Unidirectional_list::~Unidirectional_list() { delAll(); }

void Unidirectional_list::print() {
    if (count > 0) {
        Node* currNode = head;

        for (int i = 1; i <= count; i++) {
            cout << i << ")" << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
    else cerr << "List is empty\n";
}

void Unidirectional_list::push(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (count != 0) {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    else {
        head = newNode;
    }
    count++;

}

void Unidirectional_list::push_first(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;

    head = newNode;

    count++;

}

void Unidirectional_list::insert(int data, int position) {
    if (position <= count && position > 0) {
        Node* newNode = new Node();
        newNode->data = data;

        if (position != 1) {
            Node* currNode = head;
            for (int i = 1; i < position - 1; i++) {
                currNode = currNode->next;
            }
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }
    else cerr << "Such position doesn't exist\n";
}

int Unidirectional_list::pop() {
    if (count > 0) {
        Node* lastNode = head;
        int d=0;

        if (count != 1) {
            while ((lastNode->next)->next != nullptr) {
                lastNode = lastNode->next;
            }
            d = (lastNode->next)->data;
            delete lastNode->next;
            lastNode->next = nullptr;
        }
        else {
            d = head->data;
            delete head;
            head = nullptr;
        }
        count--;
        return d;
    }
    else cerr << "List is empty\n"; return 0;
}

int Unidirectional_list::pop_first() {
    if (count > 0) {
        Node* delNode = head;
        int d = delNode->data;
        head = delNode->next;
        delete delNode;
        
        count--;
        return d;
    }
    else cerr << "List is empty\n"; return 0;
}

int Unidirectional_list::erase(int position) {
    if (count > 0) {
        if(count >= position && position > 0) {
            Node* lastdelNode = head;
            int d;

            if (position == 1) {
                head = lastdelNode->next;
                d = head->data;
                delete lastdelNode;
            }
            else {
                for (int i = 1; i < position - 1; i++) {
                    lastdelNode = lastdelNode->next;
                }
                Node* delNode = lastdelNode->next;
                lastdelNode->next = delNode->next;
                d = delNode->data;
                delete delNode;
            }
            count--;
            return d;
        }
        else cerr << "Such position doesn't exist\n"; return 0;
    }
    else cerr << "List is empty\n"; return 0;
}

void Unidirectional_list::delAll() {
    Node* delNode = head;

    while (delNode != nullptr) {
        Node* nextNode = delNode->next;
        delete delNode;
        delNode = nextNode;
    }

    head = nullptr;
    count = 0;
}


Iterator_uni Unidirectional_list::begin() const { 
    return Iterator_uni(head); 
}

Iterator_uni Unidirectional_list::end() const { 
    Node* Node = head;

    while(Node->next != nullptr) {
        Node = Node->next;
    }
    return Iterator_uni(Node); 
}


int Unidirectional_list::getCount() const { return count; }

void Unidirectional_list::sort_b(int *a, int left, int right)
{
    int i = left, j = right;
    float x = a[(left + right) / 2];
    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            if (i < j)
            {
                std::swap(a[i], a[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < right)
        sort_b(a, i, right);

    if (left < j)
        sort_b(a, left, j);
}

void Unidirectional_list::Xoar() {
    Unidirectional_list::Node* currNode = Unidirectional_list::head;
    int* a = new int[count];

    for (int i = 0; i < count; i++) {
        a[i] = currNode->data;
        currNode = currNode->next;
    }

    Unidirectional_list::sort_b(a, 0, count-1);

    currNode = Unidirectional_list::head;
    for (int i = 0; i < count; i++) {
        currNode->data = a[i];
        currNode = currNode->next;
    }
}

Unidirectional_list Unidirectional_list::Div_list(int d) {
    Unidirectional_list *New_list = new Unidirectional_list;
    
    Unidirectional_list::Node* currNode = this->head;
    for (int i = 0; currNode != nullptr;) {
        //printf("%i", currNode->data);
        if (currNode != nullptr) {
            if (currNode->data >= d) {
                New_list->Unidirectional_list::push(currNode->data);

                
                this->Unidirectional_list::erase(i+1);
                currNode = head;
                for (int j = 0; j < i; j++) {
                    currNode = currNode->next;
                }

            }
            else {
                currNode = currNode->next;
                i++;
            }
        }
    }

    return *New_list;
}

bool Unidirectional_list::operator==(const Unidirectional_list& otherlist) const { return (count == otherlist.count); }

bool Unidirectional_list::operator!=(const Unidirectional_list& otherlist) const { return (count != otherlist.count); }

bool Unidirectional_list::operator>(const Unidirectional_list& otherlist) const { return (count > otherlist.count); }

bool Unidirectional_list::operator>=(const Unidirectional_list& otherlist) const { return (count >= otherlist.count); }

bool Unidirectional_list::operator<(const Unidirectional_list& otherlist) const { return (count < otherlist.count); }

bool Unidirectional_list::operator<=(const Unidirectional_list& otherlist) const { return (count <= otherlist.count); }

Iterator_uni::Iterator_uni() { 
    currNode = nullptr; 
}

Iterator_uni::Iterator_uni(Unidirectional_list::Node* Node) { 
    currNode = Node; 
}

Iterator_uni::Iterator_uni(const Iterator_uni& otheriter) { currNode = otheriter.currNode; }

Iterator_uni& Iterator_uni::operator++() {
    if (currNode != nullptr and currNode->next != nullptr) {
        currNode = currNode->next;
    }
    else {
        cerr << "Such position doesn't exist\n";
    }
    return *this;
}

Iterator_uni Iterator_uni::operator++(int) {
    Unidirectional_list::Node* oldNode = currNode;
    if (currNode != nullptr and currNode->next != nullptr) {
        currNode = currNode->next;
    }
    else {
        cerr << "Such position doesn't exist\n";
    }
    return oldNode;
}

Iterator_uni& Iterator_uni::operator=(const Iterator_uni& otheriter) {
    if (this == &otheriter)
        return *this;
    currNode = otheriter.currNode;
    return *this;
}

int& Iterator_uni::operator*() const { return currNode->data; }

int Iterator_uni::operator->() const { return currNode->data; }

bool Iterator_uni::operator==(const Iterator_uni& otheriter) const { return currNode == otheriter.currNode; }

bool Iterator_uni::operator!=(const Iterator_uni& otheriter) const { return currNode != otheriter.currNode; }
