class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        
        int count = 0, i=0;
        for(string word:words) {
            string reversed = word.substr(1)+word[0];
            if(mp[reversed]) {
                count++;
                mp[reversed]--;
            } else {
                mp[word]++;
            }
            i++;
        }
        
        count*=4;
        
        for(auto t:mp) {
            string x = t.first;
            if(t.second!=0 && x == x.substr(1)+x[0]) return count+2;
        }
        
        return count;
    }
};