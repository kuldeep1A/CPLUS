#include "binary_tree.h"
#include <iostream>

using namespace std;

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

    cout << "Preorder Traversal: ";
    binaryTree.preorderTraversal();
    cout << endl;

    cout << "Postorder Traversal: ";
    binaryTree.postorderTraversal();
    cout << endl;

    return 0;
}
