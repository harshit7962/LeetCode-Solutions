class Solution {
public:
    string greatestLetter(string s) {
        vector<int> v(128, 0);
        for(char c:s) {
            v[c-'A']++;
        }
        
        int res=-1;
        for(int i=0;i<26;i++) {
            if(v[i]>0 && v[i+32]>0) res=i;
        }
        if(res==-1) return "";
        char ch = static_cast<char>(res+65);
        string r = "";
        r+=ch;
        return r;
    }
};