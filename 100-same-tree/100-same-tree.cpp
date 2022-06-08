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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL) return true;
        if((p==NULL &&  q!=NULL) || (q==NULL && p!=NULL)) return false;
        if(p->left==NULL && q->left!=NULL) return false;
        if(p->left!=NULL && q->left==NULL) return false;
        if(p->right!=NULL && q->right==NULL) return false;
        if(p->right==NULL && q->right!=NULL) return false;
        if(p->val!=q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};