class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(), res=0;
        
        for(int i=0;i<k;i++) res+=cardPoints[i];
        int curr_sum=res;
        int j=1;
        for(int i=k-1;i>=0;i--) {
            // cout << curr_sum << endl;
            curr_sum = curr_sum-cardPoints[i]+cardPoints[n-j];
            j++;
            res=max(res, curr_sum);
        }
        return res;
    }
};