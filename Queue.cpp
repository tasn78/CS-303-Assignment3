// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#include "Queue.h"

using namespace TS;
   
void Queue::enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty!" << std::endl;
        return -1;
    }

    Node* temp = front;
    int value = temp->data;

    front = front->next;
    delete temp;

    size--;

    if (isEmpty()) {
        rear = nullptr;
    }

    return value;
}

int Queue::getFront() {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty" << std::endl;
        return -1;
    }

    return front->data;
}

bool Queue::isEmpty() {
    return size == 0;
}

int Queue::getSize() {
    return size;
}

void Queue::print() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    Node* temp = front;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
;