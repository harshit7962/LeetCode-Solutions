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
    TreeNode *prev=NULL, *first=NULL, *second=NULL;
public:
    void findNodes(TreeNode* root) {
        //If our root node is null, we simply return... (to handle base cases)
        if(root==NULL) return;
        
        //Traverse to the left of the root...
        findNodes(root->left);
        
        //If current node has a value less than the prev node
        if(prev!=NULL && root->val<=prev->val) {
            if(first==NULL) first=prev;
            second = root;
        }
        
        //Update the prev node to current node
        prev = root;
        
        //Check the same for right subtree
        findNodes(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        prev = NULL;
        second = NULL;
        first = NULL;
        findNodes(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};