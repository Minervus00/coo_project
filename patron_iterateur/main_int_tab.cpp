#include <iostream>

class IntegerArrayIterator; // déclaration anticipée de la classe IntegerArrayIterator

class IntegerArray {
private:
    int* data;
    int size;
public:
    IntegerArray(int size);
    ~IntegerArray();
    int getItem(int index);
    void setItem(int index, int value);
    int getSize();
    IntegerArrayIterator* createIterator();
};

// définition de la classe IntegerArrayIterator
class IntegerArrayIterator {
private:
    IntegerArray* array;
    int index;
public:
    IntegerArrayIterator(IntegerArray* array);
    bool hasNext();
    int next();
};

// définition des méthodes de la classe IntegerArray
IntegerArray::IntegerArray(int size) : size(size) {
    data = new int[size];
}

IntegerArray::~IntegerArray() {
    delete[] data;
}

int IntegerArray::getItem(int index) {
    return data[index];
}

void IntegerArray::setItem(int index, int value) {
    data[index] = value;
}

int IntegerArray::getSize() {
    return size;
}

IntegerArrayIterator* IntegerArray::createIterator() {
    return new IntegerArrayIterator(this);
}

// définition des méthodes de la classe IntegerArrayIterator
IntegerArrayIterator::IntegerArrayIterator(IntegerArray* array) : array(array), index(0) {}

bool IntegerArrayIterator::hasNext() {
    return (index < array->getSize());
}

int IntegerArrayIterator::next() {
    int result = array->getItem(index);
    index++;
    return result;
}

int main() {
    IntegerArray array(7);
    array.setItem(0, 10);
    array.setItem(1, 20);
    array.setItem(2, 30);
    array.setItem(3, 40);
    array.setItem(4, 50);
    array.setItem(5, 60);
    array.setItem(6, 70);

    IntegerArrayIterator* iterator = array.createIterator();
    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }

    delete iterator;

    return 0;
}
