class Solution {
public:
    static bool compareValue(int i, int j) {
        return abs(i)<abs(j);
    }
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareValue);
        for(int i=0;i<nums.size();i++) nums[i]*=nums[i];
        return nums;
    }
};