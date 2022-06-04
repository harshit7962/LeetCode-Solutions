class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> col;
    unordered_set<int> negD;
    unordered_set<int> posD;
    int size;
    
    void help(int n, vector<string>& prev)
    {
        if(n < 0)
        {
            ans.push_back(prev);
            return;
        }
        for(int i = 0; i < size; i++)
        {
            if(col.find(i) == col.end() && negD.find(n-i) == negD.end() && posD.find(n+i) == posD.end())
            {
                col.insert(i);
                negD.insert(n-i);
                posD.insert(n+i);
                string s = "";
                for(int j = 0; j < size; j++)
                {
                    if(i == j) s+='Q';
                    else s+='.';
                }
                prev.push_back(s);
                help(n-1,prev);
                
                // backtracking part
                prev.pop_back();
                col.erase(col.find(i));
                negD.erase(negD.find(n-i));
                posD.erase(posD.find(n+i));
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<string> prev;
        help(n-1,prev);
        return ans;
    }
};