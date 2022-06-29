class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0, res=0;
        vector<int> char_count(26, 0);
        
        int max_count=0;
        
        while(right<s.size()) {
            char_count[s[right]-'A']++;
            max_count = max(max_count, char_count[s[right]-'A']);
            
            right++;
            int window_size = right-left;
            
            if(window_size-max_count<=k) {
                res = max(res, right-left);
            } else {
                char_count[s[left]-'A']--;
                left++;
            }
        }
        
        return res;
    }
};