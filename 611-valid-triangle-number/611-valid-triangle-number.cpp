class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), count=0;
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                //Finding the least value that can satisfy the property nums[i]+nums[j] > nums[x]
                int low = j, high = n-1, res = j;
                while(low <= high) {
                    int mid = (low + high)/2;
                    if(nums[mid] < nums[i]+nums[j]) {
                        res = mid;
                        low = mid+1;
                    } else high = mid-1;
                }
                
                count += (res - j);
            }
        }
        
        return count;
    }
};