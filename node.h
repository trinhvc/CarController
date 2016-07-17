#pragma once
#include <cstddef>
#include <string>
#include "instruction.h";
using namespace std;
class Node
{
    private:
    //Instruction _instruction;
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
