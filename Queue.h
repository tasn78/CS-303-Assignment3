#pragma once
// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

namespace TS{

    // Queue class of integers
    class Queue {
    private:
        struct Node {
            int data;
            Node* next;
        };

        Node* front;
        Node* rear;
        int size;

    public:
        Queue() : front(nullptr), rear(nullptr), size(0) {};
        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }
        void enqueue(int value);
        int dequeue();
        int getFront();
        bool isEmpty();
        int getSize();
        void print();
    };
};
#endif