class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int ind = 0;
        while(!(s[ind]>='0' && s[ind]<='9') && s[ind]!='-' && s[ind]!='+') {
            if(s[ind]==' ') ind++;
            else return 0;
        }
        
        bool isNegative = false;
        if(s[ind] == '-') {isNegative = true;ind++;}
        else if(s[ind] == '+') ind++;
        
        while(s[ind]>='0' && s[ind]<='9') {
            res = res*10 + (s[ind]-'0');
            ind++;
            
            if(res > INT_MAX) break;
        }
        
        if(isNegative) {
            if(res>=2147483648) return INT_MIN;
            return -res;
        }
        
        if(res>=INT_MAX) return INT_MAX;
        return res;
    }
};