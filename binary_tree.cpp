//
// Created by yaros on 23.05.2021.
//

#include "binary_tree.h"
#include <iostream>
#include <algorithm>

template<typename T>
binary_tree<T>::binary_tree(){
    m_root = nullptr;
    size = 0;
}

template<typename T>
binary_tree<T>::binary_tree(T key){
    m_root = new tree_el<T>(key);
    size = 1;
}

template<typename T>
tree_el<T>* binary_tree<T>::find(T key){//поиск значения
    tree_el<T>* curr = m_root;
    while(curr != NULL && curr->m_data != key){
        if(curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
    return curr;
}

template<typename T>
void val(tree_el<T> cur, vector<T> resp)
{
    if(cur != NULL)
    {
        resp.append(cur->m_data);
        if(cur->m_right!=NULL)
            val(cur->m_right, resp);

        if(cur->m_left!=NULL)
            val(cur->m_left, resp);
    }
}


template<typename T>
vector<T> binary_tree<T>::values()
{
    vector<T> resp = {};
    if (m_root == NULL)
        return resp;
    else
    {
        val(m_root,resp);
        qsort(resp);
        return resp;
    }
}


template<typename T>
void binary_tree<T>::print()
{
   m_root->print_subtree();
}

template<typename T>
void binary_tree<T>::insert(T key)
{
    m_root->Insert(key);
}