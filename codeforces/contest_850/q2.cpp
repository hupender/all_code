#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int p=2;
    int bob_black=0;
    int bob=0,alice=1;
    n--;
    int flag=1;
    int n2=n+1;
    int n1=2;
    while(n>0) {
        if(flag) {
            int b=2*p+1;
            int res=0;
            if(n1%2==0) {
                res=1;
            }
            if(n>b) {
                bob+=b;
                res+=p;
                n-=b;
                n1+=b;
            }
            else {
                bob+=n;
                res+=(n-1)/2;
                n=0;
                n1+=n;
            }
            bob_black+=res;
            p+=2;
            flag=0;
        }
        else {
            int a=2*p+1;
            if(n>a) {
                alice+=a;
                n-=a;
                n1+=a;
            }
            else {
                alice+=n;
                n=0;
                n1+=n;
            }
            p+=2;
            flag=1;
        }
    }
    int bob_white=bob-bob_black;
    int alice_white=((n2+1)/2)-bob_white;
    int alice_black=alice-alice_white;
    cout<<alice_white<<" "<<alice_black<<" "<<bob_white<<" "<<bob_black<<endl;
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