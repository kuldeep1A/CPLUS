#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    void inorderTraversalRecursive(TreeNode* current) {
        if (current != nullptr) {
            inorderTraversalRecursive(current->left);
            cout << current->data << " ";
            inorderTraversalRecursive(current->right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }
};

int main() {
    BinaryTree binaryTree;

    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(70);
    binaryTree.insert(60);
    binaryTree.insert(80);

    cout << "Inorder Traversal: ";
    binaryTree.inorderTraversal();
    cout << endl;

    return 0;
}
