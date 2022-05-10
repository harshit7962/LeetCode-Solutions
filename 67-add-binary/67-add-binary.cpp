class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        char c='0';
        int i=a.size()-1, j=b.size()-1;
        while(i>=0 || j>=0) {
            if(i<0) {
                i=0;
                a[i]='0';
            } 
            if(j<0) {
                j=0;
                b[j]='0';
            }
            if(c=='1' && a[i]=='1' && b[j]=='1') {
                res="1"+res;
            } else if (c=='0' && a[i]=='1' && b[j]=='1') {
                res="0"+res;
                c='1';
            } else if(c=='1' && (a[i]=='1' || b[j]=='1')) {
                res="0"+res;
            } else if(c=='0' && (a[i]=='1' || b[j]=='1')) {
                res="1"+res;
            } else if(c=='1') {
                res="1"+res;
                c='0';
            } else {
                res="0"+res;
            }
            i--;
            j--;
        }

        if(c=='1') res="1"+res;
        return res;
    }
};