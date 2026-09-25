/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* r) {
        if (r == nullptr) return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(r);
        
        while (!q.empty()) {
            TreeNode* c = q.front();
            q.pop();
            
            if (c == nullptr) {
                s += "null,";
            } else {
                s += to_string(c->val) + ",";
                q.push(c->left);
                q.push(c->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string d) {
        if (d.empty()) return nullptr;
        
        stringstream ss(d);
        string v;
        
        // Grab the very first value before the comma to make the root
        getline(ss, v, ',');
        TreeNode* r = new TreeNode(stoi(v));
        queue<TreeNode*> q;
        q.push(r);
        
        while (!q.empty()) {
            TreeNode* c = q.front();
            q.pop();
            
            // Try to grab the next string piece for the left child
            if (getline(ss, v, ',')) {
                if (v != "null") {
                    c->left = new TreeNode(stoi(v));
                    q.push(c->left);
                }
            }
            
            // Try to grab the next string piece for the right child
            if (getline(ss, v, ',')) {
                if (v != "null") {
                    c->right = new TreeNode(stoi(v));
                    q.push(c->right);
                }
            }
        }
        
        return r;
    }
};