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
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int l=0;
        TreeNode* temp1=root;
        while(temp1!=nullptr){
            l++;
            temp1=temp1->left;
        }
        int r=0;
        TreeNode* temp2=root;
        while(temp2!=nullptr){
            r++;
            temp2=temp2->right;
        }
        if(l==r){
            return pow(2,l)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};