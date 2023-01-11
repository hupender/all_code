#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> get_mst(int v,int e,vector<pair<pair<int,int>,int>> &edges) {
    vector<vector<pair <int,int> >> adj(v+1);
    for(int i=0;i<e;i++) {
        int a,b,c;
        a=edges[i].first.first;
        b=edges[i].first.second;
        c=edges[i].second;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    // distance---1st node(parent)------2nd node
    set<pair<pair<int,int>,int>> st;
    vector<bool> visited(v+1, false);
    st.insert({{0,-1},1});
    visited[1]=true;

    vector<pair<pair<int,int>,int>> result;

    while(!st.empty()) {
        set<pair<pair<int,int>,int>>::iterator it;
        it=st.begin();
        int top_dis=it->first.first;
        int top_par=it->first.second;
        int top_node=it->second;
        st.erase(st.begin());
        
        if(top_par!=-1) {
            result.push_back({{top_par,top_node},top_dis});
        }

        for(auto i:adj[top_node]) {
            int a=i.first;
            int b=i.second;
            if(!visited[a]) {
                st.insert({{b,top_node},a});
                visited[a]=true;
            }
        }
    }
    return result;

}


int main() {
    int v,e;
    vector<pair<pair<int,int>,int>> edges;
    cout<<"enter no of vertices and edges"<<endl;
    cin>>v>>e;
    cout<<"enter edges with their weights"<<endl;
    for(int i=0;i<e;i++) {
        int a,b,c;
        //edge____weight
        cin>>a>>b>>c;
        edges.push_back({{a,b},c});
    }
    
/*
input 
4 5

0 1 5
0 2 8
1 2 10
1 3 15
2 3 20

*/

    //prim's minimum spanning tree
    vector<pair<pair<int,int>,int>> ans;
    ans=get_mst(v,e,edges);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
}