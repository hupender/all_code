#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        long long ans=1;
        for(int i=0;i<n;i++) {
            ans=ans*2;
        }
        
        if(k==n) {
            cout<<"2"<<endl;
        }

        else if(k%2!=0) {
            ans=ans%(1000000007);
            cout<<ans<<endl;
        }
        else {
            ans=ans/2;
            ans=ans%(1000000007);
            cout<<ans<<endl;
        }
    }
}