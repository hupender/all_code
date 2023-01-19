#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        s.insert({a[i],i});
    }
    unordered_map<int,int> m;
    for(int i=0;i<n-1;i++) {
        m[abs(a[i+1]-a[i])]++;
    }
    for(int i=0;i<n-2;i++) {
        if(a[i]>a[i+1]) {
            auto it1=s.find({a[i+1],i+1});
            auto it2=s.find({a[i],i});
            it1++;
            while(it1!=it2) {
                if(it1->first==a[i]) {
                    m[0]++;
                    break;
                }
                else {
                    m[abs(it1->first-a[i])]++;
                }
                it1++;
            }
        }
        else if(a[i]==a[i+1]) {
            m[0]++;
        }
    }
    cout<<m.size()<<endl;
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