class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        vector<int> v = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        
        for(string word:words) {
            bool isOk=true;
            for(int i=1;i<word.size();i++) {
                if(v[tolower(word[i-1])-'a']!=v[tolower(word[i])-'a']) {
                    isOk=false;
                    break;
                }
            }
            if(isOk) res.push_back(word);
        }
        
        return res;
    }
};