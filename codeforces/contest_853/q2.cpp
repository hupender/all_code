#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int st=0,end=n-1;
    while(st<=end && s[st]==s[end]) {
        st++;
        end--;
    }
    if(st<end) {
        while(st<=end && s[st]!=s[end]) {
            st++;
            end--;
        }
        if(st<end) {
            while(st<=end && s[st]==s[end]) {
                st++;
                end--;
            }
            if(st<end) {
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
            }
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    else {
        cout<<"YES"<<endl;
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