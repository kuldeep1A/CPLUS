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
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    vector<int> rightSideView_bfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> queue{{root}};

        while (!queue.empty())
        {
            const int size = queue.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = queue.front();
                queue.pop();

                if (i == size - 1)
                    ans.push_back(node->data);

                if (node->left != nullptr)
                    queue.push(node->left);

                if (node->right != nullptr)
                    queue.push(node->right);
            }
        }

        return ans;
    }

    vector<int> rightSideView_dfs(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int depth, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }

        if (depth == ans.size())
        {
            ans.push_back(root->data);
        }

        dfs(root->right, depth + 1, ans);
        dfs(root->left, depth + 1, ans);
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);

    Solution myObj;
    vector<int> result = myObj.rightSideView_bfs(tree);
    for (int ele : result)
    {
        cout << ele << " ";
    }
    result = myObj.rightSideView_dfs(tree);
    cout << endl;
    for (int ele : result)
    {
        cout << ele << " ";
    }
}