class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int idx = 0;
        int sign = 1;
        long int ans = 0;
        while(idx<n && s[idx]==' '){
            idx++;
        } 
        if(idx<n && (s[idx]=='-'|| s[idx]=='+') ){
            if(s[idx]=='-'){
            sign = -1;
            }
            idx++;
        }
        while(idx<n && isdigit(s[idx])){
            int digit = s[idx] - '0';
            
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            idx++;
        }
        return (int)sign*ans;
    }
};