#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    // pair<int,int> a[m];
    unordered_map<int,ll> map1;
    ll time=0;
    for(int i=0;i<m;i++) {
        // cin>>a[i].first>>a[i].second;
        int a,b;
        cin>>a>>b;
        if(map1[a]>0) {
            map1[a]+=b;
            time+=map1[a];
        }
        else {
            map1[a]=b;
            time+=b;
        }
        cout<<time<<endl;
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
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}