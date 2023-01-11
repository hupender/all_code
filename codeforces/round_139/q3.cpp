#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int flag=1;
        for(int i=0;i<n-1;i++) {
            if(s1[i]=='B') {
                if(s1[i+1]=='B' || s2[i]=='B') {
                    continue;
                }
                else {
                    flag=0;
                    break;
                }
            }
        }
        for(int i=0;i<n-1;i++) {
            if(s2[i]=='B') {
                if(s2[i+1]=='B' || s1[i]=='B') {
                    continue;
                }
                else {
                    flag=0;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if((i!=0 && i!=n-1) && s1[i]=='B') {
                if(s1[i+1]=='B' || s1[i-1]=='B') {
                    continue;
                }
                else {
                    flag=0;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if((i!=0 && i!=n-1) && s2[i]=='B') {
                if(s2[i+1]=='B' || s2[i-1]=='B') {
                    continue;
                }
                else {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}