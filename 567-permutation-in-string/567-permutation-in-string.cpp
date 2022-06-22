class Solution {
public:
    bool hasSameFreq(string s, int start, int end, vector<int> freq_count) {
        vector<int> curr_count(26,0);
        for(int i=start;i<=end;i++) curr_count[s[i]-'a']++;
        
        return freq_count==curr_count;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> freq_count(26, 0);
        
        int h1=0, h2=0;
        for(int i=0;i<s1.size();i++) {
            freq_count[s1[i]-'a']++;
            h1+=(s1[i]-'a');
            h2+=(s2[i]-'a');
        }
        
        if(h1==h2) {
            if(hasSameFreq(s2, 0, s1.size()-1, freq_count)) return true;
        }
        
        for(int i=s1.size();i<s2.size();i++) {
            h2+=s2[i]-s2[i-s1.size()];
            if(h1==h2 && hasSameFreq(s2, i-s1.size()+1, i, freq_count)) return true;
        }
        
        return false;
    }
};