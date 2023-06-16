#include <iostream>
#include "BinaryTree.h"
using namespace std;

class maxDepth : public BinaryTree {
public:
    int max_Depth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }

        return 1 + max(max_Depth(root->left), max_Depth(root->right));
    }

};

int main() {
    maxDepth tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);

    int maxdepth = tree.max_Depth(tree.getRoot());

    cout << "MaxDepth: " << maxdepth;
}