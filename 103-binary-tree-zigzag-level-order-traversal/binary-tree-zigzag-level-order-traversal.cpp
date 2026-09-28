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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q1;
        q1.push(root);
        bool isLeftToRight=true;
        while(!q1.empty()){
            int l=q1.size();
            vector<int>current;
            for(int i=0;i<l;i++){
                TreeNode* temp=q1.front();
                q1.pop();
                if(temp->left!=nullptr){
                    q1.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q1.push(temp->right);
                }
                current.push_back(temp->val);
            }
            if(!isLeftToRight){
                    reverse(current.begin(), current.end());
                }
                isLeftToRight=!isLeftToRight;
            ans.push_back(current);
        }
        return ans;
    }
};