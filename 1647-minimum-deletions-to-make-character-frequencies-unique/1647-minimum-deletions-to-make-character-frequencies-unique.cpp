class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(char c:s) v[c-'a']++;
        sort(v.begin(), v.end(), greater<int>());
        
        int res=0;
        for(int i=1;i<26;i++) {
            if(v[i]==0) break;
            while(v[i]!=0 && v[i]>=v[i-1]) {res++;v[i]--;}
        }
        
        return res;
    }
};