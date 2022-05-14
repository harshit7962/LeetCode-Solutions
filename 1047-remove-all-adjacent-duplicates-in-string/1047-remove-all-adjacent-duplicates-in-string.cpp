class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(char c:s) {
            if(res.size()==0 || res[res.size()-1]!=c) res+=c;
            else res.pop_back();
        }
        return res;
    }
};