#include <iostream>
#include "binary_tree.cpp"

int main() {
    binary_tree<int> tree;
    binary_tree<int> Tree;

    for(int i=0; i<70; i++)
        tree.insert(i);

    tree.print();

    tree.wareGraph("NRL");
    tree.Balance();
    cout << tree.GraphViz();
}
