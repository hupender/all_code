#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
            m[k].push_back(i);
        }
        int ind=0,count=0;
        for(int i=0;i<n-1;i++) {
            if(v[i]>v[i+1]) {
                count++;
                int p=v[i];
                int k=m[p].size();
                for(auto it:m[v[i]]) {
                    v[it]=0;
                }
                int last=m[p][k-1];
                for(int j=ind;j<last;j++) {
                    if(v[j]!=0) {
                        count++;
                        for(auto l:m[v[j]]) {
                            v[l]=0;
                        }
                    }
                }
                ind=last;
                i=ind;
            }
        }
        cout<<count<<endl;
    }
}