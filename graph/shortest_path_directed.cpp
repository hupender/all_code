#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges,int v,int e,int s,int t) {
    // code here
    unordered_map<int,vector<int>
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