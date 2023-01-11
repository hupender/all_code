#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve2() {
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    sort(a,a+n);
    for(int i=0;i<m;i++) {
        int flag=0;
        for(int j=0;j<n;j++) {
            if(a[j]<b[i]) {
                a[j]=b[i];
                flag=1;
                break;
            }
        }
        if(!flag) {
            a[0]=b[i];
        }
        sort(a,a+n);
    }
    ll sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
    }
    cout<<sum<<endl;
}
void solve1() {
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    sort(a,a+n,greater<int>());
    sort(b,b+m,greater<int>());
    if(m>=n) {
        ll sum=0;
        for(int i=0;i<n;i++) {
            sum+=b[i];
        }
        cout<<sum<<endl;
    }
    else {
        ll sum=0;
        for(int i=0;i<m;i++) {
            sum+=b[i];
        }
        int rem=n-m;
        for(int i=0;i<rem;i++) {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    ll sum=0;
    if(m>=n) {
        int j=0;
        for(int i=m-1;j<n && i>=0;i--) {
            sum+=b[i];
            j++;
        }
        cout<<sum<<endl;
    }
    else {
        for(int i=0;i<m;i++) {
            sum+=b[i];
        }
        int rem=n-m;
        int j=n-1;
        while(rem--) {
            sum+=a[j];
            j--;
        }
        cout<<sum<<endl;
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
        solve2();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}