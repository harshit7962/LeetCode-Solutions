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
    
    int sumRootToLeaf(TreeNode* root, int sum=0) {
        if(root->val==0) sum=sum*2;
        else sum=sum*2+1;
        
        if(root->left==NULL && root->right==NULL) {
            res+=sum;
        } else if(root->left==NULL){
            sumRootToLeaf(root->right, sum);
        } else if(root->right==NULL) {
            sumRootToLeaf(root->left, sum);
        } else {
            sumRootToLeaf(root->right, sum);
            sumRootToLeaf(root->left, sum);
        }
        
        return res;
    }
};