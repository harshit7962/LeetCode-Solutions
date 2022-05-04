class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        int res=0;
        mp.insert({nums[0], 1});
        for(int i=1;i<nums.size();i++) {
            if(mp[k-nums[i]]>0) {
                res++;
                mp[k-nums[i]]--;
            }
            else mp[nums[i]]++;
        }
        return res;
    }
};