#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;
    TreeNode* insertRecursive(TreeNode* current, int value){
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
    void inorderTraversalRecursive(TreeNode* current){
        if (current != nullptr) {
            inorderTraversalRecursive(current->left);
            std::cout << current->data << " ";
            inorderTraversalRecursive(current->right);
    }

    }
    void preorderTraversalRecursive(TreeNode* current){
        if (current != nullptr) {
            std::cout << current->data << " ";
            preorderTraversalRecursive(current->left);
            preorderTraversalRecursive(current->right);
    }
    }
    void postorderTraversalRecursive(TreeNode* current){
        if (current != nullptr) {
            postorderTraversalRecursive(current->left);
            postorderTraversalRecursive(current->right);
            std::cout << current->data << " ";
    }
    }

public:
    BinaryTree(){
        root = nullptr;
    }
    void insert(int value){
        root = insertRecursive(root, value);
    }
    TreeNode* getRoot(){
        return root;
    }
    void addRoot(TreeNode* _root){
        root = _root;
    }
    void inorderTraversal(){
        inorderTraversalRecursive(root);
    }
    void preorderTraversal(){
        preorderTraversalRecursive(root);
    }
    void postorderTraversal(){
        postorderTraversalRecursive(root);
    }

    void _preorder(TreeNode* res){
        preorderTraversalRecursive(res);
    }
};

#endif