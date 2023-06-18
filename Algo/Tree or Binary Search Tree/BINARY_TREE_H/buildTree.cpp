#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    void preorder(Node *res)
    {
        if (res != nullptr)
        {
            cout << res->data << " ";
            preorder(res->left);
            preorder(res->right);
        }
    }

    Node *BuildTree(vector<int> preorder, vector<int> inorder)
    {
        unordered_map<int, int> inToIndex;

        for (int i = 0; i < inorder.size(); i++)
        {
            inToIndex[inorder[i]] = i;
        }

        return Build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inToIndex);
    }

private:
    Node *Build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder,
                int inStart, int inEnd, const unordered_map<int, int> &inToIndex)
    {
        if (preStart > preEnd)
            return nullptr;

        const int rootVal = preorder[preStart];
        const int rootToIndex = inToIndex.at(rootVal);
        const int leftSize = rootToIndex - inStart;

        Node *root = new Node(rootVal);

        root->left = Build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootToIndex - 1, inToIndex);
        root->right = Build(preorder, preStart + leftSize + 1, preEnd, inorder, rootToIndex + 1, inEnd, inToIndex);

        return root;
    }
};

int main()
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    Solution myObj;

    Node *res = myObj.BuildTree(preorder, inorder);

    myObj.preorder(res);
}