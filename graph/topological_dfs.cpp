#include<bits/stdc++.h> 
using namespace std;
stack<int> s;
void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int k) {
    visited[k]=1;
    for(auto i:adj[k]) {
        if(!visited[i]) {
            dfs(adj,visited,i);
        }
    }
    s.push(k);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++) {
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
    }
    vector<int> ans;
    vector<bool> visited(v);
    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            dfs(adj,visited,i);
        }
    }
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
