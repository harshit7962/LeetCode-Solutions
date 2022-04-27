class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftSum(n), rightSum(n);
        leftSum[0]=nums[0];
        rightSum[n-1] = nums[n-1];
        
        for(int i=1;i<n;i++) leftSum[i]=nums[i]+leftSum[i-1];
        for(int i=n-2;i>=0;i--) rightSum[i]=nums[i]+rightSum[i+1];
        
        for(int i=0;i<n;i++) {
            if(leftSum[i]==rightSum[i]) return i;
        }
        return -1;
    }
};