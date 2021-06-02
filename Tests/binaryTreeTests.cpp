#include "gtest/gtest.h"
#include "../binary_tree.cpp"

TEST(binary_tree, map) {
    binary_tree<int> tree;
    binary_tree<int> treeT;

    for(int i=0; i<10; i++)
        tree.insert(i);
    for(int j=0; j<10; j++)
        treeT.insert(j*5);

    tree.map([](int data) {return data * 5;});
    bool res = tree == treeT;
    ASSERT_TRUE(res);
}

TEST(binary_tree, reduce) {
    binary_tree<int> tree;
    binary_tree<int> treeT;
    for(int i=1; i<11; i++)
    {
        tree.insert(i);
    }
    int res = tree.reduce([](int data1,int data2) {return data1 * data2;},1);
    ASSERT_EQ(res,3628800);
}

TEST(binary_tree, where) {
    binary_tree<int> tree;
    binary_tree<int> treeT;

    for(int i=0; i<10; i++)
        tree.insert(i);

    for(int i=0; i<5; i++)
        treeT.insert(i);

    binary_tree<int> where = tree.where([](int data) {return data <5;});
    treeT.print();
    where.print();
    bool res = where == treeT;
    ASSERT_TRUE(res);
}
