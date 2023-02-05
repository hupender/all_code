#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int count_same=0;
    for(int i=0;i<n;i++) {
        if(a[i]==b[i]) {
            count_same++;
        }
    }
    int count_different=n-count_same;
    if(count_different%2!=0) {
        cout<<"0"<<endl;
    }
    else {
        ll res=1;
        ll count_pairs=(count_different*(count_different-1))/2;
        int n1=(count_different/2)+count_same;
        while(n1--) {
            res*=2;
            res%=mod;
        }
        cout<<res<<endl;
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