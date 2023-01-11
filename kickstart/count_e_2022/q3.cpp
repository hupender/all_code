#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(string s) {
    int i=0,j=s.length()-1;
    while(i<j) {
        if(s[i]!=s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,flag;
        cin>>n;
        string s;
        cin>>s;
        string ans;
        for(int i=0;i<s.size();i++) {
            flag=0;
            ans+=s[i];
            string t;
            reverse(ans.begin(),ans.end());
            if(check_palindrome(ans)) {
                t=s+ans;
                if(check_palindrome(t)) {
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                reverse(ans.begin(),ans.end());
            }
        }
        cout<<ans<<endl;
    }
}