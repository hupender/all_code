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
    int min_diff=INT_MAX;
    int st,end;
    int st_ind,end_ind;
    for(int i=0;i<n-1;i++) {
        int d=a[i+1]-a[i];
        if(d<min_diff) {
            min_diff=d;
            st_ind=i;
            end_ind=i+1;
            st=a[i];
            end=a[i+1];
        }
    }
    int b[n];
    b[0]=st;
    b[n-1]=end;
    int k=1;
    for(int i=end_ind+1;i<n;i++) {
        b[k]=a[i];
        k++;
    }
    for(int i=0;i<st_ind;i++) {
        b[k]=a[i];
        k++;
    }
    for(int i=0;i<n;i++) {
        cout<<b[i]<<" ";
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