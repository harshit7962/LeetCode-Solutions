class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0, res=0, curr_max=0;
        
        vector<int> char_count(26, 0);
        
        while(right<s.size()) {
            char_count[s[right]-'A']++;
            curr_max = max(curr_max, char_count[s[right]-'A']);
            
            int window_size = right-left+1;
            if(window_size-curr_max > k) {
                char_count[s[left]-'A']--;
                left++;
            }
            
            res = max(res, right-left+1);
            right++;
        }
        
        return res;
    }
};