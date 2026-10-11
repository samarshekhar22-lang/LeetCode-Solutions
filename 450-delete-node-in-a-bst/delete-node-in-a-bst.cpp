/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
            return root;
        }
        if(root->right==nullptr){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==nullptr){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        TreeNode* cur=root->right;
        while(cur->left!=nullptr){
            cur=cur->left;
        }
        root->val=cur->val;
        root->right=deleteNode(root->right,cur->val);
        return root;
    }
};