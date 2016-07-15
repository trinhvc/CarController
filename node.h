#pragma once
#include<cstddef>
#include<string>
using namespace std;
class Node
{
    private:
        string _text;
        Node* _nextNode;
    public:
        Node ();
        Node (string text);
        ~Node();
        Node*  getNextNode();
        void   setNextNode(Node* node);
        void   setText(string text);
        string getText();
};
