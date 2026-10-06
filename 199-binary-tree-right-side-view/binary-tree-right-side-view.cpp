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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*>q1;
        if(root==nullptr){
            return {};
        }
        q1.push(root);
        while(!q1.empty()){
            int l=q1.size();
            TreeNode*temp;
            for(int i=0;i<l;i++){
                temp=q1.front();
                q1.pop();
                if(temp->left!=nullptr){
                    q1.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q1.push(temp->right);
                }
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};