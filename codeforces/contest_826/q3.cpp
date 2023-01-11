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
        vector<int> v;
        int sum=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            sum+=k;
            v.push_back(k);
        }
        int s=0;
        int len=INT_MAX,ans=INT_MAX;
        for(int i=0;i<n;i++) {
            s+=v[i];
            if(sum%s==0) {
                len=i+1;
                int sum1=0,ind=i+1;
                for(int j=i+1;j<n;j++) {
                    sum1+=v[j];
                    if(sum1>s) {
                        len=n;
                        break;
                    }
                    if(sum1==s) {
                        len=max(len,j-ind+1);
                        ind=j+1;
                        sum1=0;
                    }
                }
                ans=min(ans,len);
            }
            
        }
        cout<<ans<<endl;
    }
}