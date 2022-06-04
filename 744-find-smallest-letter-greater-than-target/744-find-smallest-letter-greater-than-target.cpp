class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(target<letters[0] || target>=letters[n-1]) return letters[0];
        
        int low=0, high=n-1;
        char res;
        while(low<=high) {
            int mid = (low+high)/2;
            if(letters[mid]<=target) low = mid+1;
            else {
                res = letters[mid];
                high = mid-1;
            }
        }
        return res;
    }
};