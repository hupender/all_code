#include<bits/stdc++.h>/
using namespace std;

vector<int> dijkastra(vector<vector<int>> &edges,int v,int e) {
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<e;i++) {
        int a=edges[i][0];
        int b=edges[i][1];
        int c=edges[i][2];
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    set<int,int> s;

}

int main() {
    int v,e;
    cout<<"no of vertices and edges"<<endl;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c}); 
    }
    vector<int> k=dijkastra(edges,v,e);
    for(int i=0;i<k.size();i++) {
        // Mistake
        cout<<k[i];
    }
}