class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> tmap, smap;
        for(char c:target) tmap[c]++;
        
        for(char c:s) if(tmap.find(c)!=tmap.end()) smap[c]++;

        int res=INT_MAX;
        for(auto x:tmap) {
            res = min(res, smap[x.first]/x.second);
        }
        return res;
    }
};