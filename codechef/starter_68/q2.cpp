#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        int a=x-n;
        int res=1;
        while(a--) {
            res*=2;
        }
        cout<<res<<endl;
    }
}