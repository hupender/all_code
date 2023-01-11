#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        char c='a';
        map<char,int> m1;
        vector<char> m;
        for(int i=0;i<n;i++) {
            
            m1[s[i]]++;
        }

        map<char,int> alp;
        for(int i=0;i<26;i++) {
            alp[('a'+i)]++;
        }
        unordered_map<char,char> um;
        for(auto i:m) {
            if(i.first==c) {
                for(auto &j:alp) {
                    if(j.second!=0 && j.first!=c) {
                        um[i.first]=j.first;
                        i.second--;
                        break;
                    }
                }
            }
            else {
                if(um[c]==i.first) {
                    um[i.first]=c+1;
                    alp[c+1]--;
                }
                else {
                    um[i.first]=c;
                    alp[c]--;
                    for(auto i:alp) {
                        if(i.second>0) {
                            c=i.first;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            s[i]=um[s[i]];
        }
        cout<<s<<endl;
    }
}