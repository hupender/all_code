#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        int size;
        cin>>size;
        vector<int> v1;
        for(int j=0;j<size;j++) {
            int k;
            cin>>k;
            v1.push_back(k);
        }
        v.push_back(v1);
    }
    while(q--) {
        int a,b;
        cin>>a>>b;
        cout<<v[a-1][b-1]<<endl;
    }
}