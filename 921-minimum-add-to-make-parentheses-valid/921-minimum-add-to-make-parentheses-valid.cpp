class Solution {
public:
    int minAddToMakeValid(string s) {
        int need_closing=0, need_opening=0;
        
        for (char c:s) {
            if(c=='(') need_closing++;
            else if(need_closing==0) need_opening++;
            else need_closing--;
        }
        
        return need_opening +need_closing;
    }
};