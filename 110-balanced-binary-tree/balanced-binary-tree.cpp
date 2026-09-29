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
    int height(TreeNode* root,bool&a){
        if(root==nullptr){
            return 0;
        }
        int x=height(root->left,a);
        int y=height(root->right,a);
        if(abs(x-y)>1){
            a=false;
        }
        return max(x,y)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool a=true;
        height(root,a);
        return a;
    }
};