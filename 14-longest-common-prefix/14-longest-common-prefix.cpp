class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs[0];
        for(int i=1;i<strs.size();i++) {
            if(res.size()<strs[i].size()) {
                int j=0;
                while(j<res.size()) {
                    if(res[j]==strs[i][j]) j++;
                    else break;
                }
                res=res.substr(0, j);
            } else {
                int j=0;
                while(j<strs[i].size()) {
                    if(res[j]==strs[i][j]) j++;
                    else break;
                }
                res = strs[i].substr(0, j);
            }
            if(res=="") return res;
        }
        return res;
    }
};