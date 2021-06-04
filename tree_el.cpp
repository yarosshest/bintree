#include "tree_el.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T>
tree_el<T>::tree_el(T key)
{
    m_data = key;
    height = 1;
    m_left = NULL;
    m_right = NULL;
    left_tag = false;
    right_tag = false;
}

template<typename T>
tree_el<T>::tree_el()
{
    m_data = NULL;
    height = NULL;
    m_left = NULL;
    m_right = NULL;
    left_tag = false;
    right_tag = false;
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

    if ((m_left != NULL)&&(!left_tag)) heightL = m_left->height;
    if ((m_right != NULL)&&(!right_tag)) heightR = m_right->height;

    height = max(heightL, heightR)+1;
}

template<typename T>
int tree_el<T>::bf()
{
    int heightL = 0;
    int heightR = 0;

    if ((m_left != NULL)&&(!left_tag)) heightL = m_left->height;
    if ((m_right != NULL)&&(!right_tag)) heightR = m_right->height;

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

    if (((m_left != NULL)&&(!left_tag)) || ((m_right != NULL)&&(!right_tag))) { // если есть дети
        node_print_state_t s;
        if (parent_state != NULL) {
            parent_state->child_state = &s;
        } else {
            _root_state = &s;
        }
        s.child_state = NULL;

        // печатаем детей
        if ((m_left != NULL)&&(!left_tag)) {
            s.printing_last_child = (m_right == NULL);
            m_left->print_subtree(_root_state);
        }
        if ((m_right != NULL)&&(!right_tag)) {
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

    if ((m_right != NULL)&&(!right_tag)) m_right->map(fk);
    if ((m_left != NULL)&&(!left_tag)) m_left->map(fk);
}


template<typename T>
void tree_el<T>::where(bool(*fk)(T),vector<T>& tree)
{
    if(fk(m_data))
        tree.push_back(m_data);

    if ((m_right != NULL)&&(!right_tag)) m_right->where(fk,tree);
    if ((m_left != NULL)&&(!left_tag)) m_left->where(fk,tree);
}

template<typename T>
bool tree_el<T>::equal(tree_el el) {
    if(m_data == el.m_data)
    {
        bool eqR = false;
        bool eqL = false;

        if((((m_right != NULL)&&(!right_tag)))&&(el.m_right != NULL))
            bool eqR = m_right->equal(*el.m_right);

        if(((m_left != NULL)&&(!left_tag))&&(el.m_left != NULL))
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
        if ((m_left != NULL)&&(!left_tag)) m_left->reduce (fk, cont, c, min);
        cont = fk(cont, m_data);
        if ((m_right != NULL)&&(!right_tag)) m_right->reduce (fk, cont, c, min);
    }
}

template<typename T>
T tree_el<T>::min() {
    if ((m_left != NULL)&&(!left_tag)) return m_left->min();
    else return m_data;
}

template<typename T>
void tree_el<T>::printPath(string &result, char first, char second, char third) {
    wayPrintPath(result,first,first,second,third);
    wayPrintPath(result,second,first,second,third);
    wayPrintPath(result,third,first,second,third);
}

template<class T>
string toString(const T &value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

template<typename T>
void tree_el<T>::wayPrintPath(string &result, char command,char first,char second ,char third) {
    string res;

    switch (command)
    {
        case 'N':
            if(result == "")
                res =toString(m_data);
            else
                res = ',' + toString(m_data);
            result.append(res);
            break;
        case 'R':
            if((m_right != NULL)&&(!right_tag))
                m_right->printPath(result,first,second,third);
            break;

        case 'L':
            if((m_left != NULL)&&(!left_tag))
                m_left->printPath(result,first,second,third);
            break;


    }
}

template<typename T>
void tree_el<T>::warePath(vector<tree_el<T>*>& leaf,char first,char second ,char third) {
    wayWarePath(leaf,first,first,second,third);
    wayWarePath(leaf,second,first,second,third);
    wayWarePath(leaf,third,first,second,third);
}

template<typename T>
void tree_el<T>::wayWarePath(vector<tree_el<T>*>& leaf, char command, char first, char second, char third) {
    switch (command)
    {
        case 'N':
            leaf.push_back(this);
            break;
        case 'R':
            if((m_right != NULL)&&(!right_tag))
                m_right->warePath(leaf,first,second,third);
            break;

        case 'L':
            if((m_left != NULL)&&(!left_tag))
                m_left->warePath(leaf,first,second,third);
            break;
    }
}

template<typename T>
void tree_el<T>::GraphViz(string &result) {
    if((m_left != NULL)&&(!left_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_left->m_data);
        result.append(data1+"->"+data2+";");
    }
    if((m_right != NULL)&&(!right_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_right->m_data);
        result.append(data1+"->"+data2+";");
    }
    if((m_left != NULL)&&(left_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_left->m_data);
        result.append(data1+"->"+data2 +" [style=dotted];");
    }
    if((m_right != NULL)&&(right_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_right->m_data);
        result.append(data1+"->"+data2 + " [style=dotted];");
    }
    if((m_right != NULL)&&(!right_tag))
        m_right->GraphViz(result);
    if((m_left != NULL)&&(!left_tag))
        m_left->GraphViz(result);
}

template<typename T>
tree_el<T> *tree_el<T>::reBalance() {
    if((m_left != NULL)&&(!left_tag))
        m_left = m_left->Balance();
    if((m_right != NULL)&&(!right_tag))
        m_right = m_right->Balance();
    if((m_left != NULL)&&(!left_tag))
        m_left = m_left->Balance();
    if((m_right != NULL)&&(!right_tag))
        m_right->reBalance();
    if((m_left != NULL)&&(!left_tag))
        m_left->reBalance();
    return Balance();
}
template<typename T>
tree_el<T> *SearchMin(tree_el<T> *x)
{
    if (x->m_left) return SearchMin(x->m_left);
    else return x;
}
template<typename T>
tree_el<T> *DeleteMin(tree_el<T> *x)
{
    if (x->m_left==0) return x->m_left;
    x->m_left=DeleteMin(x->m_left);
    return x->Balance();
}

template<typename T>
tree_el<T>* tree_el<T>::delete_elem(T key) {
    if ((key<m_data)&&(m_left != NULL)&&(!left_tag)) m_left = m_left->delete_elem(key);
    else if ((key>m_data)&&(m_right != NULL)&&(!right_tag)) m_right=m_right->delete_elem(key);
    else
    {
        tree_el<T> *y=m_left;
        tree_el<T> *z=m_right;
        delete this;
        if (!z) return y;
        tree_el<T>* min=SearchMin(z);
        min->m_right=DeleteMin(z);
        min->m_left=y;
        return min->Balance();
    }
    return this->Balance();
}
