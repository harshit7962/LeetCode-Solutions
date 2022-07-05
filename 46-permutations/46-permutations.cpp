class Solution {
public:
    vector<vector<int>> res;
    
    void stringToArray(string s) {
        vector<int> curr;
        
        for(char c:s) {
            curr.push_back(c-'0');
        }
        
        res.push_back(curr);
    }
    
    void permutate(string s, string curr="") {
        if(s.size()==0) {stringToArray(curr); return;}
        
        for(int i=0;i<s.size();i++){
            permutate(s.substr(0,i)+s.substr(i+1), curr+s[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        string str="";
        for(int i:nums) str+=(i+48);
        
        permutate(str,"");
        return res;
    }
};