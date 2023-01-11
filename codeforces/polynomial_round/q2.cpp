#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v;
    ll sum=0;
    for(int i=0;i<m;i++) {
        int k;
        cin>>k;
        sum+=k;
        v.push_back(k);
    }
    if(sum==n) {
        sort(v.begin(),v.end());
        int p=n/k;
        int r=n%k;
        int count=0;
        int flag=1;
        for(int i=0;i<m;i++) {
            if(v[i]==p+1) {
                count++;
            }
            else if(v[i]>p+1) {
                flag=0;
            }
        }
        if(flag==0 || count>r) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    else {
        cout<<"NO"<<endl;
    }
}
void solve1() {
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    ll sum=0;
    int ma=INT_MIN;
    for(int i=0;i<m;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        sum+=a[i];
        ma=max(ma,a[i]);
    }
    if(sum!=n) {
        cout<<"No"<<endl;
    }
    else {
        // if(ma*k>n) {
            
        // }
        if(ma*k>n) {
            int p=n/k;
            int r=n%k;
            if(r==0) {
                cout<<"No"<<endl;
            }
            else {
                if(ma==p+1) {
                    int count=0;
                    for(int i=0;i<n;i++) {
                        if(a[i]==p+1) {
                            count++;
                        }
                    }
                    if(count==r) {
                        cout<<"Yes"<<endl;
                    }
                    else {
                        cout<<"No"<<endl;
                    }
                }
                else {
                    cout<<"NO"<<endl;
                }
            }
        }
        else {
            cout<<"Yes"<<endl;
        }
    }
    
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