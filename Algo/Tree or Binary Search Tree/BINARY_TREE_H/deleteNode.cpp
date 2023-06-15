/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == nullptr){
            return root;
        }

        if (val < root->data){
            root->left = deleteNode(root->left, val);
        } else if (val > root->data){
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == nullptr && root->right == nullptr){
                delete root;
                root = nullptr;
            } else if (root->left == nullptr){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            } else {
                TreeNode* minNode = getMin(root->right);
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data);
            }
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node){
        while (node->left != nullptr){
            node = node->left;
        }
        return node;
    }

};

int main(){
    BinaryTree binary_tree;


    // Input: root = [5,3,6,2,4,null,7], key = 3
    
    binary_tree.insert(5);
    binary_tree.insert(3);
    binary_tree.insert(6);
    binary_tree.insert(2);
    binary_tree.insert(4);
    binary_tree.insert(7);

    Solution solve;
    binary_tree.preorderTraversal();
    cout << endl;

    TreeNode* res = solve.deleteNode(binary_tree.getRoot(), 3);
    binary_tree._preorder(res);
}