class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res;
        
        for(int i=0;i<n;i++) {
            int c=m, low=0, high=m-1;
            while(low<=high) {
                int mid = low+(high-low)/2;
                if((long long)potions[mid]*(long long)spells[i]>=success) {
                    c = mid;
                    high = mid-1;
                } else low = mid+1;
            }
            res.push_back(m-c);
        }
        return res;
    }
};