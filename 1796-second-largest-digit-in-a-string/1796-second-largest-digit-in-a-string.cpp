class Solution {
public:
    int secondHighest(string s) {
        int largest=-1, secondlargest=-1;
        
        for(char c:s) {
            if(c>='0' && c<='9') {
                if(largest < (c-'0')) {
                    secondlargest = largest;
                    largest = c-'0';
                } else if(largest!=(c-'0') && secondlargest<(c-'0')) {
                    secondlargest=(c-'0');
                }
            }
        }
        
        return secondlargest;
    }
};