class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber>0) {
            char c = '@' + (columnNumber%26);
            if(columnNumber%26==0) {
                c = 'Z';
                columnNumber--;
            }
            res=c+res;
            columnNumber/=26;
        }
        
        return res;
    }
};