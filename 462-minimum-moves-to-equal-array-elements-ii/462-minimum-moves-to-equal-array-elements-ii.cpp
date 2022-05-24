class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //Sorting the array
        sort(nums.begin(), nums.end());
        
        //Finding the Median
        int median, n=nums.size();
        if(n&1) median = nums[n/2];
        else median = (nums[n/2]+nums[(n-1)/2])/2;

        //Find the minimum cost
        int cost=0;
        for(int i=0;i<n;i++) {
            cost+=abs(median-nums[i]);
        }
        
        return cost;
    }
};