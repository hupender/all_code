#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    if(n%2==0) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        vector<pair<int,int>> res;
        vector<int> v2;
        for(int i=n+1;i<=2*n;i++) {
            v2.push_back(i);
        }
        int sum=2*n+1;
        res.push_back({v2[0],sum-v2[0]});
        int i=1;
        sum--;
        for(i=1;i<=n/2;i++) {
            int a=v2[i];
            int b=sum-a;
            sum--;
            res.push_back({a,b});
        }
        sum=2*n+1+n/2;
        for(;i<n;i++) {
            int a=v2[i];
            int b=sum-a;
            sum--;
            res.push_back({a,b});
        }
        for(int i=0;i<n;i++) {
            cout<<res[i].first<<" "<<res[i].second<<endl;
        }
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