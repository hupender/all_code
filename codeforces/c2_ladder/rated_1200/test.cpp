#include<bits/stdc++.h>
using namespace std;
int main() {
    // char s[100];
    // #ifndef ONLINE_JUDGE
    //     freopen("inp.txt","r",stdin);
    // #endif
    // int n;
    // cin>>n;
    // string s[n];
    // getline(cin,s);
    // cin.getline(s,100);
    // cout<<s<<endl;
    vector<string> v;
    while(true) {
        string s1;
        cin>>s1;
        v.push_back(s1);
        if(s1=="") {
            break;
        }
    }
    // for(int i=0;i<n;i++) {
    //     cin>>s[i];
    // }
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<endl;
    }

    
}