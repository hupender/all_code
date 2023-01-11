#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    ll a,b;
    cin>>a>>b;
    ll p=a*b;
    if(b==1) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        ll z=4*a*b;
        ll x;
        x=a*(b+1);
        ll y=z-x;
        cout<<x<<" "<<y<<" "<<z<<endl;
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