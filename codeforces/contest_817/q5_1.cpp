#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
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
        int n,q;
        cin>>n>>q;
        ll v[1001][1001];
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            v[a][b]+=a*b;
        }
        for(int i=1;i<1001;i++) {
            for(int j=1;j<1001;j++) {
                v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            }
        }
        // for(int i=0;i<1001;i++) {
        //     for(int j=0;j<1001;j++) {
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        while(q--) {
            int h1,b1,h2,b2;
            cin>>h1>>b1>>h2>>b2;
            ll res;
            res=v[h2-1][b2-1]-v[h1][b2-1]-v[h2-1][b1]+v[h1][b1];
            cout<<res<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}