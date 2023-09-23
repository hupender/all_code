#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
string res;
void helper() {
    int i=1;
    while(res.size()!=20) {
        if(i%3==0) {
            res.push_back('F');
        }
        if(i%5==0) {
            res.push_back('B');
        }
        i++;
    }
}
void solve() {
    int k;
    cin>>k;
    string s;
    cin>>s;
    int flag=0;
    string s1=res;
    int n1=s1.size();
    for(int i=0;i<n1-k;i++) {
        int ind=i;
        int flag1=1;
        for(int j=0;j<k;j++) {
            if(s[j]!=s1[ind]) {
                flag1=0;
            }
            ind++;
        }
        if(flag1) {
            flag=1;
            break;
        }
    }
    if(flag) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
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
    helper();
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}