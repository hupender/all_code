#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    int sum=0;
    map<int,int> map;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
        map[a[i]]++;
    }
    if(m>=sum) {
        cout<<"1"<<endl;
    }
    else {
        sort(a,a+n);
        int count=0,ind;
        for(int i=0;i<n;i++) {
            if(m>=a[i]) {
                m-=a[i];
                count++;
            }
            else {
                ind=i;
                break;
            }
        }
        vector<pair<int,int>> v;
        for(auto i:map) {
            v.push_back({i.first,i.second});
        }
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        int n1=v.size();
        int sum1=0;
        for(int i=0;i<n1-1;i++) {
            sum1+=v[i].second;
            prefix_sum.push_back(sum1);
        }
        vector<int> wins;
        for(int i=0;i<n1;i++) {
            int size=v[i].second;
            for(int j=0;j<size;j++) {
                wins.push_back(prefix_sum[i]);
            }
        }
        for(int i=ind;i<n;i++) {
            wins[i]++;
        }

        // added
        int k=1;
        for(int i=ind;i<n;i++) {
            if(ind-k>=0 && wins[ind-k]<count && a[i]<=m+a[ind-k]) {
                wins[ind-k]++;
                m=m+a[ind-k]-a[i];
                k++;
                wins[i]-=2;
            }
        }
        // added end
        int res=1;
        for(int i=0;i<n;i++) {
            if(wins[i]>count) {
                res++;
            }
        }
        cout<<res<<endl;
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