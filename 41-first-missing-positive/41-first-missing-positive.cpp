class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums) {
            if(i>0 && i<=nums.size()) s.insert(i);
        }
        
        for(int i=1;i<=nums.size();i++) {
            if(s.count(i)==0) return i;
        }
        return s.size()+1;
    }
};