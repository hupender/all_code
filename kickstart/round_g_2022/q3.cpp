#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        vector<int> s;
        for(int i=0;i<n;i++) {
            int sum;
            sum=v[i];
            if(v[i]>=0) {
                s.push_back(sum);
                vector<int> s1;
                int flag=1;
                for(int j=i+1;j<n;j++) {
                    sum+=v[j];
                    if(sum>=0) {
                        s1.push_back(sum);
                    }
                    else {
                        flag=0;
                        break;
                    }
                }
                if(flag) {
                    for(auto j:s1) {
                        s.push_back(j);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<s.size();i++) {
            ans+=s[i];
        }
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
}