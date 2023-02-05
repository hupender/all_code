#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=1e9+7;
void solve() {
    ll n;
    cin>>n;
    ll sum=n*(n-1);
    sum%=mod;
    ll fact=1;
    for(int i=1;i<=n;i++) {
        fact*=i;
        fact%=mod;
    }
    ll res=(sum*fact)%mod;
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