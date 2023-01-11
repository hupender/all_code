#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
const int mod=1e9+7;
void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a[n];
    for(int i=0;i<n;i++) {
        a[i]=s[i]-'0';
    }
    int first_one=n,first_zero=n,last_one=-1,last_zero=-1;
    for(int i=0;i<n;i++) {
        if(a[i]==1) {
            first_one=i;
            break;
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            first_zero=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(a[i]==0) {
            last_zero=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(a[i]==1) {
            last_one=i;
            break;
        }
    }
    int pre[n];
    memset(pre,mod,sizeof(pre));
    int suff[n];
    memset(suff,mod,sizeof(suff));
    int d=0;
    for(int i=first_one;i<n;i++) {
        if(a[i]==0) {
            d++;
            pre[i]=d;
        }
        else {
            d=0;
        }
    }
    d=0;
    for(int i=first_zero;i<n;i++) {
        if(a[i]==1) {
            d++;
            pre[i]=d;
        }
        else {
            d=0;
        }
    }
    for(int i=last_one;i>=0;i--) {
        if(a[i]==0) {
            d++;
            suff[i]=d;
        }
        else {
            d=0;
        }
    }
    d=0;
    for(int i=last_zero;i>=0;i--) {
        if(a[i]==1) {
            d++;
            suff[i]=d;
        }
        else {
            d=0;
        }
    }
    int final[n];
    for(int i=0;i<n;i++) {
        final[i]=min(pre[i],suff[i])-1;
    }
    for(int i=0;i<n;i++) {
        if(final[i]<=k) {
            int p=k-final[i];
            if(p%2!=0) {
                if(a[i]==0) {
                    a[i]=1;
                }
                else {
                    a[i]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<a[i];
    }
    cout<<endl;
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