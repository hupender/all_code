#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;
    cin>>n>>k;
    pair<int,int> a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    vector<pair<int,int>> v;
    int count=0;
    for(int i=0;i<n;i++) {
        if(a[i].first<=k && a[i].second>=k) {
            v.push_back({a[i].first,a[i].second});
            count++;
        }
    }
    if(count==0) {
        cout<<"NO"<<endl;
    }
    else {
        vector<int> v1;
        for(int i=1;i<51;i++) {
            if(i!=k) {
                int count1=0;
                for(int j=0;j<count;j++) {
                    if(v[j].first<=i && v[j].second>=i) {
                        count1++;
                    }
                }
                v1.push_back(count1);
            }
        }
        int flag=1;
        int n1=v1.size();
        for(int i=0;i<n1;i++) {
            if(v1[i]>=count) {
                flag=0;
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
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