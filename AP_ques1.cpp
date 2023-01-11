#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<ll,ll> extended_euclidien(int a,int b) {
    if(b==0) {
        return {1,0};
    }
    
}
int main() {
    int d1,a1,d2,a2,l,r;
    cin>>d1>>a1>>d2>>a2>>l>>r;
    //a1+(n-1)*d1=a2+(m-1)*d2
    //n*d1-m*d2=a2-a1+d1-d2
    ll g=gcd(d1,d2);
    int p=a2-a1+d1-d2;
    if(p%g) {
        cout<<"0"<<endl;
    }
    else {
        extended_euclidien(d1,d2);
    }
}