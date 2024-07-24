#include <iostream>

class StackNode;

class Stack {
private:
    StackNode* head;
public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    void print();
};

class StackNode {
public:
    int value;
    StackNode* next;
    StackNode(int value, StackNode* next = nullptr);
};

// définition des méthodes de la classe Stack
Stack::Stack() : head(nullptr) {}

Stack::~Stack() {
    while (head != nullptr) {
        StackNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Stack::push(int value) {
    if (head == nullptr) {
        head = new StackNode(value);
    } else {
		StackNode* temp = new StackNode(value);
        temp->next = head;
		head = temp;
    }
}

void Stack::pop() {
	if (head != nullptr) {
		StackNode* temp = head;
		head = head->next;
		std::cout << temp->value << '\n';
		delete temp;
	}
}

void Stack::print() {
	StackNode* current = head;
    while (current) {
        std::cout << current->value;
		current = current->next;
		if (current) {
			std::cout << '-';
		}
    }
	std::cout << '\n';
}

// définition des méthodes de la classe StackNode
StackNode::StackNode(int value, StackNode* next) : value(value), next(next) {}


int main() {
    Stack Stack;
    Stack.push(1);
    Stack.push(2);
    Stack.push(3);
    Stack.push(4);
    Stack.push(5);
    Stack.push(6);
    Stack.push(7);
    Stack.push(8);

	Stack.print();

	Stack.pop();
	Stack.pop();
	Stack.push(0);

	Stack.print();

    return 0;
}
