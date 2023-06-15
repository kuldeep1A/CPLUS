#include<iostream>
#include "BinaryTree.h"

using namespace std;


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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
private:
    bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if (root == nullptr){
            return true;
        }

        if (minNode != nullptr && root->data <= minNode->data){
            return false;
        }
        if (maxNode != nullptr && root->data >= maxNode->data){
            return false;
        }

        return dfs(root->left, minNode, root) && dfs(root->right, root, maxNode);
    }
};

int main() {
    BinaryTree right_tree;

    right_tree.insert(50);
    right_tree.insert(30);
    right_tree.insert(20);
    right_tree.insert(40);
    right_tree.insert(35);
    right_tree.insert(45);
    right_tree.insert(70);
    right_tree.insert(60);
    right_tree.insert(80);

    Solution solve;

    bool res = solve.isValidBST(right_tree.getRoot());

    cout << (res ? "true" : "false") << endl;


    BinaryTree wrong_tree;

    wrong_tree.insertWrong(50);
    wrong_tree.insertWrong(30);
    wrong_tree.insertWrong(20);
    wrong_tree.insertWrong(40);
    wrong_tree.insertWrong(35);
    wrong_tree.insertWrong(45);
    wrong_tree.insertWrong(70);
    wrong_tree.insertWrong(60);
    wrong_tree.insertWrong(80);


    res = solve.isValidBST(wrong_tree.getRoot());
    cout << (res ? "true" : "false") << endl;
    return 0;
}