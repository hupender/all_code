#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    int time[m];
    for(int i=0;i<m;i++) {
        cin>>time[i];
    }
    int type[m];    // value can be 1 or 2
    for(int i=0;i<m;i++) {
        cin>>type[i];
    }
    int j=0;
    int a=0,b=0,score=0;
    for(int i=1;j<m && i<=n;i++) {
        if(time[j]==i) {
            // there is an event    
            if(type[j]==1) {
                // this time we will increase a 
                a++;
                if(a>b) {
                    score++;
                }
                else {
                    a=0;
                    b=0;
                }
            }
            else {
                // this time we will increase b
                b++;
                if(a<b) {
                    score++;
                }
                else {
                    a=0;
                    b=0;
                }
            }
            j++;
        }
        else {
            // no event
            if(type[j]==1) {
                a++;
            }
            else {
                b++;
            }
        }
    }
    cout<<score<<endl;
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