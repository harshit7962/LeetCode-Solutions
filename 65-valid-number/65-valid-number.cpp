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
                //There can not be more than two occurances of Plus or Minus
                if(sign==2) return false;
                
                //If not at the beginning, a Plus or Minus can only come after an e or E
                if(i>0 && (s[i-1]!='e'&&s[i-1]!='E')) return false;
                
                //Plus or Minus cannot be the last occurance
                if(i==s.size()-1) return false;
            } else if(c=='.') {
                //Dot
                
                //Decimal cannot occur after an e or E or after any other dot
                if(e||dot) return false;
                
                //Decimal Occuring at the end without occurance of the digit
                if(i==s.size()-1 && !digit) return false;
                dot=true;
            } else if(c=='e' || c=='E'){
                //e occuring after another e or without occurance of a digit or at the end
                if(e || !digit || i==s.size()-1) return false;
                e=true;
            } else return false;
        }
        return true;
    }
};