#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count_T=0;
    int flag=1;
    for(int i=0;i<n;i++) {
        if(s[i]=='T') {
            count_T++;
        }
        else {
            count_T--;
            if(count_T<0) {
                flag=0;
                break;
            }
        }
    }
    if(!flag) {
        cout<<"NO"<<endl;
    }
    else {
        count_T=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='T') {
                count_T++;
            }
            else {
                count_T--;
                if(count_T<0) {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) {
            count_T=0;
            for(int i=0;i<n;i++) {
                if(s[i]=='T') {
                    count_T++;
                }
            }
            int count_M=n-count_T;
            if(2*count_M==count_T) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
        else {
            cout<<"NO"<<endl;
        }
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