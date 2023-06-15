#include <iostream>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int Value){
        this->data =Value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree{
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* currentNode, int Value){
        if (currentNode == nullptr){
            currentNode = new TreeNode(Value);
        } else {
            if (Value < currentNode->data){
                currentNode->left = insertNode(currentNode->left, Value);
            } else {
                currentNode->right = insertNode(currentNode->right, Value);
            }
        }
        return currentNode;
    }

    void inorderTraversal(TreeNode* currentNode){
        if (currentNode != nullptr){
            inorderTraversal(currentNode->left);
            cout << currentNode->data << " ";
            inorderTraversal(currentNode->right);
        }
    }

    void preorderTraversal(TreeNode* currentNode){
        if (currentNode != nullptr){
            cout << currentNode->data << " ";
            preorderTraversal(currentNode->left);
            preorderTraversal(currentNode->right);
        }
    }

    void postorderTraversal(TreeNode* currentNode){
        if (currentNode != nullptr){
            inorderTraversal(currentNode->left);
            inorderTraversal(currentNode->right);
            cout << currentNode->data << " ";
        }
    }

    TreeNode* findMinNode(TreeNode* node){
        while (node->left != nullptr){
            node = node->left;
        }

        return node;
    }

    TreeNode* deleteNode(TreeNode* currNode, int val){
        if (currNode == nullptr){
            return currNode;
        }

        if (val < currNode->data){
            currNode->left = deleteNode(currNode->left, val);
        } else if (val > currNode->data){
            currNode->right = deleteNode(currNode->right, val);
        } else {
            if (currNode->left == nullptr && currNode->right == nullptr){
                delete currNode;
                currNode = nullptr;
            } else if (currNode->left == nullptr){
                TreeNode* temp = currNode;
                currNode = currNode->right;
                delete temp;
            } else if (currNode->right == nullptr){
                TreeNode* temp = currNode;
                currNode = currNode->left;
                delete temp;
            } else {
                TreeNode* minNode = findMinNode(currNode->right);
                currNode->data = minNode->data;
                currNode->right = deleteNode(currNode->right, minNode->data);
            }
        }

        return currNode;
    }

public:
    BinaryTree(){
        root = nullptr;
    }

    void insert(int Value){
        root = insertNode(root, Value);
    }

    void inorder(){
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void preorder(){
        cout << "Postorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void postorder(){
        cout << "Postorer Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }

    void deleteNode(int val){
        root = deleteNode(root, val);
    }
};

int main(){
    // create a object of binary tree
    BinaryTree binaryTree;
    
    // Insert the element in bianry tree
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(70);
    binaryTree.insert(60);
    binaryTree.insert(80);

    // print in various type
    binaryTree.preorder();
    binaryTree.postorder();

    cout << endl;
    binaryTree.inorder();

    // delete node 30
    cout << "Delete Node 30" << endl;
    binaryTree.deleteNode(30);
    binaryTree.inorder();
}