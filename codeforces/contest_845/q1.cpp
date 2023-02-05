#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    if(n==1) {
        cout<<"0"<<endl;
    }
    else {
        int res=0;
        for(int i=0;i<n;i++) {
            if(a[i]%2==0) {
                int count=0;
                while(i<n && a[i]%2==0) {
                    count++;
                    i++;
                }
                i--;
                res+=(count-1);
            }
            else {
                int count=0;
                while(i<n && a[i]%2!=0) {
                    count++;
                    i++;
                }
                i--;
                res+=(count-1);
            }
        }
        cout<<res<<endl;
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