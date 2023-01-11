#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int flag=1;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) {
            if(m[s[i]]>0) {
                flag=0;
                break;
            }
            else {
                m[s[i]]++;
                while(i+1<n && s[i+1]==s[i]) {
                    i++;
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
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}