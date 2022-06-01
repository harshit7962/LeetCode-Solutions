class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int ind=0;
        vector<string> res;
        for(int i=1;i<=n && ind<target.size();++i) {
            if(i==target[ind]) {
                res.push_back("Push");
                ind++;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        
        return res;
    }
};