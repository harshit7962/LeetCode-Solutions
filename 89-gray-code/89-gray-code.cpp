class Solution {
public:
    vector<string> backTrack(int n) {
        if(n == 1) {
            return {"0", "1"};
        }
        
        vector<string> aux = backTrack(n-1);
        vector<string> res;
        for(int i=0;i<aux.size();i++) {
            res.push_back('0'+aux[i]);
        }
        for(int i=aux.size()-1;i>=0;i--) {
            res.push_back('1'+aux[i]);
        }
        
        return res;
    }
    
    vector<int> convertDec(vector<string> &bin) {
        vector<int> res;
        for(string s: bin) {
            res.push_back(stoi(s, 0, 2));
        }
        
        return res;
    }
    
    vector<int> grayCode(int n) {
        vector<string> x = backTrack(n);
        return convertDec(x);
    }
};