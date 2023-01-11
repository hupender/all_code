#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int k,n,m;
    cin>>k>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int b[m];
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    vector<int> res;
    int i=0,j=0;
    int flag=1;
    while(i<n || j<m) {
        if(i<n && a[i]<=k) {
            if(a[i]==0) {
                k++;
            }
            res.push_back(a[i]);
            i++; 
        }
        else if(j<m && b[j]<=k) {
            if(b[j]==0) {
                k++;
            }
            res.push_back(b[j]);
            j++;
        }
        else if(i<n && a[i]>k) {
            if(j>=m || b[j]!=0) {
                flag=0;
                break;
            }
        }
        else if(j<m && b[j]>k) {
            if(i>=n || a[i]!=0) {
                flag=0;
                break;
            }
        }
    }
    if(flag) {
        for(int i=0;i<n+m;i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
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