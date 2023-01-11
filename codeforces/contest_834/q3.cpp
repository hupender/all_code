#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int l,r,x;
        cin>>l>>r>>x;
        int a,b;
        cin>>a>>b;
        if(a==b) {
            cout<<"0"<<endl;
        }
        else if(abs(a-b)>=x) {
            cout<<"1"<<endl;
        }
        else {
            int a_l=0,a_r=0,b_l=0,b_r=0,l_r=0;
            if(abs(l-a)>=x) {
                a_l=1;
            }
            if(abs(l-b)>=x) {
                b_l=1;
            } 
            if(abs(r-a)>=x) {
                a_r=1;
            }
            if(abs(r-b)>=x) {
                b_r=1;
            }
            if(abs(l-r)>=x) {
                l_r=1;
            }
            if(a_l && b_l || a_r && b_r) {
                cout<<"2"<<endl;
            }
            else if(a_l && b_r && l_r || a_r && l_r && b_l) {
                cout<<"3"<<endl;
            }
            else {
                cout<<"-1"<<endl;
            }
        }
        
    }
}