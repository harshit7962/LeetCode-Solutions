class Solution {
public:
    string removeDuplicates(string s) {
        string  res="";
        for(char i:s) {
            if(res.size()==0 || res[res.size()-1]!=i) res+=i;
            else res.pop_back();
        }
        return res;
    }
};