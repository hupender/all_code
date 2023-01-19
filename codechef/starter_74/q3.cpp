#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    int n;
    cin>>n;
    int a[n];
    map<int,int> m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m[a[i]]++;
    }
    unordered_map<int,int> visited;
    vector<ll> v;
    ll res=0;
    for(int i=n-1;i>=0;i--) {
        res-=visited[a[i]];
        m[a[i]]--;
        a[i]++;
        visited[a[i]]++;
        res+=m[a[i]];
        v.push_back(res);
    }
    res=0;
    for(int i=0;i<v.size();i++) {
        res=max(res,v[i]);
    }
    cout<<res<<endl;
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    map<int,vector<int>> m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m[a[i]].push_back(i);
    }
    
    int res=0;
    int final_res=0;
    int last_ind=0;
    unordered_map<int,int> index;
    for(int i=0;i<n;i++) {
        if(i>last_ind) {
            res=0;
        }
        int res1=0;
        if(index[i]>0) {
            res1-=index[i];
        }
        for(auto j:m[a[i]-1]) {
            last_ind=j;
            res1++;
            index[j]++;
        }
        m.erase(a[i]);
        res+=res1;
        final_res=max(res,final_res);
    }
    cout<<final_res<<endl;
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}