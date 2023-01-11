#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input4_final.txt","r",stdin);
    freopen("output4.txt","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        int n,m,q;
        //n is number of platform
        // next m lines contaiin : no of edges with number of passengers
        cin>>n>>m>>q;
        vector<vector<int>> edges;
        for(int i=0;i<m;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            edges.push_back({a,b,c});
        }
        // follow are q queries
        vector<pair<int,int>> query;
        for(int i=0;i<q;i++) {
            int a,b;
            cin>>a>>b;
            query.push_back({a,b});
        }
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++) {
            int a,b,c;
            vector<pair<int,int>> v;
            a=edges[i][0];
            b=edges[i][1];
            c=edges[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            // adj.push_back(v);
            // v.clear();
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<adj[i].size();i++) {
        //         cout<<adj[i][j].first<<" "<<adj[i][j].second;
        //     }
        // }

        cout<<"Case #"<<z<<": ";
        for(int i=0;i<q;i++) {
            int total_people=0;
            int source=query[i].first;
            int destination=query[i].second;
            for(auto itr1:adj[source]) {
                if(itr1.first==destination) {
                    total_people+=2*itr1.second;
                }
                for(auto itr2:adj[destination]) {
                    if(itr1.first==itr2.first) {
                        total_people+=min(itr1.second,itr2.second);
                        break;
                    }
                }
            }
            cout<<total_people<<" ";
        }
        cout<<endl;
    }
}