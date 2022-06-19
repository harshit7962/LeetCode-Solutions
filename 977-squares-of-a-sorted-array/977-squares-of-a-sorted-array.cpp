class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int i=0, j=n-1, ind=n-1;
        
        while(ind>=0) {
            if(abs(nums[i])>abs(nums[j])) {
                res[ind--] = nums[i]*nums[i];
                i++;
            } else {
                res[ind--] = nums[j]*nums[j];
                j--;
            }
        }
        
        return res;
    }
};