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
    void map(T(*fk)(T));
    binary_tree<T> where (bool(*fk)(T));
    T reduce (T(*fk)(T,T),T c);
    string printPath(string path);
    string printLNR();
    void wareGraph(string path);
    binary_tree<T> getSubtree(T key);
    string GraphViz();
    void Balance();



    //redefining the standard operator
    bool operator==(binary_tree<T> treeE);



    //special methods
    vector<T> values();
    void print();
    void print_mod();
    T min();
};


#endif //TREE_BINARY_TREE_H