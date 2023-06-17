#include<iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class pathSum {
public:
    int _pathSum(TreeNode* root, long int targetSum){
        if (root == nullptr){
            return 0;
        }

        return dfs(root, targetSum) + _pathSum(root->left, targetSum) + _pathSum(root->right, targetSum);
    }

private:
    int dfs(TreeNode* root, long int targetSum){
        if (root == nullptr){
            return 0;
        }

        return (targetSum == root->data) + dfs(root->left, targetSum - root->data) + dfs(root->right, targetSum - root->data);
    }
};

int main() {
    TreeNode* tree = new TreeNode(10);
    tree->left = new TreeNode(5);
    tree->left->left = new TreeNode(3);
    tree->left->left->left = new TreeNode(3);
    tree->left->left->right = new TreeNode(-2);
    tree->left->right = new TreeNode(2);
    tree->left->right->right = new TreeNode(1);
    tree->right = new TreeNode(-3);
    tree->right->right = new TreeNode(11);


    pathSum myObj;
    int ans = myObj._pathSum(tree, 8);

    cout << "Path Sums are : " << ans;

    // Clean up dynamically allocated memory
    delete tree->left->left->left;
    delete tree->left->left->right;
    delete tree->left->left;
    delete tree->left;
    delete tree->left->right->right;
    delete tree->left->right;
    delete tree->right->right;
    delete tree->right;

    return 0;
}

