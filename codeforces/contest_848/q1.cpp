#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m,d;
    cin>>n>>m>>d;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int b[m];
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    unordered_map<int,int> map1;
    for(int i=0;i<n;i++) {
        map1[a[i]]=i;
    }
    ll count=0;
    for(int i=0;i<m-1;i++) {
        int pos1=map1[b[i]];
        int pos2=map1[b[i+1]];
        if(pos1<pos2 && pos2<=pos1+d) {
            int res1=pos2-pos1;
            int res2;
            if(pos1+d>=n-1) {
                res2=INT_MAX;
            }
            else {
                res2=pos1+d-pos2+1;
            }
            count+=min(res1,res2);
        }
    }
    cout<<count<<endl;
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