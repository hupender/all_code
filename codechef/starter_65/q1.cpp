#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        int r=a+b;
        int flag=1;
        for(int i=2;i*i<=r;i++) {
            if(r%i==0) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout<<"Alice"<<endl;
        }
        else {
            cout<<"Bob"<<endl;
        }
    }
}