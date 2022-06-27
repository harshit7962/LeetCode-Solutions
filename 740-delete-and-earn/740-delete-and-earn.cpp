class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> house(n, 0);
        
        for(int num:nums) house[num]+=num;
        
        int prev=house[0], curr=max(house[0], house[1]);
        
        for(int i=2;i<n;i++) {
            int next = max(curr, prev+house[i]);
            prev = curr;
            curr = next;
        }
        
        return max(prev, curr);
    }
};