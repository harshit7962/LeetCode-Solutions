class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if(nums.size()==1) return 1;
        
        int i=0, res=0;
        while(i<nums.size()) {
            //If the last element is left without any successor, it implies our array lenght is odd
            if(i+1>=nums.size()) return res+1;
            
            /**If current even index is even and same as next value
            we change our even index to next index and increment the res variable as well.
            else we increment by two, so that our even index remain intact...
            */
            
            if(nums[i]==nums[i+1]) {
                res++;
                i++;
            } else i+=2;
        }
        
        return res;
    }
};