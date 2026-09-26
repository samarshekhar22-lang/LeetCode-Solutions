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
private:
   void h(TreeNode* root, vector<int>&v){
    if(root==nullptr){
        return;
    }
    h(root->left,v);
    v.push_back(root->val);
    h(root->right,v);
   }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        h(root,v);
        return v;
    }
};