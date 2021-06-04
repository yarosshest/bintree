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
    bool res = where == treeT;
    ASSERT_TRUE(res);
}

TEST(binary_tree, pathNLR) {
    binary_tree<int> tree;

    for(int i=0; i<10; i++)
        tree.insert(i);

    string path = tree.printPath("NLR");
    ASSERT_EQ(path,"5,3,1,0,2,4,7,6,8,9");
}

TEST(binary_tree, pathLNR) {
    binary_tree<int> tree;

    for(int i=0; i<10; i++)
        tree.insert(i);

    string path = tree.printPath("LNR");
    ASSERT_EQ(path,"0,1,2,3,4,5,6,7,8,9");
}

TEST(binary_tree, printLNR) {
    binary_tree<int> tree;

    for(int i=0; i<10; i++)
        tree.insert(i);

    string path = tree.printLNR();
    ASSERT_EQ(path,"0,1,2,3,4,5,6,7,8,9");
}

TEST(binary_tree, pathLRN) {
    binary_tree<int> tree;

    for(int i=0; i<10; i++)
        tree.insert(i);

    string path = tree.printPath("LRN");
    ASSERT_EQ(path,"0,2,1,4,3,6,9,8,7,5");
}