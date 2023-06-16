#include<iostream>
using namespace std;

class OwnBTree {
public:
    int data;
    OwnBTree* left;
    OwnBTree* right;

    OwnBTree(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class diameterOfBinaryTree {
public:
    int _diameterOfBinaryTree(OwnBTree* root){
        int ans = 0;
        maxDepth(root, ans);
        return ans;
    }
private:
    int maxDepth(OwnBTree* root, int& ans){
        if (root == nullptr){
            return 0;
        }

        const int left = maxDepth(root->left, ans);
        const int right = maxDepth(root->right, ans);

        ans = max(ans, left + right);

        return 1 + max(left, right);
    }
};

int main() {
    OwnBTree* tree = new OwnBTree(1);
    tree->left = new OwnBTree(2);
    tree->left->left = new OwnBTree(4);
    tree->left->right = new OwnBTree(5);
    tree->right = new OwnBTree(3);


    diameterOfBinaryTree myObj;
    int ans = myObj._diameterOfBinaryTree(tree);

    cout << "Diameter of Binary tree: " << ans;

    // Clean up dynamically allocated memory
    delete tree->left->left;
    delete tree->left->right;
    delete tree->left;
    delete tree->right;
    delete tree;

    return 0;
}

