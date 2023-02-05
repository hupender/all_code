#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    map<int,int> m;
    for(int i=0;i<n;i++) {
        m[a[i]]++;
    }
    vector<pair<int,int>> v;
    for(auto i:m) {
        v.push_back({i.first,i.second});
    }
    // sort(v.begin(),v.end());
    int n1=v.size();
    ll res=0;
    int val,count;
    for(int i=n1-1;i>=0;i--) {
        if(i==n1-1) {
            val=v[i].first;
            count=v[i].second;
        }
        else {
            if(v[i].first==val-1) {
                if(v[i].second>=count) {
                    count=v[i].second;
                }
                else {
                    res+=(count-v[i].second);
                    count=v[i].second;
                }
                val--;
            }
            else {
                res+=count;
                val=v[i].first;
                count=v[i].second;
                // i--;
            }
        }
    }
    cout<<res+count<<endl;
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