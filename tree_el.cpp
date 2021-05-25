#include "tree_el.h"
#include <iostream>
using namespace std;

template<typename T>
tree_el<T>::tree_el(T key)
{
    m_data = key;
    height = 1;
    m_left = NULL;
    m_right = NULL;
}


template<typename T>
tree_el<T>::tree_el(T key,tree_el<T>* left,tree_el<T>* right)
{
    m_data = key;
    m_left = left;
    m_right = right;
    height = max(left->height, right->height)+1;
}


template<typename T>
void tree_el<T>::fixheight()
{
    height = max(m_left->height, m_right->height)+1;
}

template<typename T>
void tree_el<T>::print_subtree()
{
    if(m_left != NULL)
        m_left->print_subtree();
//    cout << this;

    cout << m_data << "[" << height << "]"<<endl;

    if(m_right != NULL)
        m_right->print_subtree();
}

template<typename T>
int tree_el<T>::bf()
{
    return m_right->height-m_left->height;
}

template<typename T>
tree_el<T>* tree_el<T>::RightRotation()
{
    tree_el<T> *y=this->m_left;
    this->m_left=y->m_right;
    y->m_right=this;
    this->fixheight();
    y->fixheight();
    return y;
}

template<typename T>
tree_el<T>* tree_el<T>::LeftRotation()
{
    tree_el<T> *x= this->m_right;
    this->m_right=x->m_left;
    x->m_left=this;
    x->fixheight();
    this->fixheight();
    return x;
}

template<typename T>
ostream& operator <<(ostream &out, tree_el<T> point)
{
    out << point.m_data << " ";
}

template<typename T>
tree_el<T>* tree_el<T>::Balance()
{
    this->fixheight();
    if (this->bf()==2)
    {
        if (this->m_right->bf()<0) this->m_right=this->m_right->RightRotation();
        return this->LeftRotation();
    }
    if (this->bf()==-2)
    {
        if (this->m_left->bf()>0) this->m_left=this->m_left->LeftRotation();
        return this->RightRotation();
    }
    return this;
}


template<typename T>
tree_el<T>* tree_el<T>::Insert(T k)
{
    if (k<this->m_data) this->m_left= this->m_left->Insert(k);
    else this->m_right=this->m_right->Insert(k);
    return this->Balance();
}