#ifndef TREE_H
#define	TREE_H

#include "Node.h"

#include <cmath>
#include <random>
#include <chrono>


class Node;


class Tree
{
private:
    int MidLeaves; // То, что надо посчитать - "количество средних листьев"
    char UniqueMark;
    Node** NewTree;
    Node* Root;
    
    char getNextMark() { if(UniqueMark == 'Z') UniqueMark = 'a'; return UniqueMark++; } 
    void preOrderTraverse(Node *node);
    void inorderMarking(Node* node);

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
    
public:
    Tree(int);
    ~Tree();
    void printMidLeaves() { std::cout << "Middle leaves = " << MidLeaves <<'\n'; }
    void printTree() { Root->print(); } // http://stackoverflow.com/a/18669747
    void traverse_preOrder();    
    void mark_inOrder();
    
}; // class Tree

#endif	/* TREE_H */

