class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n =nums.size();
        vector<vector<int>> v(n);
        
        v[0].push_back(nums[0]);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0 && v[i].size()<v[j].size()) {
                    v[i] = v[j];
                }
            }
            v[i].push_back(nums[i]);
        }
        
        int res = 0;
        for(int i=1;i<n;i++) if(v[res].size()<v[i].size()) res = i;
        
        return v[res];
    }
};