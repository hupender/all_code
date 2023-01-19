#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef hupi
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    int n=s.size();
    int count=0;
    for(int i=0;i<n;i++) {
        if(s[i]==',') {
            count++;
        }
    }
    cout<<count<<endl;

}