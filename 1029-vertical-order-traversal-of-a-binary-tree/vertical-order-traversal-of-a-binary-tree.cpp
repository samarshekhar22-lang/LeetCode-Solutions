#include <bits/stdc++.h>
using namespace std;

// LeetCode's node structure
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // The 3D Map: Column -> Row -> Self-Sorting Bucket (Multiset)
        map<int, map<int, multiset<int>>> m;
        
        // The Queue: { Node pointer, {Column, Row} }
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root == nullptr) {
            return {};
        }
        
        // Start at Root: Column 0, Row 0
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            
            TreeNode* curr = x.first;
            int col = x.second.first;
            int row = x.second.second;
            
            // Drop the value into the exact grid coordinate bucket
            // The multiset automatically sorts it if there's a collision!
            m[col][row].insert(curr->val);
            
            // Travel Left: Column decreases, Row increases (moves down)
            if (curr->left != nullptr) {
                q.push({curr->left, {col - 1, row + 1}});
            }
            
            // Travel Right: Column increases, Row increases (moves down)
            if (curr->right != nullptr) {
                q.push({curr->right, {col + 1, row + 1}});
            }
        }
        
        // Prepare the final 2D answer vector
        vector<vector<int>> ans;
        
        // Step 1: Loop through every Column in the map
        for (auto c : m) {
            vector<int> current_column_nodes; // Holds all nodes for this column
            
            // Step 2: Loop through every Row inside that specific Column
            for (auto r : c.second) {
                
                // Step 3: Loop through the multiset bucket and extract the sorted values
                for (auto value : r.second) {
                    current_column_nodes.push_back(value);
                }
            }
            
            // Add the fully collected column to our final answer
            ans.push_back(current_column_nodes);
        }
        
        return ans;
    }
};