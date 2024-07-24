#include <iostream>

class QueueNode;

class Queue {
private:
    QueueNode* head;
    QueueNode* tail;
public:
    Queue();
    ~Queue();
    void enqueue(int value);
    void dequeue();
    void print();
};

class QueueNode {
public:
    int value;
    QueueNode* next;
    QueueNode(int value, QueueNode* next = nullptr);
};

// définition des méthodes de la classe Queue
Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (head != nullptr) {
        QueueNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::enqueue(int value) {
    if (head == nullptr) {
        head = new QueueNode(value);
		tail = head;
    } else {
		QueueNode* temp = new QueueNode(value);
        tail->next = temp;
		tail = temp;
    }
}

void Queue::dequeue() {
	if (head != nullptr) {
		QueueNode* temp = head;
		head = head->next;
		std::cout << temp->value << '\n';
		delete temp;
	}
}

void Queue::print() {
	QueueNode* current = head;
    while (current) {
        std::cout << current->value;
		current = current->next;
		if (current) {
			std::cout << '-';
		}
    }
	std::cout << '\n';
}

// définition des méthodes de la classe QueueNode
QueueNode::QueueNode(int value, QueueNode* next) : value(value), next(next) {}


int main() {
    Queue Queue;
    Queue.enqueue(1);
    Queue.enqueue(2);
    Queue.enqueue(3);
    Queue.enqueue(4);
    Queue.enqueue(5);
    Queue.enqueue(6);
    Queue.enqueue(7);
    Queue.enqueue(8);

	Queue.print();

	Queue.dequeue();
	Queue.dequeue();
	Queue.enqueue(0);

	Queue.print();

    return 0;
}
