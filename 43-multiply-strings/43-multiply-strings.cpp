class Solution {
public:
    string add(string n1, string n2) {
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        
        int carry = 0;
        string res = "";
        
        for(int i=0;i<n1.size() && i<n2.size();i++) {
            int x = (n1[i]-'0') + (n2[i]-'0') + carry;
            
            carry = x/10;
            x = x%10;
            
            res+=(x+48);
        }
        
        if(n1.size()>n2.size()) {
            int i=n2.size();
            while(i<n1.size()){
                int x = (n1[i]-'0') + carry;
                
                carry = x/10;
                x = x%10;
                
                res+=(x+48);
                i++;
            }
        }
        
        if(n2.size()>n1.size()) {
            int i = n1.size();
            while(i<n2.size()) {
                int x = (n2[i]-'0') + carry;
                
                carry = x/10;
                x = x%10;
                
                res+=(x+48);
                i++;
            }
        }
        if(carry!=0) res+=(carry+48);
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    string multiply(string num1, string num2) {
        if(num1=="0" ||  num2=="0") return "0";
        string res;
        int s2=num2.size(), s1=num1.size();
        
        for(int i=s2-1;i>=0;i--) {
            string curr = "";
            
            for(int j=0;j<s2-i-1;j++) curr+="0";
            
            int carry=0;
            for(int j=s1-1;j>=0;j--) {
                int x = (num2[i]-'0')*(num1[j]-'0') + carry;
                
                carry = x/10;
                x=x%10;
                
                char c = (x+48);
                curr = c+curr;
            }
            if(carry!=0) curr = ((char)(carry+48)) + curr;

            res = add(res, curr);
        }
        
        return res;
    }
};