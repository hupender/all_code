#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;
        int size=roads.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<size;i++) {
            int a=roads[i][0];
            int b=roads[i][1];
            int c=roads[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        vector<int> visited(n+1,false);
        queue<int> q;
        q.push(1);
        // visited[1]=true;
        while(!q.empty()) {
            int a=q.front();
            visited[a]=true;
            q.pop();
            for(auto i:adj[a]) {
                if(!visited[i.first]) {
                    // visited[i.first]=true;
                    q.push(i.first);
                    res=min(res,i.second);
                }
            }
        }
        return res;
    }
};