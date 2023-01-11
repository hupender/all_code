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
        int n,c;
        cin>>n>>c;
        // vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            // v.push_back(k);
            m[k]++;
        }
        int ans=0;
        for(auto i:m) {
            if(i.second>c) {
                ans+=c;
            }
            else {
                ans+=i.second;
            }
        }
        cout<<ans<<endl;
    }
}