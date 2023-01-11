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
        vector<int> v(n);
        int p=1;
        for(int i=0;i<n;i=i+2) {
            v[i]=p;
            p++;
        }
        p=n;
        for(int i=1;i<n;i=i+2) {
            v[i]=p;
            p--;
        }
        for(int i=0;i<n;i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}