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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr){
            return minDepth(root->right)+1;
        }
        if(root->right==nullptr){
            return minDepth(root->left)+1;
        }
        int x=minDepth(root->right);
        int y=minDepth(root->left);
        return min(x,y)+1;
    }
};