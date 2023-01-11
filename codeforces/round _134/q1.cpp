#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        unordered_map<char,int> m;
        m[s1[0]]++;
        m[s1[1]]++;
        m[s2[0]]++;
        m[s2[1]]++;
        int l=m.size();
        if(l==4) {
            cout<<"3"<<endl;
        }
        if(l==3) {
            cout<<"2"<<endl;
        }
        if(l==2) {
            cout<<"1"<<endl;
        }
        if(l==1) {
            cout<<"0"<<endl;
        }
    }
}