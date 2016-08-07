#pragma once
#include "instruction.h"

class Node
{
    private:
        Instruction* _instruction;
        Node* _nextNode;
    public:
        Node ();
        Node (Instruction *instruction);
        ~Node();
        Node* getNextNode();
        void setNextNode(Node* node);
        void setInstruction(Instruction *instruction);
        Instruction* getInstruction();
};
