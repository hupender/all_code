#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        string s1=s;
        reverse(s1.begin(),s1.end());
        s+=s1;
        cout<<s<<endl;
    }
}