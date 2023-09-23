#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    unordered_map<int,vector<int>> map1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        map1[i].push_back(a[i]);
    }
    for(int i=0;i<m;i++) {
        int ind,val;
        cin>>ind>>val;
        map1[ind-1].push_back(val);
    }
    cout<<" "<<endl;
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