class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> res;
    
    void create(vector<int>&nums, vector<int>&curr, int ind) {
        if(ind == nums.size()) {
            if(st.count(curr)==0) {
                st.insert(curr);
                res.push_back(curr);
            }
            return;
        }
        
        create(nums, curr, ind+1);
        curr.push_back(nums[ind]);
        create(nums, curr, ind+1);
        curr.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        create(nums, curr, 0);
        
        return res;
    }
};