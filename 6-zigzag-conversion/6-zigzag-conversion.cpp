class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        vector<char> adj[numRows];
        
        int curr_ind = 0;
        bool goingDown = true;
        
        for(int i=0;i<s.size();i++) {
            adj[curr_ind].push_back(s[i]);
            if(goingDown) curr_ind++;
            else curr_ind--;
            if(curr_ind==0 || curr_ind==numRows-1) goingDown = !goingDown;
        }
        
        string res;
        for(int i=0;i<numRows;i++) {
            for(char c:adj[i]) res+=c;
        }
        
        return res;
    }
};