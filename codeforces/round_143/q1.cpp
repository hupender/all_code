#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int check(string s) {
    int n=s.size();
    int count=0;
    for(int i=0;i<n-1;i++) {
        if(s[i]==s[i+1]) {
            count++;
        }
    }
    return count;
}
void solve() {
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    int a=check(s1);
    int b=check(s2);
    if(a==0 && b==0) {
        cout<<"YES"<<endl;
    }
    else if(a==0 && b==1) {
        if(s1[n-1]==s2[m-1]) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    else if(a==1 && b==0) {
        if(s1[n-1]==s2[m-1]) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
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
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}