class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // The main 2D bucket
        if (root == nullptr) return ans; 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size(); // <--- THE MAGIC LINE. How many nodes on this level?
            vector<int> currentLevel; // A temporary 1D bucket for just this current level
            
            // Process ONLY the nodes that belong to this specific level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                currentLevel.push_back(temp->val);
                
                // Add the next level's children to the back of the line
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
            
            // The for-loop ends. This level is done. 
            // Put this level's bucket into the main 2D bucket.
            ans.push_back(currentLevel);
        }
        
        return ans;
    }
};