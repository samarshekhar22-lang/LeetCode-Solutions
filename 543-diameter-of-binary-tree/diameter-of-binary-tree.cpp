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
    int diameter(TreeNode*root,int &maxD){
        if(root==nullptr){
            return 0;
        }
        int left=diameter(root->left,maxD);
        int right=diameter(root->right,maxD);
        int dia=left+right;
        maxD=max(maxD,dia);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=-1;
        diameter(root,maxD);
        return maxD;
    }
};