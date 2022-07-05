class Solution {
public:
    bool checkValidString(string s) {
        int leftBalance = 0;
        
        for(char c:s){
            if(c==')') leftBalance--;
            else leftBalance++;
            if(leftBalance<0) return false;
        }
        
        if(leftBalance==0) return true;
        
        int  rightBalance = 0;
        
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]=='(') rightBalance--;
            else rightBalance++;
            
            if(rightBalance<0) return false;
        }
        
        return true;
    }
};