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
        int a=1;
        int b=ceil(1.0*(n-4)/3);
        int c=(n-4)-b;
        int d=abs(a-b);
        int e=abs(b-c);
        int f=abs(a-c);
        int p=min(d,min(e,f));
        cout<<p<<endl;
    }
}