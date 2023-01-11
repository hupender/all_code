#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> v;
        for(int i=0;i<n-1;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        vector<pair<int,int>> edges;
        for(int i=0;i<n-1;i++) {
            edges.push_back({v[i],i+2});
        }
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n-1;i++) {
            int a=edges[i].first;
            int b=edges[i].second;
            adj[a].push_back(b);
        }
        vector<int> level(n+1);
        level[0]=-1;
        queue<int> q;
        q.push(1);
        int count=1;
        int l=0;
        while(!q.empty()) {
            while(count--) {
                int tar=q.front();
                level[tar]=l;
                q.pop();
                for(auto i:adj[tar]) {
                    q.push(i);
                    count++;
                }
            }
            l++;
        }
        sort(level.begin(),level.end());
        for(int i=)
    }
}