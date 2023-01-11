#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0;i<n;i++) {
            m1[a[i]]++;
            m2[b[i]]++;
        }
        int ans=0;
        for(auto i:m1) {
            ans=max(ans,min(i.second,m2[i.first]));
        }
        cout<<ans<<endl;
    }
}