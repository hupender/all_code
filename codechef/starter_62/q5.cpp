#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c1=0,c2=0;
        for(int i=0;i<n-1;i++) {
            if(s[i]=='0' && s[i+1]=='1') {
                c1++;
            }
        }
        if(s[n-1]=='0') {
            if(s[0]=='0') {
                cout<<c1<<endl;
            }
            else {
                // cout<<c2<<endl;
                cout<<c1+1<<endl;
            }
        }
        else {
            if(s[0]=='0') {
                cout<<c1-1<<endl;
            }
            else {
                // cout<<c2<<endl;
                cout<<c1<<endl;
            }
        }
    }
}