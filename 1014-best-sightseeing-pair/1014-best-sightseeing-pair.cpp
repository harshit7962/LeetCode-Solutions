class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res=0, maxv=values[0], maxi=0;
        
        for(int i=1;i<values.size();i++) {
            res = max(res, (maxv+values[i]+(maxi-i)));
            
            if(maxv+maxi<=i+values[i]) {
                maxv=values[i];
                maxi=i;
            }
        }
        
        return res;
    }
};