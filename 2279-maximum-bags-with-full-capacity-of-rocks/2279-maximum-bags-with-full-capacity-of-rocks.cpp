class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int> difference(n);
        for(int i=0;i<n;i++) difference[i]=capacity[i]-rocks[i];
        
        sort(difference.begin(), difference.end());
        
        int i=0, res=0;
        while(difference[i]==0) {
            res++;
            i++;
        }
        
        while(additionalRocks>0 && i<n) {
            if(additionalRocks-difference[i]>=0) res++;
            additionalRocks-=difference[i++];
        }
        
        return res;
    }
};