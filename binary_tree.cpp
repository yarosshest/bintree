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
    node_print_state_t* _root_state = NULL;
   m_root->print_subtree(_root_state);
}

template<typename T>
void binary_tree<T>::insert(T key)
{
    if (m_root == nullptr)
    {
        tree_el<T> *root = new tree_el(key);
        m_root = root;
    }
    else
        m_root = m_root->Insert(key);
}


template<typename T>
void binary_tree<T>::map(T(*fk)(T))
{
    m_root->map(fk);
}

template<typename T>
binary_tree<T> binary_tree<T>::where(bool(*fk)(T))
{
    vector<T> result;
    m_root->where(fk,result);
    int size = result.size();

    binary_tree<T> tree = *(new binary_tree<T>);
    for(int i=1; i<=size; i++)
        tree.insert(result.at(size-i));
    return tree;
}
template<typename T>
bool binary_tree<T>::operator==(binary_tree<T> treeE)
{
    bool result = false;
    result = m_root->equal(*treeE.m_root);
    return result;
}

template<typename T>
T binary_tree<T>::reduce(T (*fk)(T,T),T c) {
    T min = m_root->min();
    T cont;
    m_root->reduce(fk,cont,c,min);
    return cont;
}

template<typename T>
T binary_tree<T>::min() {
    return m_root->min();
}

template<typename T>
string binary_tree<T>::printPath(string path) {
    if(path.size()==3)
    {
        string result;*-
        m_root->printPath(result,path[0],path[1],path[2]);
        return result;
    }
}

template<typename T>
string binary_tree<T>::printLNR() {
    string result;
    m_root->printPath(result,'L','N','R');
    return result;
}

template<typename T>
void binary_tree<T>::wareGraph(string path) {
    vector<tree_el<T>*> leaf;
    m_root->warePath(leaf,path[0],path[1],path[2]);
    for(int i=0; i<leaf.size(); ++i)
    {
        if((leaf[i]->m_left == NULL)&&(i!=0))
        {
            leaf[i]->m_left = (leaf[i-1]);
            leaf[i]->left_tag = true;
        }
        if((leaf[i]->m_right == NULL)&&(i!=leaf.size()-1))
        {
            leaf[i]->m_right = (leaf[i+1]);
            leaf[i]->right_tag = true;
        }
    }
}

template<typename T>
binary_tree<T> binary_tree<T>::getSubtree(T key) {
    binary_tree<T> tree;
    tree.m_root = find(key);
    return tree;
}

template<typename T>
string binary_tree<T>::GraphViz() {
    string result;
    result.append("https://quickchart.io/graphviz?graph=digraph{");
    m_root->GraphViz(result);
    result.append("}");
    return  result;
}

template<typename T>
void binary_tree<T>::Balance() {
    m_root = m_root->reBalance();
}

template<typename T>
void binary_tree<T>::delete_elem(T key) {
    m_root = m_root->delete_elem(key);
}
