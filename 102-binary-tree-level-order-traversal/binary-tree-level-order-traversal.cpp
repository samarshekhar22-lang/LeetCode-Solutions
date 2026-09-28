 class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v1;
        
        if(root == nullptr){
            return {};
        }
        
        // 1. Build the queue and start the line OUTSIDE the loop
        queue<TreeNode*> q1; 
        q1.push(root);
        
        // 2. The engine runs until the queue is completely empty
        while(!q1.empty()){
            
            int l = q1.size(); 
            vector<int> v2;    
            
            // 3. Process the exact number of nodes currently in this level
            for(int i = 0; i < l; i++){
                
                // Grab, pop, and process INSIDE the batch loop
                TreeNode* temp = q1.front(); 
                q1.pop();
                
                v2.push_back(temp->val); // Use 'val' instead of 'data'
                
                // Send children to the back of the line
                if(temp->left != nullptr){
                    q1.push(temp->left); // Queues use 'push', not 'push_back'
                }
                if(temp->right != nullptr){
                    q1.push(temp->right);
                }
            }
            
            // 4. Batch is done, add it to the main answer
            v1.push_back(v2); 
        }
        
        return v1;
    }
};