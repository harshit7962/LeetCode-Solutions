class Solution {
public:
    bool contains(string s, unordered_map<string, int> mp, int i, int j, int ws) {
        for(int x=i;x<=j;x=x+ws) {
            mp[s.substr(x, ws)]--;
        }
        
        for(auto x:mp) if(x.second!=0) return false;
        
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        //Total number of characters in our words list
        int words_count = words.size()*words[0].size();
        if(s.size()<words_count) return {};
        
        //We create a hashvalue to travel only if the hashvalue is satisfied...
        int hashval=0;
        unordered_map<string, int> mp;
        for(string word:words) {
            mp[word]++;
            for(char c:word) hashval+=c-'a';
        }
        
        //For first index, we need to travel the string till number of characters...
        int currval=0;
        for(int i=0;i<words_count;i++) {
            currval+=s[i]-'a';
        }
        
        
        vector<int> res;
        
        if(hashval==currval) {
            if(contains(s, mp, 0, words_count-1, words[0].size()))
                res.push_back(0);
        }
        
        int i=0, j=words_count-1;
        while(j<s.size()) {
            currval-=(s[i++]-'a');
            currval+=(s[++j]-'a');

            if(currval==hashval) {
                if(contains(s, mp, i, j, words[0].size()))
                    res.push_back(i);
            }
        }
        
        return res;
    }
};