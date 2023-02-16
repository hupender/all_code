#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll v[3];
    v[0]=a;
    v[1]=b;
    v[2]=c;
    sort(v,v+3);
    a=v[0];
    b=v[1];
    c=v[2];
    ll res=0;
    if((c-a)%2==0) {
        ll val=(c-a)/2;
        res+=val;
        c-=val;
        a+=val;
        b+=val;
        if((b-a)%2==0) {
            ll val1=(b-a)/2;
            res+=val1;
            // b-=val1;
            // a+=val1;
            // c+=val1;
            cout<<res<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }

    }
    else {
        cout<<"-1"<<endl;
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