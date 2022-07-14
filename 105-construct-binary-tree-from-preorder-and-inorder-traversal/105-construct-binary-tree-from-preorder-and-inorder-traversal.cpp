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
    int pre_ind = 0;
    
    TreeNode *tree(vector<int>&preorder, vector<int>&inorder, int start, int end) {
        if(start>end) return NULL;
        
        TreeNode *root = new TreeNode(preorder[pre_ind]);
        
        int ino_ind = start;
        
        for(int i=start;i<=end;i++) {
            if(inorder[i] == preorder[pre_ind]) {
                ino_ind = i;
                break;
            }
        }
        
        pre_ind++;
        
        root->left = tree(preorder, inorder, start, ino_ind-1);
        root->right= tree(preorder, inorder, ino_ind+1, end);
        
        return root;        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree(preorder, inorder, 0, inorder.size()-1);
    }
};