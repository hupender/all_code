#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> get_help(vector<int> &v) {
    int min_ind,mi=INT_MAX,max_ind,ma=INT_MIN;
    int n=v.size();
    if(n==1) {
        return v;
    }
    for(int i=0;i<n;i++) {
        if(v[i]>ma) {
            ma=v[i];
            max_ind=i;
        }
        if(v[i]<mi) {
            mi=v[i];
            min_ind=i;
        }
    }
    int m1=min(min_ind,max_ind);
    int m2=max(max_ind,min_ind);
    ll sum=0;
    for(int i=m1;i<=m2;i++) {
        sum+=v[i];
    }
    ll new_value=ma-mi;
    if(new_value*(m2-m1+1)>=sum) {
        for(int i=m1;i<=m2;i++) {
            v[i]=new_value;
        }

        vector<int> v1;
        for(int i=0;i<=m1;i++) {
            v1.push_back(v[i]);
        }
        vector<int> v2;
        for(int i=m2;i<n;i++) {
            v2.push_back(v[i]);
        }
        vector<int> a=get_help(v1);
        vector<int> b=get_help(v2);
        for(int i=0;i<=m1;i++) {
            v[i]=a[i];
        }
        int j=0;
        for(int i=m2;i<n;i++) {
            v[i]=b[j];
            j++;
        }
    }
    return v;
        
}
void solve() {
    int n;
    cin>>n;
    vector<int> v;
    ll sum1=0;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        sum1+=k;
        v.push_back(k);
    }
    vector<int> v1=get_help(v);
    ll sum=0;
    for(int i=0;i<n;i++) {
        sum+=v1[i];
    }
    cout<<max(sum,sum1)<<endl;
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