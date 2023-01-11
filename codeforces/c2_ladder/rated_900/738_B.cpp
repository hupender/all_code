#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ind=-1;
    for(int i=0;i<n;i++) {
        if(s[i]!='?') {
            ind=i;
            break;
        }
    }
    if(ind>0) {
        for(int i=ind-1;i>=0;i--) {
            if(s[i+1]=='R') {
                s[i]='B';
            }
            else {
                s[i]='R';
            }
        }
    }
    // comment
    if(ind==-1) {
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                s[i]='B';
            }
            else {
                s[i]='R';
            }
        }
        cout<<s<<endl;
    }
    else {
        for(int i=ind;i<n;i++) {
            if(s[i]=='?') {
                while(s[i]=='?') {
                    if(s[i-1]=='R') {
                        s[i]='B';
                    }
                    else {
                        s[i]='R';
                    }
                    i++;
                }
            }
        }
        cout<<s<<endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}