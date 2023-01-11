#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    ll n,x,t;
    cin>>n>>x>>t;
    ll r=t/x;
    ll n1=(n-1)*x-t;

    if(n1<0) {
        n1=0;
    }
    ll re=n1%x;
    n1/=x;
    if(re!=0) {
        n1++;
    }
    ll res=n1*r;
    ll rem=n-n1;
    ll res1=rem*(rem-1);
    res1/=2;
    cout<<res+res1<<endl;
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

// ll r=t/x;
//     ll r1=n*x-t;
//     r1/=x;
//     if(r1%x==0) {
//         r1--;
//     }
//     ll res=r*r1;
//     res+=(r*(r+1))/2;
//     cout<<res<<endl;