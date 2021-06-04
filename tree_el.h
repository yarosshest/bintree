//
// Created by yaros on 22.05.2021.
//

#ifndef TREE_TREE_EL_H
#define TREE_TREE_EL_H
#include <iostream>
#include <vector>
using namespace std;

struct node_print_state_t {
    node_print_state_t* child_state;

    bool printing_last_child;
};

template<typename T>
class tree_el{
public:
    T m_data;
    tree_el* m_left;
    tree_el* m_right;
    bool left_tag;
    bool right_tag;
    int height;

    tree_el(T key);
    tree_el();
    tree_el(T key,tree_el<T>* left,tree_el<T>* right);

    void map(T(*fk)(T));
    void where(bool(*fk)(T),vector<T>& tree);
    void reduce (T(*fk)(T,T),T& cont,T c, T min);
    void printPath(string& result,char first,char second ,char third);
    void warePath(vector<tree_el<T>*>&,char first,char second ,char third);
    tree_el<T>* delete_elem(T key);


    //redefining the standard operator
    friend ostream& operator<< (ostream &out, tree_el<T> &point);

    void fixheight();
    void print_subtree(node_print_state_t* _root_state);
    int bf();
    void wayPrintPath(string& result,char command,char first,char second ,char third);
    void wayWarePath(vector<tree_el<T>*>&,char command,char first,char second ,char third);
    tree_el<T>* LeftRotation();
    tree_el<T>* RightRotation();
    tree_el<T>* Balance();
    tree_el<T>* reBalance();
    void GraphViz(string& result);

    bool equal(tree_el el);

    tree_el<T> *Insert(T k);
    T min();
};


#endif //TREE_TREE_EL_H
