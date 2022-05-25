class Solution {
public:
    bool isNumber(string s) {
        bool digit=false, e=false, dot=false;
        int sign=0;
        
        for(int i=0;i<s.size();i++) {
            char c = s[i];
            
            //Digit
            if(c>='0' && c<='9') digit=true;
            else if(c=='+' || c=='-') {
                //Sign
                if(sign==2) return false;
                if(i>0 && (s[i-1]!='e'&&s[i-1]!='E')) return false;
                if(i==s.size()-1) return false;
            } else if(c=='.') {
                //Dot
                if(e||dot) return false;
                if(i==s.size()-1 && !digit) return false;
                dot=true;
            } else if(c=='e' || c=='E'){
                if(e || !digit || i==s.size()-1) return false;
                e=true;
            } else return false;
        }
        return true;
    }
};