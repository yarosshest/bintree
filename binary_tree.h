//
// Created by yaros on 23.05.2021.
//

#ifndef TREE_BINARY_TREE_H
#define TREE_BINARY_TREE_H

#include "tree_el.cpp"
#include <vector>

using namespace std;

template<typename T>
class binary_tree {
private:
    tree_el<T>* m_root;
    int size;
public:
    //constructors
    binary_tree();
    binary_tree(T key);

    //standard methods
    void insert(T key);
    void delete_elem(T key);
    tree_el<T>* find(T key);
    //redefining the standard operator
    void print();

    //special methods
    vector<T> values();
};


#endif //TREE_BINARY_TREE_H