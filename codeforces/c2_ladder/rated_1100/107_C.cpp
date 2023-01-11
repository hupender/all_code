#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    // vector<pair<int,int>> v;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        if(m[a[i]]==0) {
            m[a[i]]=i+1;
        }
    }

    while(q--) {
        int t;
        cin>>t;
        int ind;
        for(auto &i:m) {
            if(i.first==t) {
                ind=i.second;
                cout<<ind<<" ";
                break;
            }
        }
        for(auto &i:m) {
            if(i.second<ind) {
                i.second++;
            }
        }
        m[t]=1;
    }
    cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--) {
    solve();
    // }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}