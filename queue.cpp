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
    return _firstNode ==NULL;
}

void Queue::enqueue(string text)
{
    Node* node = new Node(text);
    /*
        if  queue is empty
        then firstnode, lastnode point to newnode
        else update lastnode
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

string Queue::dequeue()
{
    string result;

    if(_firstNode!=NULL)
    {

        // store firstnode for later deleting
        Node *oldNode = _firstNode;

        result = oldNode->getText();

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

string Queue::peek()
{
    string result = _firstNode->getText();
    return result;
}
