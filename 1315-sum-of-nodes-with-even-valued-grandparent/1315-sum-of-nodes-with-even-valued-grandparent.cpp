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
    
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
        if(root == NULL) return 0;
        if(root->val%2==0) {
            if(root->left!=NULL) {
                if(root->left->left!=NULL) res+=root->left->left->val;
                if(root->left->right!=NULL) res+=root->left->right->val;
            }
            if(root->right!=NULL) {
                if(root->right->left!=NULL) res+=root->right->left->val;
                if(root->right->right!=NULL) res+=root->right->right->val;
            }
        }
        if(root->left!=NULL) res+=sumEvenGrandparent(root->left);
        if(root->right!=NULL) res+=sumEvenGrandparent(root->right);
        

        return res;
    }
};