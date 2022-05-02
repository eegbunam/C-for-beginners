#include "BTree.h"
#include <iostream>


int main(){
    BTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);

    tree.print();

    //number of nodes in the tree
    std::cout << "Number of nodes: " << tree.size() << std::endl;
    
    return 0;

}