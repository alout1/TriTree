#ifndef TREE_H
#define	TREE_H

#include "Node.h"

#include <cmath>
#include <cstdlib>

using namespace std;

class Node;

class Tree {
private:
    int MidLeaves; // То, что надо посчитать - "количество средних листьев"
    Node* Root;
    char num, maxnum;
    int maxrow, offset;
    char** Screen;

    void preOrderTraverse(Node* node);
    void inorderMarking(Node* node);
    Node* makeNode(int depth);
    void outNodes(Node* node,int r, int c);

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

public:
    Tree(char nm, char mnm, int mxr);
    ~Tree();

    void printMidLeaves() {std::cout << "Middle leaves = " << MidLeaves << '\n';}
    void printTree();
    void traversePreOrder();
    void markInOrder();

}; // class Tree

#endif	/* TREE_H */

