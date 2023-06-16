#include<iostream>
#include "BinaryTree.h"
using namespace std;


class isSameTree{
public:
    bool _isSameTree(TreeNode* tree1, TreeNode* tree2){
        if (tree1 == nullptr && tree2 == nullptr){
            return true;
        }

        if (tree1 == nullptr || tree2 == nullptr){
            return false;
        }

        if (tree1->data == tree2->data){
            return _isSameTree(tree1->left, tree2->left) && _isSameTree(tree2->right, tree2->right);
        }

        return false;
    }
};

int main() {
    BinaryTree tree1;
    BinaryTree tree2;

    tree1.insert(4);
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(3);
    tree1.insert(7);
    tree1.insert(9);
    tree1.insert(6);

    tree2.insert(4);
    tree2.insert(2);
    tree2.insert(1);
    // for true
    tree2.insert(3);
    tree2.insert(7);
    tree2.insert(9);
    tree2.insert(6);

    isSameTree myObj;

    bool res = myObj._isSameTree(tree1.getRoot(), tree2.getRoot());
    cout << (res ? "true": "false");

}
