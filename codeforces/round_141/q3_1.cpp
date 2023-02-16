#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<pair<int,int>> b;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        b.push_back({a[i],i});
    }
    sort(b.begin(),b.end());
    int count=0;
    vector<bool> defeated(n,false);  // store those defeated by us
    int last_defeated=-1;
    for(int i=0;i<n;i++) {
        int val=b[i].first;
        int ind=b[i].second;
        if(m>=val) {
            // finally we will get remaining time
            m-=val;
            defeated[ind]=true;
            last_defeated=val;
            count++;
        }
        else {
            break;
        }
    }
    int flag=0;
    if(!defeated[count]) {
        flag=1;
        int val=a[count];
        if(m+last_defeated>=val) {
            flag=0;
        }
    }
    int res=0;
    for(int i=0;i<n;i++) {
        if(b[i].second>count) {
            res++;
        }
        else if(b[i].second==count && flag) {
            res++;
        }
    }
    cout<<res+1<<endl;
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