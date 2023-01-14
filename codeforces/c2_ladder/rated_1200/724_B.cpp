#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<string> set;
    for(int i=0;i<n;i++) {
        string s1;
        s1.push_back(s[i]);
        if(set.find(s1)==set.end()) {
            set.insert(s1);
        }
        for(int j=i+1;j<n;j++) {
            s1.push_back(s[j]);
            if(set.find(s1)==set.end()) {
                set.insert(s1);
            }
        }
    }
    int flag=1;
    string res;
    vector<string> v;
    for(int i=0;i<26;i++) {
        string s1;
        s1.push_back('a'+i);
        if(set.find(s1)==set.end()) {
            flag=0;
            res=s1;
            break;
        }
        v.push_back(s1);
    }
    if(flag) {
        while(flag) {
            vector<string> v1;
            for(int i=0;i<v.size();i++) {
                for(int j=0;j<26;j++) {
                    char c='a'+j;
                    string s2=v[i];
                    s2.push_back(c);
                    if(set.find(s2)==set.end()) {
                        flag=0;
                        res=s2;
                        break;
                    }
                    v1.push_back(s2);
                }
                if(!flag) {
                    break;
                }
            }
            if(flag) {
                v=v1;
            }
        }
    }
    cout<<res<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}