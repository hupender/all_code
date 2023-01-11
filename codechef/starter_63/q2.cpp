#include<bits/stdc++.h>
using namespace std;

string get_help(int n) {
    if(n==0) {
        string s=to_string('0');
        return s;
    }
    vector<int> v;
    string s;
    while(n>0) {
        v.push_back(n%2);
        n/=2;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++) {
        s.push_back(v[i]+'0');
    }
    s.pop_back();
    if(s.empty()) {
        s='0';
    }
    return s;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        unordered_map<string,int> m;
        for(int i=0;i<n;i++) {
            string s=get_help(v[i]);
            m[s]++;
        }
        int ma=0;
        for(auto i:m) {
            ma=max(i.second,ma);
        }
        cout<<n-ma<<endl;
    }
}