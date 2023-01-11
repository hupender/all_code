#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> get_factors(ll n) {
    vector<ll> v;
    v.push_back(1);
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            v.push_back(i);
            while(n%i==0) {
                n=n/i;
            }
        }
    }
    if(n!=1) {
        v.push_back(n); 
    }
    return v;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        vector<ll> v=get_factors(b);
        int flag=1;
        for(int i=0;i<v.size();i++) {
            if(a%v[i]!=0) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
}