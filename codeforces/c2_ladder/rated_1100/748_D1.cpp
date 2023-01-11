#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> v;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int d=abs(a[i]-a[j]);
            if(d!=0) {
                v.push_back(d);
            }
        }
    }
    if(v.size()==0) {
        cout<<"-1"<<endl;
    }
    else {
        int s=v.size(); 
        int g=v[0];
        for(int i=1;i<s;i++) {
            g=gcd(g,v[i]);
        }
        cout<<g<<endl;
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