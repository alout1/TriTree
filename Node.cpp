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

int level = 0;
void Node::print()
{
    for (int ix = 0; ix < level; ++ix) std::cout << "   ";
        std::cout << Mark << std::endl;
        ++level;
        if (Left)
        {
            Left->print();
            --level;
        }
        if (Middle)
        {
            Middle->print();
            --level;
        }
        if (Right)
        {
            Right->print();
            --level;
        }
}