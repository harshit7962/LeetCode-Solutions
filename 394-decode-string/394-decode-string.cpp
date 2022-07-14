class Solution {
public:
    string decodeString(string s) {
        string curr = "", res = "";
        stack<int> numbers;
        stack<string> result;
        
        int i=0;
        
        while(i<s.size()) {
            if(s[i]>='0' && s[i]<='9') {
                int num = s[i++]-'0';
                while(s[i]>='0' && s[i]<='9') {
                    num=num*10 + (s[i]-'0');
                    i++;
                }
                numbers.push(num);
            } else if(s[i]=='[') {
                result.push(curr);
                curr = "";
                i++;
            } else if(s[i]==']') {
                int num = numbers.top();
                numbers.pop();
                string temp = curr;
                
                while(num>1) {
                    temp += curr;
                    num--;
                }
                
                temp = result.top()+temp;
                result.pop();
                
                curr = temp;
                i++;                
            } else {
                curr+=s[i];
                i++;
            }
        }
        
        return curr;        
    }
};