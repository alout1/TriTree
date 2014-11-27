#include "Node.h"
#include "Tree.h"

Node::Node()
{
    Left = nullptr; 
    Middle = nullptr; 
    Right = nullptr; 
    Mark = 'Q';
    
}

Node::~Node()
{ 
    if (Left) 
        delete Left; 
    if (Middle) 
        delete Middle; 
    if (Right) 
        delete Right; 
}

void Node::mark(char c)
{
    Mark = c;
}

void Node::visit()
{
    std::cout << this->Mark << " ";
}