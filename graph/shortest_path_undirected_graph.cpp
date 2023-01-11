#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<m;i++) {
        int a=edges[i].first;
        int b=edges[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n);
    vector<bool> visited(n);
    // unordered_map<int,int> parent;
    // unordered_map<int,bool> visited;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()) {
        int p=q.front();
        q.pop();
           for(auto j:adj[p]) {
               if(!visited[j]) {
                   parent[j]=p;
                   visited[j]=true;
                   q.push(j);
                }
            }
    }
    vector<int> v;
    int j=t;
    while(j!=s) {
        v.push_back(j);
        j=parent[j];
    }
    v.push_back(s);
    reverse(v.begin(),v.end());
    return v;
}





int main() {
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> edges;
    for(int i=0;i<e;i++) {
        pair<int,int> p;
        int a,b;
        cin>>a>>b;
        p={a,b};
        edges.push_back(p);
    }
    int s,t;
    cin>>s>>t;
    vector<int> k=shortestPath(edges,v,e,s,t);
    for(int i=0;i<k.size();i++) {
        cout<<k[i];
    }
}
