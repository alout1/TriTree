#include "Tree.h"

using namespace std;

Tree::Tree(char nm,char mnm, int mxr)
{
	Screen=new char *[maxrow];
	for(int i=0;i<maxrow;i++)
		Screen[i]= new char[80];
    num = nm;
    maxrow = mxr;
    offset = 40;
    Root = nullptr;
    //====================
    MidLeaves = 0;
    srand(time(0));
    //====================
    Root = makeNode(0);
}

Tree::~Tree()
{
    delete Root;
}

Node* Tree:: makeNode(int depth)
{
    char x = 0;
    if (depth < maxrow)
    {
	//==============================================
        x = (depth < rand() % 4 + 1) && (num <= 'z');
    //============================================== 
    /*if (depth < maxrow)
    {
        cout<<"create node(depth = "<<depth<<")? : "; 
        cin >> x;
    } */
    //============================================== 
    }
    
    Node* node = nullptr;
	if((x != 0 || x == 'y') && x!= 'n')
	{
		node = new Node;
		node->Mark = 'Q';
		node->Left = makeNode(depth + 1);
		node->Middle = makeNode(depth + 1);
		node->Right = makeNode(depth + 1);
	}
	return node;
}

void Tree::printTree()
{
    for(int i = 0; i < maxrow; ++i)
        for (int j = 0; j < 80; ++j)
            Screen[i][j] = '.';
    
    outNodes(Root, 1, offset);
    
	for(int i = 0; i < maxrow; i++)
        cout<<'\n'<<Screen[i];
    cout<<'\n';
    
}

void Tree::outNodes(Node *node, int r, int c)
{
	if(r && c && (c<80))
		Screen[r-1][c-1] = node->Mark;
	if(r<maxrow)
	{
		if(node->Left)
			outNodes(node->Left, r+1, c-(offset>>r));
		if(node->Middle)
			outNodes(node->Middle, r+1, c);
		if(node->Right)
			outNodes(node->Right, r+1, c+(offset>>r) - 2);
	}
}

void Tree::traversePreOrder()
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

void Tree::markInOrder()
{
    inorderMarking(Root);
}

void Tree::inorderMarking(Node *node)
{
    if(node!= nullptr) 
    {
        inorderMarking(node->Left);
        node->mark(num++);
        inorderMarking(node->Middle);
        inorderMarking(node->Right);
    }
}