#include<bits/stdc++.h>
using namespace std;
string helper(string s) {
    int n=s.size();
    string p=s;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            p[i]='0';
            if(i-1>=0 && s[i-1]=='0') {
                p[i-1]='1';
            }
            if(i+1<n && s[i+1]=='0') {
                p[i+1]='1';
            }
        }
    }
    return p;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string s1=s;
        unordered_map<string,pair<int,int>> m;
        unordered_map<int,string> m1;
        m[s1]={1,0};
        m1[0]=s1;
        int div;
        int start,end;
        int i;
        for(i=1;i<=k;i++) {
            s1=helper(s1);
            m1[i]=s1;
            if(m[s1].first>0) {
                start=m[s1].second;
                end=i;
                break;
            }
            else {
                m[s1]={1,i};
            }
        }
        int x=k-start+1;
        int interval=end-start;
        x=x%interval;
        cout<<m1[start+x-1]<<endl;
    }
}