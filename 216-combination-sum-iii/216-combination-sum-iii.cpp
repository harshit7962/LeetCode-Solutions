class Solution {
public:
    void recursiveResult(int n, int k, int start, vector<int>& curr, vector<vector<int>>& res) {
        if(n==0 && k==0) {
            res.push_back(curr);
            return;
        }
        if(n<0 || k<0) return;
        
        for(int i=start;i<=9;i++) {
            curr.push_back(i);
            recursiveResult(n-i, k-1, i+1, curr, res);
            curr.pop_back();            
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        recursiveResult(n, k, 1, curr, res);
        
        return res;
        
    }
};