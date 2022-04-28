class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        
        for(int i=-n/2;i<=n/2;i++)
            if(i!=0 || n&1) res.push_back(i);
        
        return res;
    }
};