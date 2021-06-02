#include <iostream>
#include "binary_tree.cpp"

int main() {
    binary_tree<int> tree;
    binary_tree<int> treeT;

    for(int i=0; i<10; i++)
        tree.insert(i);

    binary_tree<int> where = tree.where([](int data) {return data <5;});
    where.print();
}

