#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> decimal_to_binary(int n) {
    vector<int> v(32,0);
    int k=31;
    while(n>0) {
        int rem=n%2;
        v[k]=rem;
        n/=2;
        k--;
    }
    return v;
}
void solve() {
    int x;
    cin>>x;
    if(x%2==0) {
        int num1=x+x/2;
        int num2=x/2;
        int xo=num1^num2;
        if(xo==x) {
            cout<<num1<<" "<<num2<<endl;
        }
        else {
            cout<<"-1"<<endl;
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