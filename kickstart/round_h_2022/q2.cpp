#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        int l;
        cin>>l;
        int ans=l;
        int ans1=2*(l/3)+2+3;
        int r=l%3;
        if(r==1) {
            ans1++;
        }
        else if(r!=0) {
            ans1+=2;
        }
        ans=min(ans,ans1);
        for(int i=5;i<l;i++) {
            int res=2*(l/i)+2+i;
            int rem=l%i;
            if(r==1) {
                res++;
            }
            else if(r!=0) {
                res+=2;
            }
            ans=min(ans,res);
        }
        cout<<"Case #"<<x<<": "<< ans<<endl;
    }
}