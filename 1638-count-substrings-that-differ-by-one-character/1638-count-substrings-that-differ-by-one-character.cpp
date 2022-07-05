class Solution {
public:
    int countSubstrings(string s, string t) {
        int n1 = s.size(), n2=t.size(), res=0;
        
        for(int i=0;i<n1;i++) {
            for(int j=0;j<n2;j++) {
                int x=i, y=j, dist=0;
                
                while(x<n1 && y<n2) {
                    if(s[x]!=t[y]) dist++;
                    if(dist==1) res++;
                    if(dist==2) break;
                    x++;
                    y++;
                }
            }
        }
        
        
        return res;
    }
};