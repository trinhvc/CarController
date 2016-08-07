#include "node.h"
#include "instruction.h"

Node::Node()
{
    _instruction = NULL;
    _nextNode = NULL;
}

Node::Node(Instruction* instruction)
{
    _instruction = instruction;
    _nextNode = NULL;
}

Node::~Node()
{
    if(_instruction!=NULL)
    {
        delete _instruction;
    }
    _nextNode = NULL;
}

void Node::setInstruction(Instruction* instruction)
{
    _instruction = instruction;
}

Instruction* Node::getInstruction()
{
    return _instruction;
}

void Node::setNextNode(Node* node)
{
    _nextNode = node;
}

Node* Node::getNextNode()
{
    return _nextNode;
}
