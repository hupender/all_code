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
        unordered_map<char,int> freq;
        vector<char> order;
        for(int i=0;i<n;i++) {
            if(freq[s[i]]==0) {
                order.push_back(s[i]);
            }
            freq[s[i]]++;
        }
        map<char,int> alp;
        for(int i=0;i<26;i++) {
            alp['a'+i]++;
        }
        unordered_map<char,char> repla;
        char c='a';
        for(auto i:order) {
            if(i==c) {
                for(auto &j:alp) {
                    if(j.second>0 && j.first!=c) {
                        repla[i]=j.first;
                        j.second--;
                        break;
                    }
                }
            }
            else {
                if(repla[c]==i) {
                    for(auto &j:alp) {
                        if(j.second>0 && j.first!=c) {
                            repla[i]=j.first;
                            j.second--;
                            break;
                        }
                    }
                }
                else {
                    repla[i]=c;
                    alp[c]--;
                    c++;
                }
            }
        }
        for(int i=0;i<n;i++) {
            s[i]=repla[s[i]];
        }
        for(int i=0;i<n;i++) {
            cout<<s[i];
        }
        cout<<endl;
    }
}