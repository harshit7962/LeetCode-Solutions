class Solution {
public:
    bool contains(string word1, string word2) {
        int i=0, j=word1.size();
        while((i+j)<=word2.size()) {
            if(word1 == word2.substr(i,j)) return true;
            i++;
        }
        return false;
    }
    
    int numOfStrings(vector<string>& patterns, string word) {
        int res=0;
        
        for(int i=0;i<patterns.size();i++) {
            if(contains(patterns[i], word)) res++;
        }
        return res;
    }
};