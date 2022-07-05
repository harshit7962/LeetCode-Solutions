class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        
        for(int i:nums) st.insert(i);
        
        int res=0;
        
        for(int i:nums) {
            if(st.count(i-1)>0) continue;
            else {
                int curr=0, val=i;
                while(st.count(val)>0) {
                    curr++;
                    val++;
                }
                res=max(res, curr);
            }
        }
        
        return res;
    }
};