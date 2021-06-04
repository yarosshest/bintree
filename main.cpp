#include <iostream>
#include "binary_tree.cpp"

const int cloM = 9;
const string manipulations[cloM] = {"0. Exit",
                                    "1. Insert",
                                    "2. Delete",
                                    "3. Graph ware",
                                    "4. Saving to a string",
                                    "5. Extract subtree",
                                    "6. Print",
                                    "7. GraphViz",
                                    "8. Balance"};



int main() {
    binary_tree<int> tree;
    string pathware;
    string pathprint;
    binary_tree<int> tree_sub;
    bool flag = true;
    while (flag)
    {
        for (int i = 0; i <cloM;i++)
        {
            cout << manipulations[i] <<endl;
        }
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 0:
                flag = false;
                break;
            case 1:
                int a;
                cin >> a;
                tree.insert(a);
                break;
            case 2:
                int b;
                cin >> b;
                tree.delete_elem(b);
                break;
            case 3:
                cin >> pathware;
                tree.wareGraph(pathware);
                break;
            case 4:
                cin >> pathprint;
                cout << tree.printPath(pathprint)<<endl;
                break;
            case 5:
                int c;
                cin >> c;
                tree_sub = tree.getSubtree(c);
                tree_sub.print();
                tree_sub.GraphViz();
                break;
            case 6:
                tree.print();
                break;
            case 7:
                cout <<tree.GraphViz()<< endl;
                break;
            case 8:
                tree.Balance();
                break;
        }

    }
}
