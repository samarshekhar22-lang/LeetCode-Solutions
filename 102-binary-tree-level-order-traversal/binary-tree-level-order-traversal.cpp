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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            vector<int>v2;
            int l=q1.size();
            for(int i=0;i<l;i++){
                 TreeNode* temp=q1.front();
            q1.pop();
                v2.push_back(temp->val);
            if(temp->left!=nullptr){
                q1.push(temp->left);
            }
            if(temp->right!=nullptr){
                q1.push(temp->right);
            }
            }
            ans.push_back(v2);
        }
        return ans;
    }
};