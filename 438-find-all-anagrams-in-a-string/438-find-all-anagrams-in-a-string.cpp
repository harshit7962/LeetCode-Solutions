class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        sort(p.begin(), p.end());
        
        vector<int> pfreq(26, 0), sfreq(26, 0);
        
        for(int i=0;i<p.size();i++) {
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }
        
        vector<int> res;
        if(pfreq==sfreq) res.push_back(0);
        
        for(int i=p.size();i<s.size();i++) {
            sfreq[s[i]-'a']++;
            sfreq[s[i-p.size()]-'a']--;
            
            if(pfreq==sfreq) res.push_back(i-p.size()+1);
        }
        
        return res;
    }
};