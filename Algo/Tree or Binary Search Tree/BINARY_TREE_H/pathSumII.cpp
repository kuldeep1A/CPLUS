#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans;
        dfs(root, sum, {}, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int sum, vector<int> &&path,
             vector<vector<int>> &ans)
    {
        if (root == nullptr)
            return;
        if (root->data == sum && root->left == nullptr && root->right == nullptr)
        {
            path.push_back(root->data);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->data);
        dfs(root->left, sum - root->data, move(path), ans);
        dfs(root->right, sum - root->data, move(path), ans);
        path.pop_back();
    }
};

int main()
{
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(4);
    tree->left->left = new TreeNode(11);
    tree->left->left->left = new TreeNode(7);
    tree->left->left->right = new TreeNode(2);
    tree->right = new TreeNode(8);
    tree->right->left = new TreeNode(13);
    tree->right->right = new TreeNode(4);
    tree->right->right->left = new TreeNode(5);
    tree->right->right->right = new TreeNode(1);

    Solution myObj;
    vector<vector<int>> ans = myObj.pathSum(tree, 22);

    for (vector<int> path : ans)
    {
        cout << "path : [ ";
        for (int ele : path)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }

    // Clean up dynamically allocated memory
    delete tree->left->left->left;
    delete tree->left->left->right;
    delete tree->left->left;
    delete tree->left;
    delete tree->right->right->right;
    delete tree->right->right;
    delete tree->right->right;
    delete tree->right;

    return 0;
}
