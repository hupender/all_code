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
        int count=0;
        int x=n;
        while(x) {
            count++;
            x/=10;
        }
        int res=0;
        res+=9*(count-1);
        int d=1;
        count--;
        while(count--) {
            d*=10;
        }
        res+=n/d;
        cout<<res<<endl;

    }
}