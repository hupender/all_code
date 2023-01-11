#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
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
        int g=gcd(v[0],v[1]);
        for(int i=2;i<n;i++) {
            g=gcd(g,v[i]);
        }
        for(int i=0;i<n;i++) {
            v[i]/=g;
        }
        cout<<v[n-1]<<endl;
    }
}