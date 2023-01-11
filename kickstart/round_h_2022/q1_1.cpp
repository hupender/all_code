#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve(int t) {
    int n,l;
    cin>>l>>n;
    char prev_dir;
    int prev_dis;
    ll count=0;
    for(int i=0;i<n;i++) {
        int dis;
        char dir;
        cin>>dis>>dir;
        if(i==0) {
            prev_dir=dir;
            count+=dis/l;
            prev_dis=dis%l;
        }
        else {
            if(dir==prev_dir) {
                dis+=prev_dis;
                count+=dis/l;
                prev_dis=dis%l;
            }
            else {
                if(dis>=prev_dis) {
                    prev_dir=dir;
                    dis-=prev_dis;
                    count+=dis/l;
                    prev_dis=dis%l;
                }
                else {
                    prev_dis-=dis;
                }
            }
        }
    }
    cout<<"Case #"<<t<<": "<<count<<endl;
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
    for(int i=1;i<=t;i++) {
        solve(i);
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}