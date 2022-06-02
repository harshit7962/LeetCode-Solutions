class Solution {
public:
    int countElements(vector<int>& nums) {
        int minv=nums[0], maxv=nums[0], minc=1, maxc=1;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==minv) minc++;
            else if(nums[i]<minv) {minv=nums[i]; minc=1;}
            
            if(nums[i]==maxv) maxc++;
            else if(nums[i]>maxv) {maxv=nums[i];maxc=1;}
        }
        
        if(minv==maxv) return 0;
        
        return nums.size()-minc-maxc;        
    }
};