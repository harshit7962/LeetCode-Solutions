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
private:
    int preIndex=0;
    
public:
    TreeNode *cTree(vector<int> preorder, vector<int> inorder, int is, int ie) {
        if(is>ie) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        
        int ind;
        for(int i=is;i<=ie;i++) {
            if(inorder[i]==root->val) {ind=i;break;}
        }
        
        root->left = cTree(preorder, inorder, is, ind-1);
        root->right = cTree(preorder, inorder, ind+1, ie);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return cTree(preorder, inorder, 0, inorder.size()-1);
    }
};