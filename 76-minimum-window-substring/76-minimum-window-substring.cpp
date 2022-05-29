class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, smap;
        for(char c:t) tmap[c]++;
        
        int i=0, j=0, matchcount=0;
        string res="";
        while(j<s.size()) {
            //Acquire
            while(j<s.size() && matchcount!=t.size()) {
                smap[s[j]]++;
                if(smap[s[j]]<=tmap[s[j]]) matchcount++;
                j++;
            }
            
            //Release
            while(matchcount==t.size()) {
                smap[s[i]]--;
                if(smap[s[i]]<tmap[s[i]]) matchcount--;
                
                string curr = s.substr(i, j-i);
                i++;
                if(res=="" || res.size()>curr.size()) res=curr;
            }
        }
        
        return res;
    }
};