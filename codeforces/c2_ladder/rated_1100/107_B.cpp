#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
bool is_prime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
// get smallst prime number with n number of digits in  it.
int get_prime(int n) {
    int ans=1;
    n--;
    while(n--) {
        ans*=10;
    }
    while(!is_prime(ans)) {
        ans++;
    }
    return ans;
}
void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    int d1=abs(c-a)+1;
    int d2=abs(c-b)+1;
    int z=get_prime(c);
    int p=get_prime(d1);
    int q=get_prime(d2);
    if(d1==d2) {
        q++;
        while(!is_prime(q)) {
            q++;
        }
    }
    int x=p*z;
    int y=q*z;
    cout<<x<<" "<<y<<endl;
    
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