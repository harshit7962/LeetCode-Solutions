class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.",
                            "--.","....","..", ".---","-.-",".-..","--","-.",
                            "---",".--.", "--.-",".-.","...","-","..-","...-",
                            ".--","-..-", "-.--","--.."};
        
        set<string> st;
        for(int i=0;i<words.size();i++) {
            string curr="";
            for(auto c: words[i]) {
                curr+=v[c-'a'];
            }
            st.insert(curr);
        }
        return st.size();
    }
};