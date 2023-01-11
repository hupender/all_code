#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int c_zero=0,c_one=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            if(k==0) {
                c_zero++;
            }
            else {
                c_one++;
            }
        }
        if(c_zero>=c_one) {
            cout<<min(c_zero,c_one)<<endl;
        }
        else {
            int p=c_one-c_zero;
            cout<<c_zero+p/3<<endl;
        }
    }
}