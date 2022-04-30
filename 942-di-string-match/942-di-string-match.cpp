class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0, j=s.size();
        vector<int> res;
        for(int x=0;x<s.size();x++) {
            if(s[x]=='I') res.push_back(i++);
            else res.push_back(j--);
        }
        res.push_back(i);
        return res;
    }
};