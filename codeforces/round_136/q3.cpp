#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
const ll mod=998244353;
// ll fact(int n) {
//     ll res=1;
//     for(int i=1;i<=n;i++) {
//         res*=i;
//         res%=mod;
//     }
//     return res;
// }
// ll nCr(int n,int r) {
//     ll a=fact(n);
//     ll b=fact(r);
//     ll c=fact(n-r);
//     ll res=a/b;
//     res/=c;
//     return res;
// }
ll nCr(int n,int r) {
    r=min(r,n-r);
    ll res=1;
    for(int i=1;i<=r;i++) {
        res=(res*n)/i;
        n--;
    }
    return res;
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
    ll a[61]={0};
    ll b[61]={0};
    ll draw=1;
    ll total[61]={0};
    for(int i=2;i<61;i+=2) {
        a[i]=(nCr(i-1,(i/2)-1)+b[i-2])%mod;
        total[i]=(nCr(i,i/2))%mod;
        b[i]=total[i]-draw-a[i];
        if(b[i]<0) {
            b[i]+=mod;
        }
    }
    while(t--) {
        int n;
        cin>>n;
        cout<<a[n]<<" "<<b[n]<<" "<<draw<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}