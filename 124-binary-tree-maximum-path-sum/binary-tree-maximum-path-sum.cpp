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
    int maxSum(TreeNode*root,int &sum){
        if(root==nullptr){
            return 0;
        }
        int l=maxSum(root->left,sum);
        if(l<0) l=0;
        int r=maxSum(root->right,sum);
        if(r<0) r=0;
        int z=root->val;
        sum=max(sum,l+r+root->val);
        return root->val +max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum=-1e9;
        maxSum(root,sum);
        return sum;
    }
};