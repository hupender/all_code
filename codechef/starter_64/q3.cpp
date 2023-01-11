#include<bits/stdc++.h>
using namespace std;
vector<int> get_factors(int n) {
    vector<int> v;
    v.push_back(1);
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            v.push_back(i);
            while(n%i==0) {
                n=n/i;
            }
        }
    }
    if(n!=1) {
        v.push_back(n); 
    }
    return v;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            vector<int> v1=get_factors(v[i]);
            for(int j=0;j<v1.size();j++) {
                m[v1[j]]++;
            }
        }
        int hcf=1;
        for(auto i:m) {
            if(i.second==n) {
                hcf*=i.first;
            }
        }
        int count=0;
        for(int i=0;i<n;i++) {
            if(v[i]!=hcf) {
                count++;
            }
        }
        cout<<count<<endl;
    }
}