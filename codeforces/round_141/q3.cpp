#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int sum=0;
    int count=0;
    int ind=n-1;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        if(sum<=m) {
            count++;
        }
        else {
            sum-=a[i];
            ind=i;
            break;
        }
    }
    if(count==0) {
        cout<<n+1<<endl;
    }
    else {
        map<int,int> map,map1;
        for(int i=0;i<n;i++) {
            map[a[i]]++;
        }
        int count1=0;
        for(auto i:map) {
            map1[i.first]=count1;
            count1+=i.second;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            int val=map1[a[i]];
            if(i>=ind) {
                val++;
            }
            v.push_back({a[i],val});
        }
        int ind1=ind-1;
        int last_defeated=a[ind1];
        while(ind1>=0 && a[ind1]!=last_defeated) {
            ind--;
        }
        if(ind1>=0) {
            m-=sum;
            while(ind1>=0 && ind<n) {
                if(m+a[ind1]>=a[ind]) {
                    v[ind1].second++;
                    v[ind].second--;
                    ind1--;
                    ind++;
                    m=m-a[ind]+a[ind1];
                }
                else {
                    break;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++) {
            if(v[i].second>count) {
                res++;
            }
        }
        cout<<res+1<<endl;
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