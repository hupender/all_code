#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int k,n;
    cin>>k>>n;
    vector<int> v;
    int curr=1;
    int d=1;
    int flag=1;
    int count=0;
    while(flag) {
        v.push_back(curr);
        count++;
        curr+=d;
        d++;
        if(n-(curr)>=(k-count-1)) {
            flag=1;
        }
        else {
            flag=0;
        }
    }
    if(count<k) {
        d--;
        curr-=d;
        curr++;
        while(count<k) {
            v.push_back(curr);
            curr++;
            count++;
        }
    }

    for(int i=0;i<k;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
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