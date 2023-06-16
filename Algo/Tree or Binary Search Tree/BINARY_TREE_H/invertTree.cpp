#include <iostream>
#include "BinaryTree.h"
using namespace std;

class invertTree : public BinaryTree {
public:
    TreeNode* invert(TreeNode* root){
        if (root == nullptr){
            return nullptr;
        }

        TreeNode* const left = root->left;
        TreeNode* const right = root->right;
        root->left = invert(right);
        root->right = invert(left);
        return root;
    }

};

int main() {
    invertTree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);

    tree.preorderTraversal();

    TreeNode* root = tree.invert(tree.getRoot());
    cout << endl;
    tree._preorder(root);
}