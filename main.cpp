#include <iostream>
#include "binary_tree.cpp"

int main() {
    binary_tree<int> tree;
    for(int i=0; i<10; i++)
        tree.insert(i);
//        tree.insert(i);
    tree.print();
}
