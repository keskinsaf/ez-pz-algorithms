#include <iostream>
#include "TwoThreeTree.hpp"

int main (int argc, char** argv){
    TwoThreeTree *my_tree = new TwoThreeTree(5, 3, 4);
    TwoThreeTree::printInorder(my_tree);
    std::cout << "\n\nSearch will be executed.\n" << '\n';
    TwoThreeTree::printSearchedElement( TwoThreeTree::search(my_tree, 2) );
    return 0;
}
