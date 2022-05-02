class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> eve;
        int i=0;
        while(i<nums.size()) {
            eve.push_back(nums[i]);
            if(i+1<nums.size()) odd.push_back(nums[i+1]);
            i+=2;
        }
        
        sort(eve.begin(), eve.end());
        sort(odd.begin(), odd.end(), greater<int>());
        
        int k=0, j=0;
        for(int i=0;i<nums.size();i++) {
            nums[i] = eve[j++];
            if(i+1<nums.size()) nums[i+1] = odd[k++];
            i++;
        }
        
        return nums;
    }
};