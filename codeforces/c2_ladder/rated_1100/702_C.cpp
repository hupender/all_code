#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    ll n;
    cin>>n;
    int p=cbrt(n);
    int flag=0;
    for(ll i=1;i<=p;i++) {
        ll r=i*i*i;
        r=n-r;
        if(r!=0) {
            ll r1=cbrt(r);
            if(r1*r1*r1==r) {
                flag=1;
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