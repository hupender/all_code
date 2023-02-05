#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int first_zero=-1;
    int count_one;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            first_zero=i;
            break;
        }
    }
    if(first_zero==-1) {
        cout<<n<<endl;
    }
    else {
        count_one=first_zero;
        int last_res=0;
        int res=0;
        for(int i=n-1;i>first_zero;i--) {
            if(s[i]=='1') {
                last_res++;
            }
            else {
                last_res=0;
            }
            res=max(last_res,res);
        }
        cout<<count_one+res<<endl;
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