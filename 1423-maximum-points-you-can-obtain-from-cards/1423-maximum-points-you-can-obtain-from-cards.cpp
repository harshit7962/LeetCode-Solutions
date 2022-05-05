class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0, n=cardPoints.size();
        for(int i=0;i<k;i++) total+=cardPoints[i];
        
        int maxPoints=total;
        for(int i=k-1;i>=0;i--) {
            total = total-cardPoints[i]+cardPoints[n+i-k];
            maxPoints = max(maxPoints, total);
        }
        return maxPoints;
    }
};