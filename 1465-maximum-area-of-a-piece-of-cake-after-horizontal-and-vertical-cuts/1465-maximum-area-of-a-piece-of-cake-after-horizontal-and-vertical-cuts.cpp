class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_w=verticalCuts[0], max_h=horizontalCuts[0];
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        for(int i=1;i<horizontalCuts.size();i++)
            max_h =  max(max_h, horizontalCuts[i]-horizontalCuts[i-1]);
        
        for(int i=1;i<verticalCuts.size();i++)
            max_w = max(max_w, verticalCuts[i]-verticalCuts[i-1]);
        
        return ((long long)max_w*(long long)max_h)%1000000007;
    }
};