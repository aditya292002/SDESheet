#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* addOneRow(TreeNode* &root, int val, int depth) {   
    if(depth == 1) {
        TreeNode* node = new TreeNode(val);
        node->left = root; 
        return node;
    }   

    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    if(depth - 1 == 1) goto here;

    while(!q.empty()) {
        level++;
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            TreeNode* node = q.front(); q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(level == depth - 1) {
            break;
        }
    }


    here:
    while(!q.empty()) {
        auto node = q.front();
        if(node->left) {
            TreeNode* newNode = new TreeNode(val);
            auto temp = node->left;
            node->left = newNode;
            newNode->left = temp;   
        }
        else {
            node->left = new TreeNode(val);
        }


        if(node->right) {
            TreeNode* newNode = new TreeNode(val);
            auto temp = node->right;
            node->right = newNode;
            newNode->right = temp;   
        }
        else {
            node->right = new TreeNode(val);
        }
    }
    return root;
}
int main() {
}
