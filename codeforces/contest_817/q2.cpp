#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        int flag;
        for(int i=0;i<n;i++) {
            if(s1[i]=='R' && s2[i]=='R' || s1[i]=='G' && s2[i]=='G' || s1[i]=='B' && s2[i]=='B' || s1[i]=='G' && s2[i]=='B' || s1[i]=='B' && s2[i]=='G') {
                flag=1;
            }
            else {
                flag=0;
                break;
            }
        }
        if(flag==0) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"yes"<<endl;
        }
    }
}