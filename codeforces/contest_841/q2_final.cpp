#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=1e9+7;
void solve() {
    ll n;
    cin>>n;
    ll res1=(n*(n-1))/2;
    res1%=mod;
    res1*=2022;
    res1%=mod;
    ll res2=4*n*n+2;
    res2%=mod;
    res2*=(n);
    res2%=mod;
    res2*=337;
    res2%=mod;
    ll res=res1+res2;
    res%=mod;
    cout<<res<<endl;
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