class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target>=letters[letters.size()-1] || target<letters[0]) return letters[0];
        
        int low = 0, high =letters.size()-1;
        
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