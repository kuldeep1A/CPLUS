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

class breadthFirstSearch
{
public:
    vector<int> bfs(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> queue{{root}};

        while (!queue.empty())
        {
            TreeNode *node = queue.front();
            queue.pop();
            ans.push_back(node->data);

            if (node->left != nullptr)
            {
                queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                queue.push(node->right);
            }
        }
        return ans;
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

    breadthFirstSearch MY;

    vector<int> result = MY.bfs(tree);

    for (int ele : result)
    {
        cout << ele << " ";
    }
}