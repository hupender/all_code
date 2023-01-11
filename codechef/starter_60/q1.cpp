#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            m[k]++;
        }
        int ma=0;
        for(auto i:m) {
            ma=max(ma,i.second);
        }
        cout<<n-ma<<endl;
    }
}