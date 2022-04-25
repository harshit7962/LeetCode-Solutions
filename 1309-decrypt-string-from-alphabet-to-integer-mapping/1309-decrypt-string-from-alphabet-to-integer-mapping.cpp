class Solution {
public:
    string freqAlphabets(string s) {
        string curr="";
        for(int i=0;i<s.size();i++) {
            if(i+2<s.size() && s[i+2]=='#') {
                int x = stoi(s.substr(i, 2));
                curr+='a'+x-1;
                i+=2;
            } else {
                curr+='a'+(s[i]-'1');
            }
        }
        return curr;
    }
};