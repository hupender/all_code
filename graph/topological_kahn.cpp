#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<int> indegree(v);
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++) {
        int a=edges[i][0];
        int b=edges[i][1];
        indegree[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<v;i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int t=q.front();
        q.pop();
        ans.push_back(t);
        for(auto j:adj[t]) {
            indegree[j]--;
            if(indegree[j]==0) {
                q.push(j);
            }
        }
    }
    return ans;
}