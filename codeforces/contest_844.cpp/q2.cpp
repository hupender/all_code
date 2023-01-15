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
    sort(a,a+n);
    int count_0=0;
    int ind=0;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            count_0++;
        }
        else {
            ind=i;
            break;
        }
    }
    int count=1;
    int count_going=count_0;
    for(int i=ind;i<n;i++) {
        if(a[i]>count_going) {
            count++;
            int diff=a[i]-count_going;
            count_going+=diff;
            i+=diff;
            count_going++;
        }
        else {
            count_going++;
        }
    }
    cout<<count<<endl;
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