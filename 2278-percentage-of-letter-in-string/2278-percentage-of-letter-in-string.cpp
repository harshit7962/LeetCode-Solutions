class Solution {
public:
    int percentageLetter(string s, char letter) {
        int x=0;
        for(auto c:s)
            if(c==letter) x++;
        
        return x*100/s.size();
    }
};