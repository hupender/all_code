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
        int flag=1;
        for(int i=1;i<n;i++) {
            if(v[i]%v[0]!=0) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout<<v[n-1]/v[0]<<endl;
        }
        else {
            cout<<v[n-1]<<endl;
        }
    }
}