#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(s[i]==' ') {
            i++;
        }
        if(s[i]=='+' || s[i]=='-' || (s[i]<='9' && s[i]>='0')) {
            int sign=1;
            if(s[i]=='+') {
                sign=1;
                i++;
            }
            else if(s[i]=='-') {
                sign=-1;
                i++;
            }
            while(s[i]=='0') {
                i++;
            }
            int count=0;
            int ind=i;
            while(s[i]<='9' && s[i]>='0') {
                count++;
                i++;
            }
            long long upper_limit=1;
            for(int j=0;j<31;j++) {
                upper_limit*=2;
            }
            int lower_limit=-(upper_limit);
            upper_limit-=1;
            if(count>10) {
                if(sign==1) {
                    return (int)upper_limit;
                }
                else {
                    return lower_limit;
                }
            }
            else {
                int res=0;
                while(count--) {
                    res*=10;
                    res+=(s[ind]-'0');
                    ind++;
                }
                return res;
            }
        }
        else {
            return 0;
        }
    }
};
int main() {
    string s="20000000000000000000";
    Solution a;
    int res=a.myAtoi(s);
    cout<<res<<endl;
}