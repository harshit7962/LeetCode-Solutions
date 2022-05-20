class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                int k=j+1, l=n-1;
                while(k<l) {
                    int sum = (long long)target-((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l]);
                    if(sum==0) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k<l && nums[k]==nums[k+1]) k++;
                        while(k<l && nums[l]==nums[l-1]) l--;
                        k++;
                        l--;
                    } else if(sum<0) l--;
                    else k++;
                }
                while(j<n-2 && nums[j]==nums[j+1]) j++;
            }
            while(i<n-3 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};