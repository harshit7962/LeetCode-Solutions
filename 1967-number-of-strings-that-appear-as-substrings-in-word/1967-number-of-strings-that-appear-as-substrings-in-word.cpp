class Solution {
public:    
    int numOfStrings(vector<string>& patterns, string word) {
        int res=0;
        
        for(int i=0;i<patterns.size();i++) {
            int pos = word.find(patterns[i]);
            if(pos>=0) res++;
        }
        
        return res;
    }
};