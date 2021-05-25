//
// Created by yaros on 22.05.2021.
//

#ifndef TREE_TREE_EL_H
#define TREE_TREE_EL_H
#include <iostream>

using namespace std;
template<typename T>
class tree_el{
public:
    T m_data;
    tree_el* m_left;
    tree_el* m_right;
    int height;

    tree_el(T key);
    tree_el(T key,tree_el<T>* left,tree_el<T>* right);


    //redefining the standard operator
    friend ostream& operator<< (ostream &out, tree_el<T> &point);

    void fixheight();
    void print_subtree();
    int bf();
    tree_el<T>* LeftRotation();
    tree_el<T>* RightRotation();
    tree_el<T>* Balance();

    tree_el<T> *Insert(T k);
};


#endif //TREE_TREE_EL_H
