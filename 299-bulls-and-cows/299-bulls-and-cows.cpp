class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        vector<pair<int, int>> c(10, {0, 0});
        
        for(int i=0;i<secret.size();i++) {
            if(secret[i]==guess[i]) bulls++;
            else {
                c[secret[i]-'0'].first++;
                c[guess[i]-'0'].second++;
            }
        }
        
        for(int i=0;i<10;i++) {
            cows+=min(c[i].first, c[i].second);
        }
        
        return (to_string(bulls)+"A"+to_string(cows)+"B");
    }
};