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
    int flag=0;
    vector<int> v;
    if(a[0]==1) {
        flag=1;
        v.push_back(n+1);
        for(int i=1;i<=n;i++) {
            v.push_back(i);
        }
    }
    else if(a[n-1]==0) {
        flag=1;
        for(int i=1;i<=n;i++) {
            v.push_back(i);
        }
        v.push_back(n+1);
    }
    if(!flag) {
        int ind;
        for(int i=0;i<n-1;i++) {
            if(a[i]==0 && a[i+1]==1) {
                flag=1;
                ind=i+1;
                break;
            }
        }
        if(flag) {
            for(int i=1;i<=n;i++) {
                v.push_back(i);
                if(i==ind) {
                    v.push_back(n+1);
                }
            }
        }
        else {
            for(int i=0;i<n-1;i++) {
                if(a[i]==1 && a[i+1]==0) {
                    flag=1;
                    ind=i+1;
                    break;
                }
            }
            if(flag) {
                for(int i=n;i>=1;i--) {
                    v.push_back(i);
                    if(i==ind) {
                        v.push_back(n+1);
                    }
                }
            }
        }
    }
    if(flag) {
        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
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