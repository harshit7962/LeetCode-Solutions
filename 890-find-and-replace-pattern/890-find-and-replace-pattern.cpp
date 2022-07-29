class Solution {
public:
    
    bool matches(string &a, string &b) {
        unordered_map<char, char> first, second;
        
        for(int i=0;i<a.size();i++) {
            if(first.find(a[i]) != first.end()) {
                if(first[a[i]]!=b[i]) return false;
            } else first[a[i]] = b[i];
        }
        
        for(int i=0;i<a.size();i++) {
            if(second.find(b[i])!=second.end()) {
                if(second[b[i]]!= a[i]) return false;
            } else second[b[i]] = a[i];
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for(string word:words) {
            if(matches(word, pattern)) res.push_back(word);
        }
        
        return res;
    }
};