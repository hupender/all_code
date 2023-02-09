#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
unordered_map<int,int> map1;
void get_help(vector<int>& a) {
    int n=a.size();
    if(n==0 || n==1) {
        return;
    }
    else if(n==2) {
        int diff=abs(a[1]-a[0]);
        map1[diff]++;
    }
    else {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        int lower=0,higher=n-1;
        int large=v[n-1].second;
        for(int i=n-2;i>=0;i--) {
            int ind=v[i].second;
            if(ind>=lower && ind<=higher) {
                int diff=v[n-1].first-v[i].first;
                map1[diff]++;
                if(ind<large) {
                    lower=ind+1;
                }
                else {
                    higher=ind-1;
                }
            }
        }
        vector<int> v1,v2;
        for(int i=0;i<large;i++) {
            v1.push_back(a[i]);
        }
        for(int i=large+1;i<n;i++) {
            v2.push_back(a[i]);
        }
        get_help(v1);
        get_help(v2);
    }
}
void solve() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        a.push_back(k);
    }
    get_help(a);
    ll res=map1.size();
    map1.clear();
    cout<<res<<endl;

    
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