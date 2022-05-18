class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
        
        auto fnd = mp.find(s[s.length()-1]);
        int curr = fnd->second;
        int num=curr;
        for(int i=s.length()-2;i>=0;i--) {
            auto fnd = mp.find(s[i]);
            if(fnd->second<curr) num-=fnd->second;
            else num+=fnd->second;
            curr = fnd->second;
        }
        return num;
        
    }
};