class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        
        int ls=nums[0], rs=0;
        for(int i=1;i<n;i++) rs+=nums[i];
        if(rs==0) return 0;
        for(int i=1;i<n;i++) {
            rs-=nums[i];
            if(ls==rs) return i;
            ls+=nums[i];
        }
        return -1;
    }
};