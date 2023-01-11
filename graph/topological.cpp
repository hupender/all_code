#include<bits/stdc++.h>
using namespace std;

int dm = 1;

void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int k, unordered_map<int,int> &parent) {
    // if(!parent[k]) {
        
    //     cout << "k is " << k << " parent[k] is " << parent[k] << endl;

    //     parent[k]=-1;
    //     visited[k]=1;
    // }
    for(auto i: adj[k]) {
        
        if(dm) cout << "i = " << i << " k = " << k <<  " visited[i] = " << visited[i] << endl;

        if(!visited[i]) {
            visited[i]=1;
            parent[i]=k;

            if(dm) cout << "parent of " << i << " set to " << parent[i] << endl;

            dfs(adj,visited,i,parent);
        }
    }



}

vector<int> get_topo(unordered_map<int,vector<int>> &adj,int p) {
    vector<int> ans;
    ans.push_back(p);
    for(auto i:adj[p]) {
        vector<int> k=get_topo(adj,i);
        ans.insert(ans.end(),k.begin(),k.end());
    }

    if(dm) cout << "topo of " << p << " called\n";
    if(dm) cout << "result:\n";
    for(int i : ans){
        if(dm) cout << i << " ";

    }
    if(dm) cout << endl;

    return ans;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++) {
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
     }
    vector<bool> visited(v); // [0,1,2...v-1]
    unordered_map<int,int> parent;

    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            parent[i] = -1;
            dfs(adj,visited,i,parent);
        }
    }

    if(dm) cout << "parent array : \n";
    for(pair<int, int> p : parent){
        if(dm) cout << "parent of " << p.first << " is " << p.second << endl;
    }

    vector<int> tot_ans;
    for(int i=0;i<v;i++) {
        if(parent[i]==-1) {

            vector<int> ans = get_topo(adj,i);
            tot_ans.insert(tot_ans.end(), ans.begin(), ans.end());
            

            if(dm) cout << "topo done with i = " << i << " ans : \n" ;

            for(int i : ans){
                if(dm) cout << i << " ";
            }

            if(dm) cout << endl;

            if(dm)cout << "tot_ans = \n";
            for(int i : tot_ans){
                if(dm) cout << i << " ";
            }

            if(dm) cout << endl;


        }
    }


    if(dm)cout << "tot_ans = \n";
    for(int i : tot_ans){
        if(dm) cout << i << " ";
    }
    if(dm) cout << endl;

    return tot_ans;
}



int main() {

/*
inp
3 2
0 1
0 2
output : 
1 2 3 or 1 3 2

5 4
0 1
1 2
3 2
3 7

expected output : 0 1 3 2 4 or 0 3 1 2 4 or 0 3 1 4 2


*/



    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++) {
        vector<int> p;
        int a,b;
        cin>>a>>b;
        p={a,b};
        edges.push_back(p);
    }
    vector<int> k=topologicalSort(edges,v,e);
    for(int i=0;i<k.size();i++) {
        // Mistake
        cout<<k[i];
    }
}
