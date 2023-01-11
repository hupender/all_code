#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if(n==0) {
            return 0;
        }
        else if(n==1) {
            return vals[0];
        }

        int res=0;
        for(int i=0;i<n;i++) {
            vector<int> v;
            int sum=vals[i];
            for(auto j:adj[i]) {
                v.push_back(vals[j]);
            }
            sort(v.begin(),v.end());
            int size=v.size();
            int j=size-1;
            int l=k;
            while(j>=0 && l>0) {
                if(v[j]>0) {
                    sum+=v[j];
                    l--;
                    j--;
                }
                else {
                    break;
                }
            }
            res=max(res,sum);
        }
        return res;
    }
};
int main() {
    vector<int> v={-5};
    vector<vector<int>> v1={{5}};
    int k=0;
    Solution s;
    int res=s.maxStarSum(v,v1,k);
    cout<<res<<endl;
}