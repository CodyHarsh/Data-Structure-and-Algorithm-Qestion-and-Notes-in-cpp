int myAtoi(string s) {
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z') || s[i]=='.') return 0;
                else if('0'<=s[i] && s[i]<='9'){
                    while('0'<=s[i] && s[i]<='9'){
                        ans = ans*10 + (s[i]-'0');
                        if(INT_MAX<=ans) return INT_MAX;
                        i++;
                    }
                    return ans;
                }
                else if(s[i]=='+' || s[i]=='-'){
                    char ch = s[i];
                    i++;
                    while('0'<=s[i] && s[i]<='9'){
                        if(ch=='+') ans = ans*10 + (s[i]-'0');
                        else if(ch=='-') ans = ans*10 - (s[i]-'0');
                        i++;
                        if(INT_MAX<=ans) return INT_MAX;
                        else if(INT_MIN>=ans) return INT_MIN;
                    }
                    return ans;
                }
            }
        }
        return ans;
