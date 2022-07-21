class Solution {
public:
    vector<vector<int>> res;
    
    void generateSubsets(vector<int>&nums, int ind, vector<int>&curr) {
        if(ind >= nums.size()) {
            res.push_back(curr);
            return;
        }
        
        generateSubsets(nums, ind+1, curr);
        curr.push_back(nums[ind]);
        generateSubsets(nums, ind+1, curr);
        curr.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        generateSubsets(nums, 0, curr);
        
        return res;
    }
};