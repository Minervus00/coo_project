#include <iostream>

class ListNode;

class ListIterator;

class List {
private:
    ListNode* head;
    ListNode* tail;
public:
    List();
    ~List();
    void add(int value);
    ListIterator* createIterator();
};

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int value, ListNode* next = nullptr);
};

class ListIterator {
private:
    ListNode* current;
public:
    ListIterator(ListNode* head);
    bool hasNext();
    int next();
};

// définition des méthodes de la classe List
List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::add(int value) {
    if (tail == nullptr) {
        head = new ListNode(value);
		tail = head;
    } else {
        tail->next = new ListNode(value);
		tail = tail->next;
    }
}

ListIterator* List::createIterator() {
    return new ListIterator(head);
}

// définition des méthodes de la classe ListNode
ListNode::ListNode(int value, ListNode* next) : value(value), next(next) {}

// définition des méthodes de la classe ListIterator
ListIterator::ListIterator(ListNode* head) : current(head) {}

bool ListIterator::hasNext() {
    return current != nullptr;
}

int ListIterator::next() {
    int result = current->value;
    current = current->next;
    return result;
}

int main() {
    List list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(50);
    list.add(70);
    list.add(40);
    list.add(80);
    list.add(60);

    ListIterator* iterator = list.createIterator();
    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }

    delete iterator;

    return 0;
}
