#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_order(int a,vector<vector<int>>& adj,vector<bool>& visited ,vector<int>& parent) {
        queue<int> q;
        q.push(a);
        int order=0;
        while(!q.empty()) {
            order++;
            int size=q.size();
            while(size--) {
                int a=q.front();
                q.pop();
                for(auto i:adj[a]) {
                    if(visited[i] && parent[i]!=a) {
                        return -1;
                    }
                    if(!visited[i]) {
                        parent[i]=a;
                        visited[i]=true;
                    }

                }
            }
        }
        return order;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> parent(n+1);
        parent[0]=-1;
        parent[1]=-1;
        queue<int> q;
        q.push(1);
        vector<bool> visited(n+1,false);
        visited[1]=true;
        int max1=0,max2=0;
        for(auto i:adj[1]) {
            int ord=get_order(i,adj,visited,parent);
            if(ord==-1) {
                return -1;
            }
            if(ord>=max1) {
                max2=max1;
                max1=ord;
            }
            else if(ord>max2) {
                max2=ord;
            }
        }
        if(max1*max2) {
            return max1+max2+2;
        }
        else {
            return max1+max2+1;
        }
    }
};