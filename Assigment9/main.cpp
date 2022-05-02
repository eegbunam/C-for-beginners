#include "BinaryTree.h"
#include <iostream>
int main(){

    BinaryTree<int> tree;
    tree.create_first_node(1);
    tree.add_left(2);
    tree.add_right(3);

    
    std::cout << " Tree root val is: " << tree.get_root()->data << std::endl;
    std::cout << " Tree left val is: " << tree.get_left()->data << std::endl;
    std::cout << " Tree right val is: " << tree.get_right()->data << std::endl;
    
}