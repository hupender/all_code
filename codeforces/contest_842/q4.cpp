#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
// number of steps to sort the array
int get_help(int a[],int n) {
    int count=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    int val=1;
    for(int i=0;i<n;i++) {
        if(a[i]!=val) {
            count++;
            int ind=v[val-1].second;
            int temp=a[ind];
            a[ind]=a[i];
            a[i]=temp;
            v[val-1].second=i;
            v[a[ind]].second=ind;
        }
        val++;
    }
    return count;
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    map<int,int> m;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        
        cin>>a[i];
        m[a[i]]++;
    }
    int res=get_help(a,n);
    cout<<res<<endl;
    // int b[n];
    // for(int i=0;i<n;i++) {
    //     int d=distance(m.begin(),m.find(a[i]));
    //     b[i]=d;
    //     m.erase(a[i]);
    // }
    
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