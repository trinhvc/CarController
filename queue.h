#pragma once
#include "node.h"

template<typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
class Queue
{
    private:
        Node* _firstNode;
        Node* _lastNode;

    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(const Instruction& instruction);
        Instruction dequeue();
};

