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
    int heightL = 0;
    int heightR = 0;

    if (m_left != NULL) heightL = m_left->height;
    if (m_right != NULL) heightR = m_right->height;

    height = max(heightL, heightR)+1;
}

template<typename T>
int tree_el<T>::bf()
{
    int heightL = 0;
    int heightR = 0;

    if (m_left != NULL) heightL = m_left->height;
    if (m_right != NULL) heightR = m_right->height;

    return heightR-heightL;
}

template<typename T>
tree_el<T>* tree_el<T>::RightRotation()
{
    tree_el<T> *y=m_left;
    m_left=y->m_right;
    y->m_right=this;
    this->fixheight();
    y->fixheight();
    return y;
}

template<typename T>
tree_el<T>* tree_el<T>::LeftRotation()
{
    tree_el<T> *x= m_right;
    m_right=x->m_left;
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
        if (m_right->bf()<0) m_right=m_right->RightRotation();
        return this->LeftRotation();
    }
    if (this->bf()==-2)
    {
        if (m_left->bf()>0) m_left=m_left->LeftRotation();
        return this->RightRotation();
    }
    return this;
}


template<typename T>
tree_el<T>* tree_el<T>::Insert(T k)
{
    if (!this) return new tree_el(k);
    if (k<m_data)
        m_left= m_left->Insert(k);
    else
        m_right=m_right->Insert(k);
    return this->Balance();
}


template<typename T>
void tree_el<T>::print_subtree(node_print_state_t* _root_state) {
    node_print_state_t* parent_state;
    if (_root_state != NULL) {
        printf(" ");
        node_print_state_t* s = _root_state;
        while (s->child_state != NULL) {
            printf(s->printing_last_child ? "  " : "| ");
            s = s->child_state;
        }
        parent_state = s;
        printf(parent_state->printing_last_child ? "L" : "+");
    } else {
        parent_state = NULL;
    }
    printf(">%i\n", m_data);

    if ((m_left != NULL) || (m_right != NULL)) { // если есть дети
        node_print_state_t s;
        if (parent_state != NULL) {
            parent_state->child_state = &s;
        } else {
            _root_state = &s;
        }
        s.child_state = NULL;

        // печатаем детей
        if (m_left != NULL) {
            s.printing_last_child = (m_right == NULL);
            m_left->print_subtree(_root_state);
        }
        if (m_right != NULL) {
            s.printing_last_child = true;
            m_right->print_subtree(_root_state);
        }

        if (parent_state != NULL) {
            parent_state->child_state = NULL;
        } else {
            _root_state = NULL;
        }
    }
}

template<typename T>
void tree_el<T>::map(T(*fk)(T))
{
    m_data = fk(m_data);

    if (m_right != NULL) m_right->map(fk);
    if (m_left != NULL) m_left->map(fk);
}


template<typename T>
void tree_el<T>::where(bool(*fk)(T),vector<T>& tree)
{
    if(fk(m_data))
        tree.push_back(m_data);

    if (m_right != NULL) m_right->where(fk,tree);
    if (m_left != NULL) m_left->where(fk,tree);
}

template<typename T>
bool tree_el<T>::equal(tree_el el) {
    if(m_data == el.m_data)
    {
        bool eqR = false;
        bool eqL = false;

        if((m_right != NULL)&&(el.m_right != NULL))
            bool eqR = m_right->equal(*el.m_right);

        if((m_left != NULL)&&(el.m_left != NULL))
            bool eqL = m_left->equal(*el.m_left);

        if (eqL && eqR) return true;
    }
    else return false;
}

template<typename T>
void tree_el<T>::reduce(T (*fk)(T,T), T& cont, T c, T min) {

    if (m_data == min)
        cont = fk(m_data,c);
    else{
        if (m_left != NULL) m_left->reduce (fk, cont, c, min);
        cont = fk(cont, m_data);
        if (m_right != NULL) m_right->reduce (fk, cont, c, min);
    }
}

template<typename T>
T tree_el<T>::min() {
    if (m_left != NULL) return m_left->min();
    else return m_data;
}
