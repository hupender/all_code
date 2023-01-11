#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    vector<int> v;
    int mi=INT_MAX;
    map<int,vector<int>> m;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        m[k].push_back(i);
        v.push_back(k);
        if(k<mi) {
            mi=k;
        }
    }
    int flag=1;
    int d;
    map<int,int> m1;
    for(auto i:m) {
        if(flag==1) {
            for(auto j:i.second) {
                m1[j]=i.first;
            }
            d=i.first;
            flag=0;
        }
        else {
            int x=i.first;
            int r=x%d;
            if(r!=0) {
                x+=(d-r);
            }
            for(auto j:i.second) {
                m1[j]=x;
            }
            d=x;
        }
    }
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++) {
        if(v[i]<m1[i]) {
            p.push_back({i+1,m1[i]-v[i]});
        }
    }
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++) {
        cout<<p[i].first<<" "<<p[i].second<<endl;
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