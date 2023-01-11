#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=1e9;
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll size=1e9+1;
    // ll dp[size];
    vector<ll> dp(size,0);
    dp[0]=0;
    dp[1]=0;
    ll res=1;
    for(int i=2;i<=size;i++) {
        ll res1=i*(i-1);
        res1%=mod;
        res+=res1;
        res%=mod;
        dp[i]=res;
    }
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll ans=1011;
        ll first=n;
        ll second=n+1;
        ll third=2*n+1;
        if(first%3==0) {
            first/=3;
        }
        else if(second%3==0) {
            second/=3;
        }
        else {
            third/=3;
        }
        ans*=first;
        ans%=mod;
        ans*=second;
        ans%=mod;
        ans*=third;
        ans%=mod;
        ans+=dp[n];
        ans%=mod;
        cout<<ans<<endl;

    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}