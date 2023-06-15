#include<iostream>
#include "BinaryTree.h"
#include <vector>

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> list;
        // inorderTraversal(root, list);
        // return list[k - 1];
        int ans = -1;
        int rank = 0;
        traverse(root, k, rank, ans);
        return ans;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& list){
        if (root != nullptr) {
            inorderTraversal(root->left, list);
            list.push_back(root->data);
            inorderTraversal(root->right, list);
        }
    }
    void traverse(TreeNode* root, int k, int& rank, int& ans) {
        if (root != nullptr){
            traverse(root->left, k, rank, ans);
            if (++rank == k){
                ans = root->data;
                return;
            }
            traverse(root->right, k, rank, ans);
        }
    }
};


int main() {
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(6);

    Solution solve;

    cout << "kthSmallest: ";
    int res = solve.kthSmallest(tree.getRoot(), 3);
    cout << res;
}

