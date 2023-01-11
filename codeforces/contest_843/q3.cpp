#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        vector<int> v1;
        for(int j=0;j<k;j++) {
            int a;
            cin>>a;
            v1.push_back(a);
            m[a]++;
        }
        v.push_back(v1);
    }
    int flag=0;
    for(int i=0;i<n;i++) {
        int flag1=1;
        for(int j=0;j<v[i].size();j++) {
            m[v[i][j]]--;
            if(m[v[i][j]]==0) {
                flag1=0;
            }
        }
        if(flag1) {
            flag=1;
        }
        if(flag) {
            break;
        }
        for(int j=0;j<v[i].size();j++) {
            m[v[i][j]]++;
        }
    }
    if(flag) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
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