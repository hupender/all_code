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
        unordered_map<string,vector<pair<int,int>> > m;
        for(int i=0;i<n-1;i++) {
            string s1;
            s1+=s[i];
            s1+=s[i+1];
            m[s1].push_back({i,i+1});
        }
        int flag=0;
        for(auto i:m) {
            if(i.second.size()>2) {
                flag=1;
                break;
            }
            if(i.second.size()==2) {
                if(i.second[0].second!=i.second[1].first) {
                    flag=1;
                    break;
                }
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