class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int res=-1;
        
        for(int i=0;i<cards.size();i++) {
            if(mp.find(cards[i])!=mp.end()) {
                if(res==-1) res = i-mp[cards[i]]+1;
                else res = min(res, i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        
        return res;
    }
};