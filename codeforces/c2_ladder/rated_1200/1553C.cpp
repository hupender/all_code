#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int get_help(string s1) {
    int n=10;
    int win1=0,win2=0,rem1=n/2,rem2=n/2;
    int res1=n;

    for(int i=0;i<n;i++) {
        if(i%2==0) {
            if(s1[i]=='1') {
                win1++;
            }
            rem1--;
        }
        else {
            if(s1[i]=='1') {
                win2++;
            }
            rem2--;
        }
        if((win1>win2+rem2) || (win2>win1+rem1)) {
            res1=i+1;
            break;
        }
    }
    return res1;
}
void solve() {
    int n=10;
    string s;
    cin>>s;
    string s1,s2;
    s1=s;
    s2=s;
    // if team 1 win
    for(int i=0;i<n;i++) {
        if(i%2==0 && s1[i]=='?') {
            s1[i]='1';
        }
        else if(i%2!=0 && s1[i]=='?') {
            s1[i]='0';
        }
    }
    int res1=get_help(s1);
    

    // if team 2 win
    for(int i=0 ; i < n ; i++) {
        if(s2[i] == '?' ) {
            if(i % 2 == 0) {
                s2[i]='0';
            }
            else {
                s2[i]='1';
            }
        }
    }
    int res2=get_help(s2);
    cout<<min(res1,res2)<<endl;

    
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