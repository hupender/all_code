#include<bits/stdc++.h>
using namespace std;
int find(vector<int> v,int val) {
    for(int i=0;i<v.size();i++) {
        if(v[i]==val) {
            return i+1;
        }
    }
    return -1;
}
int main() {

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> v;
        for(int i=0;i<k;i++) {
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<k;i++) {
            int a=v[i].first;
            int b=v[i].second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int val=1;
        int parent_size=adj[1].size();
        int parent_val=1;
        for(auto i:adj[val]) {
            int size=adj[i].size();
            if(size>parent_size) {
                parent_size=size;
                parent_val=i;
            }
        }

        vector<int> head;
        head.push_back(parent_val);
        for(int i=0;i<adj[parent_val].size();i++) {
            int ind=adj[parent_val][i];
            for(int  j=0;j<adj[ind].size();j++) {
                int check_num=adj[adj[parent_val][i]][j];
                if(check_num!=parent_val) {
                    int ans=find(adj[parent_val],check_num);
                    if(ans==-1) {
                        head.push_back(ind);
                        break;
                    }
                }    
            }
        }

        // cout<<"head vector"<<endl;
        // for(int i=0;i<head.size();i++) {
        //     cout<<head[i]<<" ";
        // }
        // cout<<endl;

        sort(head.begin(),head.end());
        cout<<head.size()<<endl;

        for(int i=1;i<=n;i++) {
            int ans=find(head,i);
            if(ans != -1) {
                cout<<ans<<" ";
            }
            else {
                for(int j=0;j<adj[i].size();j++) {
                    int ans1=find(head,adj[i][j]);
                    if(ans1 != -1) {
                        cout<<ans1<<" ";
                        break;
                    }
                }
            }
        }
        cout<<endl;
        for(int i=0;i<head.size();i++) {
            cout<<head[i]<<" ";
        }
        cout<<endl;
    }
}

/*
1
7
8
2 1
2 3
1 3
4 5
6 7
1 4
4 6
1 6


1
2
1
1 2
*/
