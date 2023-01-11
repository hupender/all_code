#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,s;
        cin>>n>>s;
        vector<int> v;
        int lar=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            lar=max(k,lar);
            m[k]++;
            v.push_back(k);
        }
        for(int i=1;i<lar;i++) {
            if(m[i]==0) {
                s-=i;
            }
        }
        if(s==0) {
            cout<<"YES"<<endl;
        }
        else if(s<0) {
            cout<<"NO"<<endl;
        }
        else {
            int flag=1;
            lar++;
            while(s>0) {
                s-=lar;
                lar++;
                if(s<0) {
                    flag=0;
                    break;
                }
            }
            if(flag) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
}