#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> v;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    int count=0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int count1=0;
            for(int k=0;k<m;k++) {
                if(v[i][k]=='o' || v[j][k]=='o') {
                    count1++;
                }
            }
            if(count1==m) {
                count++;
            }
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