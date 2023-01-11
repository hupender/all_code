#include<bits/stdc++.h>
using namespace std;
int main() {

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        char s[n];
        for(int i=0;i<n;i++) {
            cin>>s[i];
        }
        if(n!=5) {
            cout<<"NO"<<endl;
        }
        else {
            unordered_map<char,int> m;
            for(int i=0;i<n;i++) {
                m[s[i]]++;
            }
            if(m['T']==1 && m['i']==1 && m['u']==1 && m['m']==1 && m['r']==1) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
}