#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        string t;
        cin>>s;
        cin>>t;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) {
            if(s[i]!='?') {
                m[s[i]]++;
            }
        }
        for(int i=0;i<n;i++) {
            if(m[t[i]]>0) {
                m[t[i]]--;
            }
        }
        int flag=1;
        for(auto i:m) {
            if(i.second!=0) {
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
}