class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> v(1001, 0);
        for(int i=0;i<nums.size();i++) v[nums[i]]++;
        
        int curr = nums.size();
        for(int i=0;i<=nums.size();i++) {
            if(i==curr) return i;
            curr-=v[i];
        }
        return -1;
    }
};