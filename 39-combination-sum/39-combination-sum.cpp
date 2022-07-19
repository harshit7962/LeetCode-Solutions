class Solution {
public:
    vector<vector<int>> res;
    
    void backtrackFun(vector<int>&candidates, int target, vector<int>&curr, int ind) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        
        if(ind==candidates.size()) return;
        
        for(int i=ind;i<candidates.size();i++) {
            if(target-candidates[i]>=0) {
                curr.push_back(candidates[i]);
                backtrackFun(candidates, target-candidates[i], curr, i);
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        
        backtrackFun(candidates, target, curr, 0);
        
        return res;
    }
};