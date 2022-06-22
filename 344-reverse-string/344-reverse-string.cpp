class Solution {
public:
    void reverseString(vector<char>& s) {
        int first=0, last=s.size()-1;
        while(first<last) {
            char temp = s[first];
            s[first++] = s[last];
            s[last--] = temp;
        }
    }
};