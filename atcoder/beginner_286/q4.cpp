#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,x;
    cin>>n>>x;
    pair<int,int> a[n];
    vector<int> v;
    for(int i=0;i<n;i++) {
        int p,q;
        cin>>p>>q;
        a[i]={p,q};
        while(q--) {
            v.push_back(p);
        }
    }
    int size=v.size();
    int dp[size];
    for(int i=0;i<size;i++) {
        dp[i]=
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