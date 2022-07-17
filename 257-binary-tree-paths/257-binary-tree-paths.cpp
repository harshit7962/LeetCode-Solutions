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
    vector<string> res;
    
    void path(TreeNode *root, string curr) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            curr += to_string(root->val); 
            res.push_back(curr); 
            return;
        }
        
        curr += to_string(root->val) + "->";
        
        path(root->left, curr);
        path(root->right, curr);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {      
        path(root, "");
        
        return res;
    }
};