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
        int n,m;
        cin>>n>>m;
        if(n==1 || m==1) {
            cout<<"1 1"<<endl;
        }
        else if(n>3 || m>3) {
            cout<<"1 1"<<endl;
        }
        else {
            cout<<(n+1)/2<<" "<<(m+1)/2<<endl;
        }
    }
}