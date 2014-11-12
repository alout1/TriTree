#include <cstdlib>

#include "Node.h"
#include "Tree.h"

using namespace std;

int main(int argc, char** argv) {
    int max_depth;
    std::cout << "Max depth = ";
    std::cin >> max_depth;
    Tree tree(max_depth);
    tree.mark_inOrder();
    tree.traverse_preOrder();
    tree.printTree();
    tree.printMidLeaves();
    return 0;
}

