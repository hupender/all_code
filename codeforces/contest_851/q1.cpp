#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    int count_2=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]==2) {
            count_2++;
        }
    }
    if(count_2%2==0) {
        int count=count_2/2;
        int count1=0,k;
        for(int i=0;i<n;i++) {
            if(a[i]==2) {
                count1++;
            }
            if(count==count1) {
                k=i+1;
                break;
            }
        }
        cout<<k<<endl;
    }
    else {
        cout<<"-1"<<endl;
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