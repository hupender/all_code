#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    string s;
    cin>>s;
    int n=s.size();
    if(n==8 && s[0]>='A' && s[0]<='Z' && s[n-1]>='A' && s[n-1]<='Z') {
        if(s[1]>='1' && s[1]<='9') {
            int flag;
            for(int i=2;i<n-1;i++) {
                if(s[i]>='0' && s[i]<='9') {
                    flag=1;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if(flag) {
                cout<<"Yes"<<endl;
            }
            else {
                cout<<"No"<<endl;
            }
        }
        else {
            cout<<"No"<<endl;
        }
    }
    else {
        cout<<"No"<<endl;
    }
    
}