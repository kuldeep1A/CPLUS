#include <iostream>
#include <vector>
#include <queue>
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
        this->right = nullptr;
        this->left = nullptr;
    }
};

class depth_first_search
{
public:
    vector<int> dfs(TreeNode *root)
    {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }

private:
    void traverse(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        ans.push_back(root->data);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right = new TreeNode(3);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);

    depth_first_search MY;

    vector<int> result = MY.dfs(tree);

    for (int ele : result)
    {
        cout << ele << " ";
    }
}