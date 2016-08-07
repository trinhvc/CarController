#include "queue.h"
#include <string>

using namespace std;

Queue::Queue()
{
    _firstNode = NULL;
    _lastNode = NULL;
}

Queue::~Queue()
{
    Node* x;
    while(_firstNode!=NULL)
    {
        x = _firstNode;
        _firstNode = _firstNode->getNextNode();
        delete x;
    }
    _lastNode = NULL;
}

bool Queue::isEmpty()
{
    return _firstNode == NULL;
}

void Queue::enqueue(const Instruction &instruction)
{
    Instruction* newIns = new Instruction(instruction);
    Node* node = new Node(newIns);
    /*
        if  queue is empty
        then firstnode, lastnode point to newnode
        else update lastnoded
    */
    if(_lastNode==NULL)
    {
        _firstNode = node;
        _lastNode = node;
    }
    else
    {
        _lastNode->setNextNode(node);
        _lastNode = node;
    }
}

Instruction Queue::dequeue()
{
    Instruction result;

    if(_firstNode!=NULL)
    {

        // store firstnode for later deleting
        Node *oldNode = _firstNode;

        result = *oldNode->getInstruction();

        // update first node
        _firstNode = _firstNode->getNextNode();


        delete oldNode;

        // update lastnode if queue is empty
        if (_firstNode == NULL)
        {
            _lastNode = NULL;
        }

    }

    return result;
}
