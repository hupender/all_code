#include<bits/stdc++.h>
using namespace std;

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
        int hcf=v[0];
        for(int i=1;i<n;i++) {
            hcf=gcd(hcf,v[i]);
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