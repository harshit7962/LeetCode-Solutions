class Solution {
public:
    unordered_set<string> st;
    
    void permute(string s, string curr) {
        if(s.size()==0) {
            st.insert(curr);
            return;
        }
        
        for(int i=0;i<s.size();i++) {
            string newstr = s.substr(0, i) + s.substr(i+1);
            permute(newstr, curr+s[i]);            
        }
    }
    
    
    vector<int> convert(string s) {
        vector<int> res(s.size());
        for(int i=0;i<s.size();i++) res[i] = (int)(s[i]-48);
        
        return res;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        string s = "";
        for(int i:nums) s += i+48;
        permute(s, "");
        
        vector<vector<int>> res;
        
        for(auto str: st) {
            vector<int> temp = convert(str);
            res.push_back(temp);
        }
        
        return res;
    }
};