/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node *> q;
        q.push(root);
        Node *temp = NULL;
        while(!q.empty()) {
            int x = q.size();
            for(int i=0;i<x;i++) {
                temp = q.front();
                q.pop();
                if(q.empty()) temp->next = NULL;
                else temp->next = q.front();
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            temp->next = NULL;
        }
        
        return root;
    }
};