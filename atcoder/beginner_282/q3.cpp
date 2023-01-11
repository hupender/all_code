#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int flag=1;
    for(int i=0;i<n;i++) {
        if(flag) {
            while(i<n && s[i]!='"') {
                if(s[i]==',') {
                    s[i]='.';
                }
                i++;
            }
            flag=0;
        }
        else {
            while(i<n && s[i]!='"') {
                i++;
            }
            flag=1;
        }
    }
    cout<<s<<endl;
}
void solve1() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int st=n;
    for(int i=0;i<n;i++) {
        if(s[i]=='"') {
            st=i;
            break;
        }
    }
    int end=-1;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='"') {
            end=i;
            break;
        }
    }
    for(int i=0;i<st;i++) {
        if(s[i]==',') {
            s[i]='.';
        }
    }
    for(int i=n-1;i>end;i--) {
        if(s[i]==',') {
            s[i]='.';
        }
    }
    cout<<s<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--) {
    //     solve();
    // }
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}