#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        // string ans;
        string a;
        cin>>s;
        vector<int> v;
        // ans=s;
        for(int i=1;i<n-1;i++) {
            if(s[i]=='0' && s[i+1]=='0') {
                char p=char(s[i-1]*10+s[i]);
                p=p-48;
                v.push_back(p);
                char c=p;
                a+=c;
            }
            else if(s[i]=='0' && s[i+1]!='0'){
                char p=char(s[i-2]*10+s[i-1]);
                p=p-48;
                v.push_back(p);
                char c=p; 
                a+=c;
            }
            else if(s[i]!='0' && s[i+1]=='0') {
                char p=char(s[i-1]*10+s[i]);
                p=p-48;
                v.push_back(p);
                char c=p;
                a+=c;
            }
            else {
                char p=char(s[i-1]);
                p=p-48;
                v.push_back(p);
                char c=p;
                a+=c;
            }
        }
        // cout<<a<<endl;
        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}