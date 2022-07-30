class Solution {
public:
    vector<int> get_frequency(string word) {
        vector<int> freq(26, 0);
        
        for(char c: word) {
            freq[c-'a']++;
        }
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        
        vector<int> max_counts(26, 0);
        for(string word: words2) {
            vector<int> curr_count = get_frequency(word);
            
            for(int i=0;i<26;i++) max_counts[i] = max(max_counts[i], curr_count[i]);
        }
        
        for(string word: words1) {
            vector<int> curr_count = get_frequency(word);
            
            bool flag = true;
            for(int i=0;i<26;i++)
                if(max_counts[i] > curr_count[i]) {flag=false; continue;}
            
            if(flag) res.push_back(word);
        }
        
        return res;
    }
};