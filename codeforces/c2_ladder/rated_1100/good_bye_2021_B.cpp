#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    while(i<n-1) {
        if(s[i]>s[i+1]) {
            i++;
        }
        else {
            break;
        }
    }
    if(s[0]!=s[i]) {
        while(i<n-1) {
            if(s[i]>=s[i+1]) {
                i++;
            }
            else {
                break;
            }
        }
        // char c=s[i];
        // while(s[i]==c) {
            
        //     i++;
        // }
        // i--;
    }
    string s1;
    for(int j=0;j<=i;j++) {
        s1.push_back(s[j]);
    }
    cout<<s1;
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;
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