#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mod=1e9+7;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s1;
        cin>>s1;
        vector<int> s;
        for(int i=0;i<n;i++) {
            s.push_back(s1[i]-'0');
        }
        int ind=-1;
        for(int i=1;i<n;i++) {
            if(s[i]!=s[0]) {
                ind=i;
                break;
            }
        }
        if(ind==-1) {
            cout<<"0"<<endl;
        }
        else {
            int size=n-ind;
            vector<ll> v;
            ll ans=0;
            int j=0;
            for(int i=size-1;i>=0;i--) {
                ans+=s[i]*pow(2,j);
                j++;
            }
            j=size;
            v.push_back(ans);
            for(int i=0;i<ind;i++) {
                int a=pow(2,size-1)*s[i];
                ans-=a;
                ans*=2;
                ans+=s[j];
                j++;
                v.push_back(ans);
            }
            int n1=v.size();
            ll res=0;
            for(int i=0;i<n1-1;i++) {
                ll res1=v[i]^v[n1-1];
                res=max(res1,res);
            }
            cout<<res%mod<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}