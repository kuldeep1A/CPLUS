#include <iostream>
#include<vector>
#include<queue>
#include "BinaryTree.h"
using namespace std;

class levelOrder: public BinaryTree {
public:
    vector<vector<int>> levelOrderTraversal(TreeNode* root){
        vector<vector<int>> result;
        queue<TreeNode*> queue;

        queue.push(root);

        while(!queue.empty()){
            int len = queue.size();
            vector<int> level;
            for(int i = 0; i < len; i++){
                TreeNode* current = queue.front();
                queue.pop();
                level.push_back(current->data);

                if (current->left != nullptr){
                    queue.push(current->left);
                }

                if (current->right != nullptr){
                    queue.push(current->right);
                }
            }
            result.push_back(level);            
        }
        return result;
    }
};

int main(){
    levelOrder tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(9);
    tree.insert(20);
    tree.insert(15);
    // 7, 3 9, 15 20

    tree.preorderTraversal();
    
    vector<vector<int>> levels = tree.levelOrderTraversal(tree.getRoot());
    for(vector<int> level: levels){
        for(int node: level){
            cout << node << " ";
        }
        cout << endl;
    }
}