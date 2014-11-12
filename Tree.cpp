#include "Tree.h"

using namespace std;
using namespace std::chrono;

Tree::Tree(int max_depth)
{
    MidLeaves = 0;
    UniqueMark = 'A';
    int max_nodes = (pow(3,max_depth)-1) / 2; // количество элементов в полном дереве 
    int branches = (pow(3,max_depth-1)-1) / 2;  // количество веток / не-листьев
    // a1*(q^n - 1) / (q - 1) - сумма геометрической прогрессии
    
    NewTree = new Node*[max_nodes + 1];
    for (int i = 0; i < max_nodes; ++i)
        NewTree[i] = new Node();
    Root = NewTree[0];
    
    for (int i = 0; i < branches; ++i)
    {
        NewTree[i]->Left = NewTree[3 * i + 1];
        NewTree[i]->Middle = NewTree[3 * i + 2];
        NewTree[i]->Right = NewTree[3 * i + 3];
    }
    
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    for (int i = branches; i >= 0; --i)
    {
        if (NewTree[i] != nullptr)
        {
            int Decision = generator() % (max_depth + 2);
            switch(Decision)
            {
                case 0: 
                {
                    if (NewTree[i]->Left)
                    {
                        delete NewTree[i]->Left; 
                        NewTree[i]->Left = nullptr; 
                        
                    }
                    break;
                }
                case 1: 
                {

                    if (NewTree[i]->Middle)
                    {
                        delete NewTree[i]->Middle; 
                        NewTree[i]->Middle = nullptr; 
                        
                    }
                    break;
                }
                case 2: 
                {
                    if (NewTree[i]->Right)
                    {
                        delete NewTree[i]->Right; 
                        NewTree[i]->Right = nullptr; 
                        
                    }
                    break;
                }
                default: { /* do nothing */ }
            }
        }
    }
}

Tree::~Tree()
{
    delete Root;
    delete[] NewTree; 
}

void Tree::traverse_preOrder()
{
    cout << "preOrder Traversal: ";
    preOrderTraverse(Root);
    cout << endl;
}

void Tree::preOrderTraverse(Node *node)
{
    if(node!= nullptr)
    {
        /////////////////////////////////
        if (node->Middle)
            if (node->Middle->Left == nullptr &&
                node->Middle->Middle == nullptr &&
                node->Middle->Right == nullptr)
                    MidLeaves++; 
        ///////////////////////////////////////
        node->visit();
        preOrderTraverse(node->Left);
        preOrderTraverse(node->Middle);
        preOrderTraverse(node->Right);
        
    }
}

void Tree::mark_inOrder()
{
    inorderMarking(Root);
}

void Tree::inorderMarking(Node *node)
{
    if(node!= nullptr)
    {
        inorderMarking(node->Left);
        node->mark(getNextMark());
        inorderMarking(node->Middle);
        inorderMarking(node->Right);
        
    }
}