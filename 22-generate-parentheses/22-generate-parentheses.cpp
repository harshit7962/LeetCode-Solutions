class Solution {
public:
    void recursive(vector<string> &arr, int n, string curr="", int open=0, int close=0)  {
        if(curr.size() == n*2) {
            arr.push_back(curr);
            return;
        }
        
        if(open<n) recursive(arr, n, curr+'(', open+1, close);
        if(close<open) recursive(arr, n, curr+")", open, close+1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursive(res, n);
        
        return res;
    }
};