#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
ll gcd(ll a,ll b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    ll sum1=a[0],sum2=sum-a[0];
    ll g=gcd(sum1,sum2);
    for(int i=1;i<n-1;i++) {
        sum1+=a[i];
        sum2-=a[i];
        ll g1=gcd(sum1,sum2);
        g=max(g,g1);
    }
    cout<<g<<endl;
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