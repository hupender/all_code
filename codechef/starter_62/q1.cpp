#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("inp.txt","r",stdin);
    int t;
    cin>>t;
    while(t--) {
        int n,x,y;
        cin>>n>>x>>y;
        if(y%x==0 && n*x>=y) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
}