#include <cstdlib>

#include "Node.h"
#include "Tree.h"

using namespace std;

int main(int argc, char** argv) {
    int max_depth;
    Tree tree('a', 'z', 5);
    tree.markInOrder();
    tree.traversePreOrder();
    tree.printMidLeaves();
    tree.printTree();
    return 0;
}

