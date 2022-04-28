class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n&1) {
            for(int i=-n/2;i<=n/2;i++) res.push_back(i);
        } else {
            for(int i=-n/2;i<=n/2;i++)
                if(i!=0) res.push_back(i);
        }
        
        return res;
    }
};