class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int top=0, bottom=n-1, left=0, right=n-1, curr=1;
        while(top<=right && left<=right) {
            for(int i=left;i<=right;i++) res[top][i] = curr++;
            top++;
            for(int i=top;i<=bottom;i++) res[i][right] = curr++;
            right--;
            if(bottom>=top) {
                for(int i=right;i>=left;i--) res[bottom][i] = curr++;
                bottom--;
            }
            if(left<=right) {
                for(int i=bottom;i>=top;i--) res[i][left] = curr++;
                left++;
            }
        }
        return res;
    }
};