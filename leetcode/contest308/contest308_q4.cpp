#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> get_topological_sort(vector<vector<int>> &edges,int n) {
        vector<int> indegree(n);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        // stack<int> st;
        // vector<bool> visited(n+1);
        // for(int i=1;i<=n;i++) {
        //     if(!visited[i]) {
        //         get_topological(adj,st,visited,i);
        //     }
        // }
        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto i:adj[t]) {
                indegree[i]--;
                if(indegree[i]==0) {
                    q.push(i);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> vertical=get_topological_sort(rowConditions,k);
        vector<int> horizontal=get_topological_sort(colConditions,k);
        if(vertical.size()!=k || horizontal.size()!=k) {
            vector<vector<int>> result;
            return result;
        }
        
        else {
            vector<vector<int>> result(k,vector<int> (k,0));
            for(int i=0;i<k;i++) {
                for(int j=0;j<k;j++) {
                    if(horizontal[i]==vertical[j]) {
                        result[i][j]=horizontal[i];
                        break;
                    }
                }
            }
            return result;
        }
    }
};

int main() {
    int k;
    cin>>k;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> rowCondition;
    vector<vector<int>> colCondition;
    cout<<"enter row conditions"<<endl;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        rowCondition.push_back({a,b});
    }
    cout<<"enter col condition"<<endl;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        colCondition.push_back({a,b});
    }
    vector<vector<int>> res;

    Solution s;
    res=s.buildMatrix(k,rowCondition,colCondition);

    cout<<"resulting matrix"<<endl;
    for(int i=0;i<res.size();i++) {
        for(int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
input
3
2 2
1 2
3 2
2 1
3 2
*/