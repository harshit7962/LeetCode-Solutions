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
    string res="";
    void inorder(TreeNode *root, string curr=""){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            curr+=(char)(97+root->val);
            reverse(curr.begin(), curr.end());
            if(res=="") res = curr;
            else res=min(res, curr);
            return;
        }
        
        inorder(root->left, curr+(char)(97+root->val));
        inorder(root->right, curr+(char)(97+root->val));
    }
    
    string smallestFromLeaf(TreeNode* root) {
        inorder(root, "");
        return res;
    }
};