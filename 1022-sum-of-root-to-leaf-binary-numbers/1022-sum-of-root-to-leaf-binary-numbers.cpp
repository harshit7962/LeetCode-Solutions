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
    int res=0;
    
    int binaryToInt(string curr) {
        int r=0;
        for(char c:curr) {
            if(c=='1') r=r*2+1;
            else r=r*2;
        }
        
        return r;
    }
    
    int sumRootToLeaf(TreeNode* root, string curr="") {
        if(root->val==0) curr+='0';
        else curr+='1';
        
        if(root->left==NULL && root->right==NULL) {
            res+=binaryToInt(curr);
        } else if(root->left==NULL){
            
            sumRootToLeaf(root->right, curr);
        } else if(root->right==NULL) {
            sumRootToLeaf(root->left, curr);
        } else {
            sumRootToLeaf(root->right, curr);
            sumRootToLeaf(root->left, curr);
        }
        
        return res;
    }
};