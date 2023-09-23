#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int get_work(int days,vector<int> v) {
    int n=v.size();
    int work=0;
    for(int i=0;i<n;i++) {
        work+=days/v[i];
    }
    return work;
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        v.push_back(a*(i+1));
    }
    int low=1,high=1e9;
    int res=-1;
    while(low<high) {
        int mid=(low+high)/2;
        int task_done=get_work(mid,v);
        if(task_done<k) {
            low=mid+1;
        }
        else if(task_done>k) {
            high=mid;
        }
        else {
            res=mid;
            break;
        }
    }
    if(res==-1) {
        res=low;
    }
    while(true) {
        int task_done=get_work(res-1,v);
        if(task_done==k) {
            res--;
        }
        else {
            break;
        }
    }
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