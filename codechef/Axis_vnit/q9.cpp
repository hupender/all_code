#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int k;
    cin>>k;
    vector<int> bad;
    for(int i=0;i<k;i++) {
        int a;
        cin>>a;
        bad.push_back(a);
    }
    // get adjacency list
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int a=v[i].first;
        int b=v[i].second;
        adj[a].push_back(b);
    }
    // first get those points which we can reach from node 1
    vector<bool> reachable(n+1,false);
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int a=q.front();
        reachable[a]=true;
        q.pop();
        for(auto i:adj[a]) {
            q.push(i);
        }
    }
    vector<int> bad_reachable;
    for(int i=0;i<k;i++) {
        if(reachable[bad[i]]) {
            bad_reachable.push_back(bad[i]);
        }
    }
    // check if we can reach end from these bad reachable points
    vector<bool> visited(n+1,false);
    int n1=bad_reachable.size();
    int flag=1;
    for(int i=0;i<n1;i++) {
        int a=bad_reachable[i];
        if(!visited[a]) {
            queue<int> q1;
            q1.push(a);
            while(!q1.empty()) {
                int b=q1.front();
                q1.pop();
                if(b==n) {
                    flag=0;
                }
                for(auto it:adj[b]) {
                    if(it==n) {
                        flag=0;
                        break;
                    }
                    q1.push(it);
                    visited[it]=true;
                }
                if(flag) {
                    break;
                }
            }
            if(flag) {
                break;
            }
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