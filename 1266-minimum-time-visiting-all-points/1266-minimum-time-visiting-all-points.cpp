class Solution {
public:
    int cost(vector<int> v1, vector<int> v2) {
        int x1 = v1[0], y1 = v1[1], x2 = v2[0], y2 = v2[1];
        int res=0;
        while(x1!=x2 && y1!=y2) {
            if(x1<x2) x1++;
            else x1--;
            if(y1<y2) y1++;
            else y1--;
            res++;
        }
        while(x1!=x2) {
            if(x1<x2) x1++;
            else x2++;
            res++;
        }
        while(y1!=y2) {
            if(y1<y2) y1++;
            else y1--;
            res++;
        }
        
        return res;
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i=1;i<points.size();i++) {
            res+=cost(points[i-1], points[i]);
        }
        
        return res;
    }
};