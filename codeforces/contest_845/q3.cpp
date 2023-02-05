#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
bool is_prime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> prime;
    for(int i=2;i<m;i++) {
        if(is_prime(i)) {
            prime.push_back(i);
        }
    }
    int size=prime.size();
    vector<vector<int>> v;
    int flag=1;
    for(int i=0;i<size;i++) {
        vector<int> v1;
        for(int j=0;j<n;j++) {
            if(a[j]%prime[i]==0) {
                v1.push_back(a[j]);
            }
        }
        if(v1.size()==0) {
            flag=0;
        }
        v.push_back(v1);
    }
    if(flag) {
        vector<int> num;
        vector<int> v1=v[0];
        for(int i=0;i<)
        for(int i=0;i<size;i++) {
            if(v[i].size()==1) {
                num.push_back(v[i][0]);
            }
            else {

            }
        }
        
    }
    else {
        cout<<"-1"<<endl;
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