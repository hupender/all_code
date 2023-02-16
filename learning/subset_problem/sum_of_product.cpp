#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod=1e9+7;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    ll res=a[0];
    for(int i=1;i<n;i++) {
        res=a[i]*(1+res)+res;
        res%=mod;
    }
    cout<<res<<endl;
}