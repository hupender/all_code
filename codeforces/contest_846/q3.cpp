#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int c[m];
    for(int i=0;i<m;i++) {
        cin>>c[i];
    }
    sort(c,c+m, greater<int>());
    map<int,int,greater<int>> map;
    for(int i=0;i<n;i++) {
        map[a[i]]++;
    }
    auto it=map.begin();
    int res=0;
    for(int i=0;i<m;i++) {
        int count=it->second;
        res+=min(count,c[i]);
        it++;
    }
    cout<<res<<endl;
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