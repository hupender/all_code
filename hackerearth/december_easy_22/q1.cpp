#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        int data=val;
        left=NULL;
        right=NULL;
    }
};


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            // adj[b].push_back(a);
            v.push_back({a,b});
        }
        Node* root;
        root=new Node(1);
        for(int i=1;i<=n;i++) {
            for(int j=0;j<adj[i].size();j++) {
                if(j==0) {
                    root->left=new Node(adj[i][j]);
                }
                else {
                    root->left=new Node(adj[i][j]);
                }
            }
        }
    }
}