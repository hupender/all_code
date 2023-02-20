#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,w;
    cin>>n>>w;
    pair<int,int> a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    ll dp[n+1][w+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=w;j++) {
            if(i==0 || j==0) {
                dp[i][j]=0;
            }
            else {
                ll res1=0,res2=0;
                res1=dp[i-1][j];
                if(a[i-1].first<=j) {
                    res2=dp[i-1][j-a[i-1].first]+a[i-1].second;
                }
                dp[i][j]=max(res1,res2);
            }
        }
    }
    cout<<dp[n][w]<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}