class Solution {
public:
    string removeDigit(string number, char digit) {
        int ind=-1;
        for(int i=0;i<number.size();i++) {
            if(number[i]==digit && number[i]<number[i+1]) {
                ind=i;
                break;
            } else if(number[i]==digit) {
                ind=i;
            }
        }
        
        return number.substr(0, ind)+number.substr(ind+1);
    }
};