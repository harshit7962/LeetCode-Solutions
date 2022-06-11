class Solution {
public:
    int lowestInd(vector<int> potion, long long x) {
        int low=0, high=potion.size()-1, res=-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(potion[mid]<x) low = mid+1;
            else {
                res=mid;
                high = mid-1;
            }
        }
        
        return res;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end()); // Sorting potions so that we can binary search on it
        vector<int> ans;
        for(int i = 0; i < n; i++) { // For every spell, binary search on the number of potions that can be used such that spells[i] * potions[j] >= success
            int l = 0, r = m - 1, c = m;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if((((long long)potions[mid]) * ((long long)spells[i])) >= success) {
                    c = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans.push_back(m - c); // Since all potions from potions[c] to potions[m - 1] satisfy the condition, we have 'm - c' pairs for this particular spell
        }
        return ans;
    }
};