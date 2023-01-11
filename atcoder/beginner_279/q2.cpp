#include<bits/stdc++.h>
using namespace std;
int main() {
    string s,t;
    cin>>s>>t;
    int n1=s.size();
    int n2=t.size();
    int flag=0;
    for(int i=0;i<=n1-n2;i++) {
        if(s[i]==t[0]) {
            int a=i;
            int b=0;
            while(s[a]==t[b] && b<n2 && a<n1) {
                a++;
                b++;
            }
            if(b==n2) {
                flag=1;
                break;
            }
        }
    }
    if(flag) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}