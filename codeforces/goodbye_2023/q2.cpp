#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int get_hcf(int a ,int b) {
    if(b==0) {
        return a;
    }
    return get_hcf(b,a%b);
}
void solve() {
    int a,b;
    cin>>a>>b;
    int hcf=get_hcf(a,b);
    int lcm=(a*(ll)b)/hcf;
    int ans=lcm;
    if(lcm=b) {
        int i=2;
        while(true) {
            int val1=lcm*i;
            int val2=a*i;
            if(val2==b) {
                ans=lcm*i;
                break;
            }
            else if(val1%val2==0) {
                i++;
            } else {
                break;
                
            }   
        }
    }
    cout<<ans<<endl;
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