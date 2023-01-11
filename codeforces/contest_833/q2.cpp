#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v;
        unordered_map<int,vector<int>> m1;
        for(int i=0;i<n;i++) {
            v.push_back(s[i]-'0');
            m1[s[i]-'0'].push_back(i);
        }
        int distinct;
        unordered_map<int,int> m;
        int last_ind=0;
        int count=0;
        for(int i=0;i<n;i++) {
            m[v[i]]++;
            distinct=m.size();
            if(m[v[i]]>distinct) {
                int p=(i-last_ind);
                count+=(p*(p+1))/2;
                int ind;
                for(auto j:m1[v[i]]) {
                    if(j>=last_ind) {
                        ind=j;
                    }
                }
                for(int j=last_ind;j<ind;j++) {
                    m[v[j]]--;
                }
            }
        }
        int num=0;
        for(auto j:m) {
            num+=j.second;
        }
        count+=(num*(num+1))/2;
        cout<<count<<endl;
    }
}