class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);

        sort(arr.begin(), arr.end());
        
        int min_diff = arr[1]-arr[0];
        for(int i=2;i<arr.size();i++) min_diff = min(min_diff, arr[i]-arr[i-1]);
        
        vector<vector<int>> res;
        for(int i=1;i<arr.size();i++) {
            if(arr[i]-arr[i-1]==min_diff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};