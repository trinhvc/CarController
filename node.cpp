#include "node.h"

Node::Node()
{
    _nextNode = NULL;
}

Node::~Node()
{
    _text.clear();
    _nextNode = NULL;
}

Node::Node(string text)
{
    _text = text;
    _nextNode = NULL;
}

void Node::setText(string text)
{
    _text = text;
}

string Node::getText()
{
    return _text;
}

void Node::setNextNode(Node* node)
{
    _nextNode = node;
}

Node* Node::getNextNode()
{
    return _nextNode;
}
