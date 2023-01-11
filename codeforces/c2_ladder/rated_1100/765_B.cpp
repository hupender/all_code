#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    unordered_map<int,vector<int>> m;
    for(int i=0;i<n;i++) {
        m[a[i]].push_back(i);
    }
    int ans=-1;
    for(auto i:m) {
        vector<int> v=i.second;
        if(v.size()>1) {
            int res=-1;
            int n1=v.size();
            for(int i=0;i<n1-1;i++) {
                int res1=v[i]+(n-v[i+1]);
                res=max(res,res1);
            }
            ans=max(ans,res);
        }
    }
    cout<<ans<<endl;
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