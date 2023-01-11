#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> ans;

    for(int i=1;i<=9;i++) {
        
        long p=i;
        
        vector<int> v;
        v.push_back(i);
        int count=0;
        while(count<n) {
            
            // p = (iii....ii) % m at this point
            // where i appear count+1 times

            if(p>=m) {
                p=p%m;
                if(p==0) {
                    // next update will happen on a bigger answer only
                    if(v.size()>=ans.size()) {
                        ans=v;
                    }
                    // ans=v;
                }
            }
            v.push_back(i);
            p=p*10+i;
            count++;
        }
    }
    if(ans.size()==0) {
        cout<<"-1";
    }
    else {
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i];
        }
    }
    cout<<endl;
}