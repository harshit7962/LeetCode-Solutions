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
    vector<TreeNode*> generateRoot(int start, int end) {
        vector<TreeNode *> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        if(start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        
        for(int i=start;i<=end;i++) {
            vector<TreeNode *> leftTree = generateRoot(start, i-1);
            vector<TreeNode *> rightTree = generateRoot(i+1, end);
            
            for(TreeNode* lt: leftTree) {
                for(TreeNode* rt: rightTree) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateRoot(1, n);
    }
};