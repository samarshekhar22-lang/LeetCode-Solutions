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
    void valid(TreeNode* root,long max,long min,bool &ans){
        if(root==nullptr){
            return;
        }
        valid(root->left,root->val,min,ans);
            if(root->val>=max){
                ans=false;
            }
        valid(root->right,max,root->val,ans);
            if(root->val<=min){
                ans=false;
            
        }
    }

    bool isValidBST(TreeNode* root) {
        long max=LONG_MAX;
        long min=LONG_MIN;
        bool ans=true;
        valid(root,max,min,ans);
        return ans;
    }
};