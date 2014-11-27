#ifndef NODE_H
#define	NODE_H

#include <iostream>

class Node
{
private:
    Node* Left;
    Node* Middle;
    Node* Right;
    char Mark;
    
public:    
    Node();
    ~Node(); 
    void visit();
    void mark(char c);
    friend class Tree;
}; // class Node

#endif	/* NODE_H */

