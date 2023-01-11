#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    int min1=INT_MAX,max1=INT_MIN;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]>max1) {
            max1=a[i];
        }
        if(a[i]<min1) {
            min1=a[i];
        }
    }
    if(n==1) {
        cout<<a[0]<<endl;
    }
    else {
        int ind=0;
        if(min1<0) {
            ind++;
            for(int i=0;i<n;i++) {
                a[i]-=min1;
            }
        }
        sort(a,a+n);
        vector<int> v;
        for(int i=ind;i<n-1;i++) {
            v.push_back(a[i+1]-a[i]);
        }
        int ma=a[ind];
        for(int i=0;i<v.size();i++) {
            ma=max(ma,v[i]);
        }
        cout<<ma<<endl;
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