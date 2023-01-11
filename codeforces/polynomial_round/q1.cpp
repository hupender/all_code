#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    char a[n-1];
    memset(a,'-',sizeof(a));
    int ind;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            ind=i;
            break;
        }  
    }
    if(ind!=0) {
        a[ind-1]='+';
    }
    int flag=1;
    for(int i=ind+1;i<n;i++) {
        if(s[i]=='1' && flag) {
            a[i-1]='-';
            flag=0;
        }
        else if(s[i]=='1' && flag==0) {
            a[i-1]='+';
            flag=1;
        }
    }
    for(int i=0;i<n-1;i++) {
        cout<<a[i];
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