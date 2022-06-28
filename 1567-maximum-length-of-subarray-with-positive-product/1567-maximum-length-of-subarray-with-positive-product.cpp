class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size(),start=-1, end=-1, ind=0, res=0, count=0;
        
        for(int i=0;i<n;i++) {
            if(nums[i]<0) {
                count++;
                if(start==-1) {start=i; end=i;}
                else end=i;
            } else if(nums[i]==0) {
                if(count%2==0) {
                    res = max(res, i-ind);
                } else {
                    res = max(res, max(end-ind, i-start-1));
                }
                ind = i+1;
                count=0;
                start=-1;
                end=-1;
            }
        }
        
        if(count%2==0) {
            return max(res, n-ind);
        }
        return max(res, max(end-ind, n-start-1));
    }
};