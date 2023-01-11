#include<bits/stdc++.h>
using namespace std;

void get_topological(unordered_map<int,vector<pair<int,int>>> &adj,vector<bool> &visited,int k,stack<int> &s) {
    visited[k]=1;
    for(auto i:adj) {
        if(!visited[i.first]) {
            get_topological(adj,visited,i.first,s);
        }
    }
    s.push(k);
}

vector<int> get_minimum_distance(int v,int e,vector<vector<int>> &edges,int st) {
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<e;i++) {
        int a=edges[i][0];
        int b=edges[i][1];
        int c=edges[i][2];
        pair<int,int> p;
        p.first=b;
        p.second=c;
        adj[a].push_back(p);
    }
    vector<bool> visited(v);
    stack<int> s;
    get_topological(adj,visited,0,s);
    
    vector<int> result(v,INT_MAX);
    result[st]=0;
    while(!s.empty()) {
        int p=s.top();
        s.pop();
        if(p!=INT_MAX) {
            for(auto i:adj[p]) {
                result[i.first]=min(result[i.first],i.second);
            }
        }
    }
    return result;
}

int main() {
    int v,e;
    cout<<"enter no of vertices and edges"<<endl;
    cin>>v>>e;
    vector<vector<int>> edges(e);
    cout<<"enter edges along with  their values"<<endl;
    for(int i=0;i<e;i++) {
        vector<int> p;
        int a,b,c;
        cin>>a>>b>>c;
        // p={a,b,c};
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
        edges.push_back(p);
    }
    cout<<"enter start node"<<endl;
    int st;
    cin>>st;
    vector<int> x=get_minimum_distance(v,e,edges,st);
    for(int i=0;i<x.size();i++) {
        cout<<x[i]<<" ";
    }
}