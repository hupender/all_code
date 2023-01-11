#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            v.push_back({p,i});
        }
        sort(v.begin(),v.end());
        int count=1;
        for(int i=0;i<n-1;i++) {
            if(v[i].second!=v[i+1].second-1) {
                count++;
            }
        }
        // for(int i=0;i<n-1;i++) {
        //     if(v[i]>v[i+1]) {
        //         count++;
        //     }
        // }
        if(count<=k) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}