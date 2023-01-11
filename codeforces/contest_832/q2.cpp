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
        int k=(n+1)/2;
        cout<<k<<endl;
        // vector<pair<int,int>> v;
        int l=2,h=3*n;
        while(k--) {
            cout<<l<<" "<<h<<endl;
            l+=3;
            h-=3;
        }
    }
}