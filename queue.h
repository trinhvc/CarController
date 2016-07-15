#pragma once
#include<cstddef>
#include "node.h"
class Queue
{
    private:
        Node* _firstNode;
        Node* _lastNode;

    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(string text);
        string dequeue();
        string peek();
};

