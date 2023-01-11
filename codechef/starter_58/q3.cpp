#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        // vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            // v.push_back(k);
            m[k]++;
        }
        int ma=0;
        for(auto i:m) {
            ma=max(ma,i.second);
        }
        int k=1;
        int count=0;
        while(k<ma) {
            k=2*k;
            count++;
        }
        cout<<count<<endl;
    }
}