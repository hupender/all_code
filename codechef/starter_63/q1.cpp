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
        for(int i=0;i<n;i++) {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}