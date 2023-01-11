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
        string s;
        cin>>s;
        int n=s.size();
        int ind=0;
        if(s[0]=='e' && s[1]=='s') {
            ind=2;
        }
        if(s[0]=='s') {
            ind=1;
        }
        int flag=1;
        for(int i=ind;i<n;i=i+3) {
            if(s[i]=='Y') {
                if(i+1<n) {
                    if(s[i+1]=='e') {
                        if(i+2<n) {
                            if(s[i+2]!='s') {
                                flag=0;
                                break;
                            }
                        }
                    }
                    else {
                        flag=0;
                        break;
                    }
                }
            }
            else {
                flag=0;
                break;
            }
        }
        if(n==1 && (s[0]=='Y' || s[0]=='e' || s[0]=='s')) {
            flag=1;
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}