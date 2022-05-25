class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int largest=nums[0], second=INT_MIN, third=INT_MIN;
        bool flags=false, flagt=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>largest) {
                third=second;
                second=largest;
                largest=nums[i];
                if(flags) flagt=true;
                flags=true;
            } else if(nums[i]>second) {
                if(nums[i]==largest) continue;
                third=second;
                second=nums[i];
                if(flags) flagt=true;
                flags=true;
            } else if(nums[i]==INT_MIN && second==INT_MIN && nums[i]!=largest) {
                flags=true;
            } else if(nums[i]>=third && nums[i]!=second && nums[i]!=largest) {
                third=nums[i];
                flagt=true;
            }
        }
        
        if(!flagt) return largest;
        return third;
    }
};